from setuptools import setup
import os
import glob

package_name = 'hoverboard_controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']), 
        ('share/' + package_name, ['launch/hoverboard_joystick_control.launch.py']),       
        ('share/' + package_name, ['launch/rsp.launch.py']),  
        ('share/' + package_name, ['launch/mapper.launch.py']),       
        ('share/' + package_name, ['launch/localization.launch.py']),       
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='qty',
    maintainer_email='qty@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'hoverboard_controller = hoverboard_controller.hoverboard_controller:main',
            'joystick_controller = hoverboard_controller.joystick_controller:main',
            'heat_map_tester = hoverboard_controller.heat_map_tester:main',
            'heat_map_controller = hoverboard_controller.heat_map_controller:main',
            'navigation_controller = hoverboard_controller.navigation_controller:main',
            'navigation_controller_tester = hoverboard_controller.navigation_controller_tester:main',
            'map_saver = hoverboard_controller.map_saver:main',
            'mapping_controller = hoverboard_controller.mapping_controller:main',
            'fire_detector = hoverboard_controller.fire_detector:main',
        ],
    },
)
