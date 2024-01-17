import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Pose
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener


class NavigationController(Node):

    def __init__(self):
        super().__init__("navigation_controller")

        # Waypoint List
        self.waypoints = []
        self.accuracy = 0.4


        # Set subscribers
        self.subscriber = self.create_subscription(Pose,"/nav_waypoints",self.setWaypoint,10)

        # Set publisher
        self.posePub = self.create_publisher(PoseStamped,"/goal_pose",10)

        # Set tf listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.target_frame = "map"
        self.src_frame = "base_link"

        self.timer = self.create_timer(0.1,self.followWaypoints)

    def setWaypoint(self,msg):
        self.waypoints.append(msg)

    def followWaypoints(self):

        if(len(self.waypoints) > 0):
            pose = PoseStamped()
            pose.pose = self.waypoints[0]
            try:
                t = self.tf_buffer.lookup_transform(
                    self.target_frame,
                    self.src_frame,
                    rclpy.time.Time()
                )
                x_diff = abs(pose.pose.position.x - t.transform.translation.x)
                y_diff = abs(pose.pose.position.y - t.transform.translation.y)
                
                if(x_diff > self.accuracy or y_diff > self.accuracy):
                # If the wanted goal isn't reached publish goal pose
                    print("Going to x: {} and y: {}".format(pose.pose.position.x,pose.pose.position.y))
                    print("Current Pose: x: {}, y: {} ".format(t.transform.translation.x,t.transform.translation.y))
                    self.posePub.publish(pose)
                else:
                    # Else remove the goal pose from the list
                    print("REACHED GOAL POINT")
                    self.waypoints.pop(0)
                                            
            except TransformException as ex:
                self.get_logger().info(
                    f'Could not transform {self.target_frame} to {self.src_frame}: {ex}')



def main(args=None):
    rclpy.init(args=args)

    navigationController = NavigationController()

    rclpy.spin(navigationController)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    navigationController.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
