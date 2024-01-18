import rclpy
from rclpy.node import Node
from nav_msgs.msg import OccupancyGrid
from std_msgs.msg import Int64
from std_msgs.msg import Bool
from geometry_msgs.msg import Pose
from hoverboard_msgs.msg import TempMsg
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
import numpy as np
from slam_toolbox.srv import SaveMap
from PIL import Image



# This program subscribes to temperature /temp_msg 
# Gets the temperature and create a heat map

MAPPING_MODE = 0
LOCALIZATION_MODE = 1

class HeatMapController(Node):
    
    def __init__(self):
        super().__init__('heatmap_creator')
        self.mode = 0
        self.threshold = 5

        # Set Subscribers
        self.temp_subscriber = self.create_subscription(TempMsg,"/temp_msg",self.tempCallback,10)
        self.temp_subscriber
        self.mode_subscriber = self.create_subscription(Int64,"/robot_mode",self.setMode,10)

        # Set tf listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.target_frame = "map"
        self.src_frame = "base_link"

        self.timer = self.create_timer(0.1,self.publishHeatMap)

        # Set publisher
        self.heatmap_publisher = self.create_publisher(OccupancyGrid,"/heat_map", 10)
        self.heat_map = OccupancyGrid()
        self.resolution = 1
        self.origin_x = -15
        self.origin_y = -15
        self.original_map_width = 30
        self.original_map_height = 30
        self.createHeatMap(self.resolution,self.origin_x,self.origin_y,self.original_map_width,self.original_map_height)
        self.saveHeatMapTest()

        self.overheating_publisher = self.create_publisher(Pose,"/overheat_pose",10)

        # Set Service
        self.save_map_srv = self.create_service(SaveMap, 'save_heat_map', self.saveHeatMap)


    def mapValueToColor(self,value):
        if value < 0:
            # Map values from 0 to -128 to gray scale
            normalized_value = int((value + 128) * 200 / 128) + 55
            return (normalized_value, normalized_value, normalized_value)
        elif value <= 20:
            # Dark blue for values 1-20
            return (0, 0, 128 + int(value * 7))
        elif value <= 40:
            # Blue for values 21-40
            return (0, 0, 255 - int((value - 20) * 7))
        elif value <= 60:
            # Pink for values 41-60
            return (255, 192 - int((value - 40) * 7), 203)
        elif value <= 80:
            # Light red for values 61-80
            return (255, 128 + int((value - 60) * 7), 128)
        elif value <= 100:
            # Dark red for values 81-100
            return (255, 0, 0)
        else:
            # Black for values 101 and above
            return (0, 0, 0)


    def saveHeatMap(self,request, response):
        fileName = request.data
        block_size = 20

        width = self.heat_map._info.width 
        height = (len(self.heat_map.data) + width - 1) // width
        img = Image.new("RGB", (width, height), color="white")
        pixels = img.load()

        for i, value in enumerate(self.heat_map.data):
            color = self.mapValueToColor(value)
            for x in range(i * block_size, (i + 1) * block_size):
                for y in range(block_size):
                    pixels[x, y] = color

        img.save(fileName) 

        return response


    def saveHeatMapTest(self):
        fileName = "hello.png"
        block_size = 20

        width = self.heat_map._info.width  * block_size
        height = self.heat_map._info.height * block_size
        img = Image.new("RGB", (width, height), color="white")
        pixels = img.load()

        for i, value in enumerate(self.heat_map.data):
            color = self.mapValueToColor(value)
            for x in range(i * block_size, (i + 1) * block_size):
                for y in range(block_size):
                    pixels[x, y] = color


        img.show()
        img.save(fileName) 



       
    
    def setMode(self,msg):
        # MODE 0 -> MAPPING
        # MODE 1 -> LOCALIZATION
        if(msg.data == 0):
            print("Changing Mode To Mapping")
            self.mode = 0
        elif(msg.data == 1):
            print("Changing Mode To Localization")
            self.mode = 1
    
    def tempCallback(self,msg):
        # Get the pose from the tf with the received timestamp4
        try:
            t = self.tf_buffer.lookup_transform(
                self.target_frame,
                self.src_frame,
                rclpy.time.Time()
                )
                        
            # print("x: {}, y: {}".format(t.transform.translation.x,t.transform.translation.y ))
            if(self.mode == MAPPING_MODE):
                self.updateHeatMap(msg.temp1,t.transform.translation.x,t.transform.translation.y)
            elif(self.mode == LOCALIZATION_MODE):
                self.controlHeatMap(msg.temp1,t.transform.translation.x,t.transform.translation.y)
                
        except TransformException as ex:
            self.get_logger().info(
                f'Could not transform {self.target_frame} to {self.src_frame}: {ex}')
            return
    
    def publishHeatMap(self):
        self.heatmap_publisher.publish(self.heat_map)

    def controlHeatMap(self, temp, x,y,width=None,height=None, wideMode=False):
        # Update the heatmap according to the temperature 
        temp = min(127,temp)

        try:
            map_x, map_y = self.convertCoordinatesToMap(x,y)
            # print("map_x: {}, map_y: {}".format(map_x,map_y))
            
            map_temp = self.heat_map.data[map_x + (map_y*self.heat_map.info.width)]
            if(map_temp == 0):
                # Check if the map has the heat info (if not the value is -1)
                self.updateHeatMap(temp,x,y)
            else:
                # Check if the difference is above the threshold 
                temp_diff = abs(self.heat_map.data[map_x + (map_y*self.heat_map.info.width)] - temp)
                
                if(temp_diff > self.threshold):
                    # OVERHEATING DETECTED 
                    pose = Pose()
                    pose.position.x = x
                    pose.position.y = y
                    self.overheating_publisher.publish(pose)
                
        except Exception as e:
            print("Exception Received: ",e)


    def updateHeatMap(self, temp, x,y,width=None,height=None, wideMode=False):
        # Update the heatmap according to the temperature 
        temp = min(127,temp)

        try:
            map_x, map_y = self.convertCoordinatesToMap(x,y)
            print("map_x: {}, map_y: {} temp: {}".format(map_x,map_y,temp))
            self.heat_map.data[map_x + (map_y*self.heat_map.info.width)] = temp
        except Exception as e:
            print("Exception Received: ",e)


        if(wideMode):
            resolution = self.heat_map.info.resolution
            x_range = width/resolution
            y_range = height/resolution

            # Set the temperature for the plus width of the robot
            for i in range(x_range//2):
                
                # Set the temperature for the plus height of the robot
                for j in range(y_range//2):
                    self.heat_map.data[(map_x+i) + ((map_y+j)*self.heat_map.info.width)] = temp
                
                # Set the temperature for the minus height of the robot
                for j in range(y_range//2):
                    self.heat_map.data[(map_x+i) + ((map_y-j)*self.heat_map.info.width)] = temp

            # Set the temperature for the minus width of the robot
            for i in range(x_range//2):

                # Set the temperature for the plus height of the robot
                for j in range(y_range//2):
                    self.heat_map.data[(map_x-i) + ((map_y+j)*self.heat_map.info.width)] = temp
                
                # Set the temperature for the minus height of the robot
                for j in range(y_range//2):
                    self.heat_map.data[(map_x-i) + ((map_y-j)*self.heat_map.info.width)] = temp
        
        

    def convertCoordinatesToMap(self,x,y):
        # Convert the real life coordintes into map coordinates
        origin_x = self.heat_map.info.origin.position.x
        origin_y = self.heat_map.info.origin.position.y
        resolution = self.heat_map.info.resolution

        map_x = round((x-origin_x) / resolution )
        map_y = round((y-origin_y) / resolution )

        return map_x,map_y
        

    def createHeatMap(self,resolution, origin_x,origin_y, width,height):
        
        # Set The Origin
        origin = Pose()
        origin.position.x = float(origin_x)
        origin.position.y = float(origin_y)
        self.heat_map.info.origin = origin
        self.heat_map.header.frame_id = self.target_frame

        # Set the map width and height
        map_width =  int(width /resolution)
        map_height = int(height /resolution)
        self.heat_map.info.height = map_height
        self.heat_map.info.width = map_width
        self.heat_map.info.resolution = float(resolution)

        # Set the map in array
        self.heat_map.data = [0] * (map_width * map_height)
        # self.heat_map.data[0] = 100
        self.updateHeatMap(100,-15,-10)
        self.updateHeatMap(100,10,-15)
        self.updateHeatMap(100,-15,10)









def main(args=None):
    rclpy.init(args=args)

    heatMapController = HeatMapController()

    rclpy.spin(heatMapController)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    heatMapController.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
