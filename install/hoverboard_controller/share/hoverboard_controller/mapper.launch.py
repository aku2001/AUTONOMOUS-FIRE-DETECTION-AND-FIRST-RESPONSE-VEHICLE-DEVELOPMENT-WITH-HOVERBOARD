from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ros2_laser_scan_matcher',
            namespace = 'laser_scan_matcher1',
            name='laser_scan_matcher',
            executable='laser_scan_matcher',
            output='screen',
            parameters=[{
                'max_iterations': 100,
            }],
        ),

        # Node(
        #     package='hoverboard_controller',
        #     namespace = 'hoverboard_controller',
        #     name='heat_map_controller',
        #     executable='heat_map_controller',
        #     output='screen',
        # ),
        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([os.path.join(
                get_package_share_directory("slam_toolbox"),'launch','online_async_launch.py'
            )])
        ),

    ])
