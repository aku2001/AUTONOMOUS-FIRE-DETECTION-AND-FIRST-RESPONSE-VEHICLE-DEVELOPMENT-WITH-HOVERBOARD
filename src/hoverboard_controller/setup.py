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
            'joystick_controller = hoverboard_controller.joystick_controller:main'
        ],
    },
)
