import rclpy
from rclpy.node import Node
from nav_msgs.msg import OccupancyGrid
from std_msgs.msg import Int64, String
from geometry_msgs.msg import Pose
from hoverboard_msgs.msg import TempMsg
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
import numpy as np
from PIL import Image
import yaml
import time


# This program subscribes to temperature /temp_msg 
# Gets the temperature and create a heat map

MAPPING_MODE = 0
LOCALIZATION_MODE = 1

class MapSaver(Node):
    
    def __init__(self):
        super().__init__('map_saver')
        self.mode = 0
        self.threshold = 5

        # Set Subscribers
        self.map_subscriber = self.create_subscription(OccupancyGrid,"/map",self.mapCallback,10)
        self.heatmap_subscriber = self.create_subscription(OccupancyGrid,"/heatmap",self.heatMapCallback,10)

        self.map = None
        self.heatmap = None

        # Set Subsciribers
        self.save_map_sub = self.create_subscription(String, '/hoverboard_controller/save_map', self.saveMap,10)
        self.save_heatmap_sub = self.create_subscription(String, '/hoverboard_controller/save_heatmap', self.saveHeatMap,10)
        self.save_heatmap_normal_sub = self.create_subscription(String, '/hoverboard_controller/save_map_normal', self.saveMapNormal,10)
        
        self.occupied_threshold = 65
        self.free_threshold = 25

    def mapCallback(self,msg):
        print("Getting Map")
        self.map = msg
    
    def heatMapCallback(self,msg):
        print("Getting HeatMap")
        self.heatmap = msg

    def mapValueToColor(self,value):
        if value <= 0:
            # Map values from 0 to -128 to gray scale
            return (200, 200, 200)
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



    def saveHeatMap(self,msg):
        try:
            if(self.heatmap == None):
                print("No Heat Map To Save")
                return
            
            print("Saving Heat Map")
            fileName = msg.data + ".png"

            # Calculate the actual width and height of the image in pixels
            width = self.heatmap.info.width
            height = self.heatmap.info.height
            element_size = 20
            image_width = width * element_size
            image_height = height * element_size

            # Create a new image with RGB mode
            img = Image.new("RGB", (image_width, image_height))

            # Iterate through the pixel list and set pixels in the image
            for y in range(height):
                for x in range(width):
                    # Get the value of the current element
                    element_value = self.mapValueToColor(self.heatmap.data[y * width + x])

                    # Calculate the position in the image
                    start_x = x * element_size
                    start_y = y * element_size

                    # Set pixels based on the element value
                    for i in range(element_size):
                        for j in range(element_size):
                            # Calculate the pixel position in the image
                            pixel_x = start_x + i
                            pixel_y = start_y + j

                            # Set the RGB values of the pixel based on the element value
                            img.putpixel((pixel_x, pixel_y), element_value)

            # img.show()
            img.save(fileName) 
            time.sleep(0.05)
        except Exception as e:
            print("In heat map error")
            print(e)


    def saveMapNormal(self,msg):
        try:
            print("Save Map Normal")
            if(self.heatmap == None):
                print("No Normal Heat Map To Save")
                return 

            print("Saving Map Normal")

            
            fileName = msg.data + ".png"
            yamlFileName = msg.data + ".yaml"

            # Calculate the actual width and height of the image in pixels
            width = self.heatmap.info.width
            height = self.heatmap.info.height
            element_size = 1
            image_width = width * element_size
            image_height = height * element_size

            # Create a new image with RGB mode
            img = Image.new("RGB", (image_width, image_height))
            # print(self.map.data)

            # Iterate through the pixel list and set pixels in the image
            for y in range(height):
                for x in range(width):
                    color = self.heatmap.data[y * width + x]
                    element_value = (color,color,color)

                    # Calculate the position in the image
                    start_x = x * element_size
                    start_y = y * element_size

                    # Set pixels based on the element value
                    for i in range(element_size):
                        for j in range(element_size):
                            # Calculate the pixel position in the image
                            pixel_x = start_x + i
                            pixel_y = start_y + j

                            # Set the RGB values of the pixel based on the element value
                            img.putpixel((pixel_x, pixel_y), element_value)

            # img.show()
            img.save(fileName) 

            # Create the yaml file
            data = {
                'image': fileName,
                'mode': 'trinary',
                'resolution': self.heatmap.info.resolution,
                'origin': [self.heatmap.info.origin.position.x,self.heatmap.info.origin.position.y,0],
                'negate': 0,
                'occupied_thresh': 0.65,
                'free_thresh': 0.25
            }
            with open(yamlFileName, 'w') as yaml_file:
                yaml.dump(data, yaml_file, default_flow_style=True)

            time.sleep(0.05)
        
        except Exception as e:
            print(e)
    

    def saveMap(self,msg):
        try:
            if(self.map == None):
                print("No Map To Save")
                return 

            print("Saving Map")

            
            fileName = msg.data + ".png"
            yamlFileName = msg.data + ".yaml"

            # Calculate the actual width and height of the image in pixels
            width = self.map.info.width
            height = self.map.info.height
            element_size = 1
            image_width = width * element_size
            image_height = height * element_size

            # Create a new image with RGB mode
            img = Image.new("RGB", (image_width, image_height))
            # print(self.map.data)

            # Iterate through the pixel list and set pixels in the image
            for y in range(height):
                for x in range(width):
                    # Get the value of the current element
                    if(self.map.data[y * width + x] < 0):
                        # Below zero is gray
                        color = 110
                    elif(self.map.data[y * width + x] < self.free_threshold):
                        # 0 - 25 is white
                        color = 255
                    elif(self.map.data[y * width + x] > self.occupied_threshold):
                        # 65-above is black
                        color = 0
                    else:
                        # 25-65 is gray
                        color = 110


                    element_value = (color,color,color)

                    # Calculate the position in the image
                    start_x = x * element_size
                    start_y = y * element_size

                    # Set pixels based on the element value
                    for i in range(element_size):
                        for j in range(element_size):
                            # Calculate the pixel position in the image
                            pixel_x = start_x + i
                            pixel_y = start_y + j

                            # Set the RGB values of the pixel based on the element value
                            img.putpixel((pixel_x, pixel_y), element_value)

            # img.show()
            img.save(fileName) 

            # Create the yaml file
            
            data = {
                'image': fileName,
                'mode': 'trinary',
                'resolution': self.map.info.resolution,
                'origin': [self.map.info.origin.position.x,self.map.info.origin.position.y,0],
                'negate': 0,
                'occupied_thresh': 0.65,
                'free_thresh': 0.25
            }
            with open(yamlFileName, 'w') as yaml_file:
                yaml.dump(data, yaml_file, default_flow_style=True)

            time.sleep(0.05)
        
        except Exception as e:
            print(e)
        
    
  


def main(args=None):
    rclpy.init(args=args)

    mapSaver = MapSaver()

    rclpy.spin(mapSaver)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    mapSaver.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
