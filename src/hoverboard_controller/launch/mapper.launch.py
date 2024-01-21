from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch import LaunchDescription
import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node


def generate_launch_description():
    

    map_saver = Node(   
        package="hoverboard_controller",
        executable="map_saver"
    )

    fire_detector = Node(   
        package="hoverboard_controller",
        executable="fire_detector"
    )

    heat_map_controller = Node(   
        package="hoverboard_controller",
        executable="heat_map_controller"
    )

    mapping_controller = Node(   
        package="hoverboard_controller",
        executable="mapping_controller"
    )

    

    laser_scan_matcher =Node(
            package='ros2_laser_scan_matcher',
            namespace = 'laser_scan_matcher1',
            name='laser_scan_matcher',
            executable='laser_scan_matcher',
            output='screen',
            parameters=[{
                'max_iterations': 100,
            }],
        )



    return LaunchDescription([
        # fire_detector,
        laser_scan_matcher,
        map_saver,
        heat_map_controller,
        # mapping_controller,
    ])



