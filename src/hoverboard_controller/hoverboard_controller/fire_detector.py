import cv2         # Library for openCV
import smtplib     # Library for email sending
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int64
import time
from sensor_msgs.msg import Image
from ament_index_python.packages import get_package_share_directory
import numpy as np



class FireDetector(Node):

    def __init__(self):
        super().__init__('fire_detector')

        # Set Subscriber 
        self.subscription = self.create_subscription(Int64, '/fire_msg', self.fireDetectionCallback, 10)
        self.subscription  # prevent unused variable warning

        # Set image publisher
        self.imagePublisher = self.create_publisher(Image, "/fire_detection_image",10)

        self.fireDetected = False
        self.fire_cascade = cv2.CascadeClassifier('fire_detection_cascade_model.xml')
        # 4 FOR THE CAM
        self.cam = cv2.VideoCapture(0)

        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.startImageProcessing)


    def fireDetectionCallback(self,msg):
        if(msg.data < 1000):
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
                    roi_gray = gray[y:y + h, x:x + w]
                    roi_color = frame[y:y + h, x:x + w]

                    print("Fire alarm initiated")

        
        # Pubish Image
        msg = Image()
        msg.header.stamp = Node.get_clock(self).now().to_msg()
        msg.header.frame_id = 'ANI717'
        msg.height = np.shape(frame)[0]
        msg.width = np.shape(frame)[1]
        msg.encoding = "bgr8"
        msg.is_bigendian = False
        msg.step = np.shape(frame)[2] * np.shape(frame)[1]
        msg.data = np.array(frame).tobytes()

        # publishes message
        self.imagePublisher.publish(msg)
        

        # cv2.imshow('frame', frame)
        # cv2.waitKey(10)
        



    # Defined function to send mail post fire detection using threading
    def send_mail_function(): 
        
        recipientmail = "add recipients mail" # recipients mail
        recipientmail = recipientmail.lower() # To lower case mail
        
        try:
            server = smtplib.SMTP('smtp.gmail.com', 587)
            server.ehlo()
            server.starttls()
            # Senders mail ID and password
            server.login("add senders mail", 'add senders password') 
            # recipients mail with mail message
            server.sendmail('add recipients mail', recipientmail, "Warning fire accident has been reported") 
            # to print in consol to whome mail is sent
            print("Alert mail sent sucesfully to {}".format(recipientmail))
            server.close() ## To close server
            
        except Exception as e:
            print(e) # To print error if any
		

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