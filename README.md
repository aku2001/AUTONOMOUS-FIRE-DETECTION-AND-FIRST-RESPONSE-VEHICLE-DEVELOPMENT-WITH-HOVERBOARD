# AUTONOMOUS FIRE DETECTION AND FIRST RESPONSE VEHICLE DEVELOPMENT WITH HOVERBOARD

The project focuses on detecting fire with image processing, creating a occupancy grid
map and heat map of the area and navigating inside the area with temperature, sonar
and lidar sensors. SLAM algorithm is used, which enables robot to create a map of
an unknown environment and help robot to find its locations in that environment
that is mapped. The heat map is used to detect any temperature anomaly that might
result in fire or damage. For detecting fire from camera, opencv library and infrared
sensor is used. The task of fire detection and mapping is successfully handled by SLAM
algorithm, Heat map algorithm and Fire detection algorithm.
The robot produced accurate maps in a closed area unless something shorter than the
robot is on the same area. The problem with this is caused by the height of the lidar
that is placed on the top of robot. To avoid this problem, everything shorter than the
robot is excluded from the mapping area. This contributes to enhancing the overall
accuracy and precision of the maps.

Please read the article for more information.

# How To Run

Before running the application, HoverboardController.ino should be uploaded to the Arduino and the motherboard of the hoverboard should be updated according to : https://github.com/EFeru/hoverboard-firmware-hack-FOC.

* Install ROS 2 Desktop version.
* Install the laser scan matcher and slam gmapping packages from ROS 2.
* Clone the repository from GitHub and compile it using colcon build.
* After compilation, source the setup.bash file.
* Launch hoverboard_joystick_control.launch using ros launch.
* Then, launch mapper.launch using ros2 launch.
* After all systems are running, execute app.py for the web interface.


# Dependencies

* ROS2 Foxy
* Python 3
