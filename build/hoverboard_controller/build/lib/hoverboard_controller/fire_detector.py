import cv2         # Library for openCV
import smtplib     # Library for email sending
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int64
import time
from sensor_msgs.msg import Image
from ament_index_python.packages import get_package_share_directory
import numpy as np
from geometry_msgs.msg import Pose
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener



class FireDetector(Node):

    def __init__(self):
        super().__init__('fire_detector')

        # Set Subscriber 
        self.subscription = self.create_subscription(Int64, '/fire_msg', self.fireDetectionCallback, 10)
        self.subscription  # prevent unused variable warning

        # Set image publisher
        self.imagePublisher = self.create_publisher(Image, "/fire_detection_image",10)
        self.firePosePublisher = self.create_publisher(Pose, "/overheat_pose",10)

        # Set tf listener
        self.pose = Pose()
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.target_frame = "map"
        self.src_frame = "base_link"

        self.fireDetected = False
        self.fire_cascade = cv2.CascadeClassifier('/home/qty/ros2_ws/src/hoverboard_controller/hoverboard_controller/fire_detection_cascade_model.xml')

        # 4 FOR THE CAM
        self.cam = cv2.VideoCapture(4)
        self.imgMsg = Image()


        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.startImageProcessing)
        # self.save_image_path = "/home/qty/ros2_ws/frontend/static/cam.png"


    def fireDetectionCallback(self,msg):
        if(msg.data < 900):
            self.fireDetected = True
            print("Fire Detected")
        else:
            self.fireDetected = False
    
    def startImageProcessing(self):
        # Value in ret is True # To read video frame
        ret, frame = self.cam.read() 
        original_height, original_width = frame.shape[:2]

        # To convert frame into gray color
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) 
        # to provide frame resolution
        fire = self.fire_cascade.detectMultiScale(frame, 1.2, 5) 

        ## to highlight fire with square 
        if self.fireDetected:
            print("Here")
            for (x, y, w, h) in fire:
                # Calculate the center coordinates of the detected fire region
                center_y = y + h // 2

                # Specify the middle region boundaries
                middle_region_y = frame.shape[0] // 3  # Assuming the middle third of the height

                # Check if the center coordinates are within the middle region
                if (center_y > middle_region_y and center_y < 2 * middle_region_y):
                    # Draw rectangle only if the fire region is in the middle
                    cv2.rectangle(frame, (x - 20, y - 20), (x + w + 20, y + h + 20), (255, 0, 0), 2)
                    
                    # Your other code for processing the fire region can go here
                    # roi_gray = gray[y:y + h, x:x + w]
                    # roi_color = frame[y:y + h, x:x + w]

                    print("Fire alarm initiated")

                    # Get the fire pose and publish
                    try:
                        t = self.tf_buffer.lookup_transform(
                            self.target_frame,
                            self.src_frame,
                            rclpy.time.Time()
                        )
                        self.pose.position.x = t.transform.translation.x
                        self.pose.position.y = t.transform.translation.y
                        
                    except TransformException as ex:
                        self.get_logger().info(
                            f'Could not transform {self.target_frame} to {self.src_frame}: {ex}')
                    
                    self.firePosePublisher.publish(self.pose)

        
        # Pubish Image
        self.imgMsg.header.stamp = Node.get_clock(self).now().to_msg()
        self.imgMsg.header.frame_id = 'ANI717'
        self.imgMsg.height = np.shape(frame)[0]
        self.imgMsg.width = np.shape(frame)[1]
        self.imgMsg.encoding = "bgr8"
        self.imgMsg.is_bigendian = False
        self.imgMsg.step = np.shape(frame)[2] * np.shape(frame)[1]
        self.imgMsg.data = np.array(frame).tobytes()

        # publishes message
        self.imagePublisher.publish(self.imgMsg)
        

        # cv2.imshow('frame', frame)
        # cv2.waitKey(10)
        # cv2.imwrite(self.save_image_path,frame)
     
		

def main(args=None):
    rclpy.init(args=args)

    fireDetector = FireDetector()
    fireDetector.startImageProcessing()
    rclpy.spin(fireDetector)


    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    fireDetector.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()