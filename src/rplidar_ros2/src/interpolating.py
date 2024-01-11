import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan




class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            LaserScan,
            '/scan',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.publisher_ = self.create_publisher(LaserScan, '/scan2', 10)

        self.expected_readings = 239

    def listener_callback(self, msg):

        print(len(msg.ranges))

        original_readings = np.array(msg.ranges,dtype=float)
        interpolated_readings = np.interp(np.linspace(0, 1, self.expected_readings ), np.linspace(0, 1, len(original_readings)), original_readings)
        
        msg.ranges = interpolated_readings.astype(float).tolist()            



# Now 'interpolated_readings' contains 323 laser scan readings



def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()
    

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()