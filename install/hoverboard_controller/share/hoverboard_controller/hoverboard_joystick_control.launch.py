from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch import LaunchDescription
import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node


def generate_launch_description():
    
    # HOVERBOARD CONTROLLER NODE
    hoverboard_controller_node = Node(
        package="hoverboard_controller",
        executable="hoverboard_controller",
        parameters=[{
            'serial_port' : '/dev/ttyUSB1'
        }]
    )

    # JOYSTICK NODE
    joystick_node = Node(   
        package="hoverboard_controller",
        executable="joystick_controller"
    )


    rplidar = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory("rplidar_ros"),'launch','rplidar.launch.py'
                )]), launch_arguments={'serial_port': '/dev/ttyUSB0'}.items()
    )

    rsp = IncludeLaunchDescription(
            PythonLaunchDescriptionSource([os.path.join(
                get_package_share_directory("articubot_one"),'launch','rsp.launch.py'
            )]), launch_arguments={'use_sim_time': 'false', 'use_ros2_control': 'true'}.items()
    )  



    return LaunchDescription([
        rsp,
        rplidar,
        hoverboard_controller_node,
        joystick_node
    ])
