import sys

from example_interfaces.srv import AddTwoInts
from slam_toolbox.srv import SerializePoseGraph,SaveMap
from std_msgs.msg import String
import rclpy
from rclpy.node import Node


class MapSaverTester(Node):

    def __init__(self):
        super().__init__('map_saver_tester_async')
        # self.cli2 = self.create_client(SaveMap, '/slam_toolbox/save_map')
        self.cli2 = self.create_client(SaveMap, '/hoverboard_controller/save_map')

        while not self.cli2.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')


        self.req2 = SaveMap.Request()
        self.serialize_map_file_name = "/home/qty/Desktop/whatsup"
        self.map_file_name = "/home/qty/Desktop/map"



    def save_serialized_map(self):
        self.req.filename = self.serialize_map_file_name
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

    def save_normal_map(self):
        name = String()
        name.data = self.map_file_name
        self.req2.name = name
        self.future = self.cli2.call_async(self.req2)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()





def main(args=None):
    rclpy.init(args=args)

    map_saver_tester = MapSaverTester()
    # response = map_saver_tester.save_serialized_map()
    response = map_saver_tester.save_normal_map()
    map_saver_tester.get_logger().info("Request Sent")

    map_saver_tester.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()