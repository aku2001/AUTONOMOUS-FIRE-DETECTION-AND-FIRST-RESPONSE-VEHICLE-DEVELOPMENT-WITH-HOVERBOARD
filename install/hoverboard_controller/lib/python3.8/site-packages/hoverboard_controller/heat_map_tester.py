# Publishes heat msg for trial

import rclpy
from rclpy.node import Node
from hoverboard_msgs.msg import TempMsg
from builtin_interfaces.msg import Time 
import time

class TempPublisher(Node):
    def __init__(self):
        super().__init__('temp_publisher')
        self.tempMsg = TempMsg()
        self.tempMsg.temp1 = 100
        self.tempMsg.temp2 = 20

        self.publisher = self.create_publisher(TempMsg,"/temp_msg",10)

        self.period = 0.1
        self.timer = self.create_timer(self.period, self.publishData)

    def publishData(self):
        self.tempMsg.stamp = self.get_clock().now().to_msg()
        print("publishing: ",self.tempMsg)
        self.publisher.publish(self.tempMsg)
    

def main(args=None):
    rclpy.init(args=args)
    tempPublisher = TempPublisher()
    rclpy.spin(tempPublisher)
    tempPublisher.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
        
