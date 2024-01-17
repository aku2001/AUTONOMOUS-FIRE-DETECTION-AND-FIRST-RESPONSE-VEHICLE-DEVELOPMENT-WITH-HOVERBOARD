import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener


class NavigationControllerTester(Node):

    def __init__(self):
        super().__init__("navigation_controller_tester")


        # Set subscribers
        self.publisher = self.create_publisher(Pose,"/nav_waypoints",10)


        self.timer = self.create_timer(0.1,self.getWaypoints)


    def getWaypoints(self):

        pose = Pose()
        x = float(input("Enter x coordinate: "))
        y = float(input("Enter y coordinate: "))

        pose.position.x = x
        pose.position.y = y
        self.publisher.publish(pose)
        print("Message Published")
        
        

def main(args=None):
    rclpy.init(args=args)

    navigationControllerTester = NavigationControllerTester()

    rclpy.spin(navigationControllerTester)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    navigationControllerTester.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
