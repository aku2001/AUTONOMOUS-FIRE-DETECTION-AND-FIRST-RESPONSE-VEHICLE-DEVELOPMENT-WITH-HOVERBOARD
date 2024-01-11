from launch import LaunchDescription
from launch_ros.actions import Node
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression

def generate_launch_description():

    serial_port = LaunchConfiguration('serial_port')

    serial_port_launch_arg = DeclareLaunchArgument(
        'serial_port',
        default_value='/dev/ttyUSB1'
    )

    rplidar_node = Node(
        node_name='rplidar_composition',
        package='rplidar_ros',
        node_executable='rplidar_composition',
        output='screen',
        parameters=[{
            'serial_port': serial_port,
            'serial_baudrate': 115200,  # A1 / A2
            # 'serial_baudrate': 256000, # A3
            'frame_id': 'laser_frame',
            'inverted': False,
            'angle_compensate': True,
            'scan_mode': 'Boost',
        }],
    )


    return LaunchDescription([
        serial_port_launch_arg,
        rplidar_node
    ])
