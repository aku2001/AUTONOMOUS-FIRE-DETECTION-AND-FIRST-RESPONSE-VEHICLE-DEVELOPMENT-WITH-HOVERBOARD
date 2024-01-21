import sys

from example_interfaces.srv import AddTwoInts
from slam_toolbox.srv import SerializePoseGraph,SaveMap
from std_msgs.msg import String
from std_srvs.srv import Empty
import rclpy
from rclpy.node import Node


class MappingControllerTester(Node):

    def __init__(self):
        super().__init__('map_saver_tester_async')
        self.slam_cli = self.create_client(Empty, '/hoverboard_controller/launch_slam')
        self.slam_reset_cli = self.create_client(Empty , '/hoverboard_controller/reset_slam')
        self.local_cli = self.create_client(SaveMap, '/hoverboard_controller/launch_localization')

        while not self.slam_cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')

        while not self.slam_reset_cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')

        while not self.local_cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')

        self.req = SaveMap.Request()
        self.empty = Empty.Request()
        self.serialize_map_file_name = "/home/qty/ros2_ws/ser_map"
        self.map_file_name = "/home/qty/map"



    def launch_localization(self):
        self.req.name.data = self.serialize_map_file_name
        self.future = self.local_cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

    def launch_slam(self):
        self.future = self.slam_cli.call_async(self.empty)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()
    
    def relaunch_slam(self):
        self.future = self.slam_reset_cli.call_async(self.empty)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()






def main(args=None):
    rclpy.init(args=args)

    map_saver_tester = MappingControllerTester()
    # response = map_saver_tester.save_serialized_map()
    # response = map_saver_tester.launch_slam()
    # response = map_saver_tester.relaunch_slam()
    response = map_saver_tester.launch_localization()
    map_saver_tester.get_logger().info("Request Sent")

    map_saver_tester.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()