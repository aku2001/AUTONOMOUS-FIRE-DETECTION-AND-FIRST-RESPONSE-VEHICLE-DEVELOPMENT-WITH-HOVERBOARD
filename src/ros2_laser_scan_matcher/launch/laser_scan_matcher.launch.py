from launch import LaunchDescription
from launch_ros.actions import Node


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
    ])
