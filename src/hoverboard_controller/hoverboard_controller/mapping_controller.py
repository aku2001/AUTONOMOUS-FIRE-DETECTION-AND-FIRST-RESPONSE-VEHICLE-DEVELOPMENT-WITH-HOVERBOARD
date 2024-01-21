# This method is written to control the mapping algorithms

import sys

from example_interfaces.srv import AddTwoInts
from slam_toolbox.srv import SerializePoseGraph,SaveMap
from std_msgs.msg import String, Empty
import rclpy
from rclpy.node import Node
from slam_toolbox.srv import SaveMap
import subprocess
import threading
import signal
import time
import psutil
import os

from geometry_msgs.msg import PoseWithCovarianceStamped


SLAM = 0
LOCALIZATION = 1

class MappingController(Node):

    def __init__(self):
        super().__init__('map_controller')
        
        # Create Services: Launch Slam, Launch Localization, Reset
        self.launch_slam_sub = self.create_subscription(Empty, '/hoverboard_controller/launch_slam', self.launchSlam,10)
        self.launch_localization_sub = self.create_subscription(String, '/hoverboard_controller/launch_localization', self.launchLocalization,10)
        self.reset_slam_sub = self.create_subscription(Empty, '/hoverboard_controller/reset_slam', self.resetSlam,10)

        self.declare_parameter("map","/home/qty/ros2_ws/frontend/maps/Map3/map.yaml")
        
        # publisher
        self.init_pose_publisher = self.create_publisher(PoseWithCovarianceStamped,"/initialpose",10)

        self.place_holder = "{MAP_FILE_NAME}"
        self.localization_config_path = "/home/qty/ros2_ws/src/hoverboard_controller/launch/localization.launch_tmp.py"
        self.localization_config_path_updated = "/home/qty/ros2_ws/src/hoverboard_controller/launch/localization.launch.py"
        self.process = None
        self.mode = None
        self.launchSlam(None)



    def updateFileNameLocalization(self,fileName):
        print("Updating Name")
        try:
            # Read the content of the file
            print("Reading")
            with open(self.localization_config_path, "r") as file:
                content = file.read()
                file.close()

            # Replace the placeholder text
            updated_content = content.replace(self.place_holder, fileName)

            # Write the updated content back to the file
            print("Writing")

            with open(self.localization_config_path_updated, "w") as file:
                file.write(updated_content)
                file.close()
            
            return True
        except Exception as e:
            print(e)
            return False
        
    def runSlamCommand(self):
        print("Launching Slam")
        # command = "ros2 launch slam_toolbox online_async_launch.py"
        command = "ros2 launch slam_gmapping slam_gmapping.launch.py"
        self.process = subprocess.Popen(command,shell=True,preexec_fn=os.setsid)
        print("subprocess with the pid: {} is created".format(self.process.pid))
    
    def runLocalizationCommand(self):
        # Change the file name from the launch file
        print("Launching Localization")
        command = "ros2 launch {}".format(self.localization_config_path_updated)
        self.process = subprocess.Popen(command,shell=True,preexec_fn=os.setsid)


    def launchSlam(self,msg):
        print("Launching Slam")
        if(self.mode == SLAM):
            if(self.process != None):
                print("Killing Process")
                os.killpg(os.getpgid(self.process.pid), signal.SIGINT)
                time.sleep(0.1)
                os.killpg(os.getpgid(self.process.pid), signal.SIGKILL)
        
        self.mode = SLAM
        if(self.process != None):
            os.killpg(os.getpgid(self.process.pid), signal.SIGKILL)

        
        self.runSlamCommand()

        print("Finished")
        

    def resetSlam(self, msg):
        print("Relaunching Slam")
        if(self.mode == SLAM):
            
            if(self.process != None):
                print("Killing Process")
                os.killpg(os.getpgid(self.process.pid), signal.SIGINT)
                time.sleep(0.1)
                os.killpg(os.getpgid(self.process.pid), signal.SIGKILL)
                time.sleep(0.5)

            print("Launching Slam") 
            self.runSlamCommand()

        print("Finished")

    def launchLocalization(self,msg):
        fileName = msg.data
        print("Launhcing Localization with: ",fileName)
        ret = self.updateFileNameLocalization(fileName)

        self.mode = LOCALIZATION
        
        if(self.process != None):
            print("Killing Process")
            os.killpg(os.getpgid(self.process.pid), signal.SIGINT)
            time.sleep(0.1)
            os.killpg(os.getpgid(self.process.pid), signal.SIGKILL)

        if(ret):
            self.runLocalizationCommand()
            time.sleep(3)
            msg = PoseWithCovarianceStamped()
            msg.header.frame_id = "map"
            msg.pose.pose.position.x = 0
            msg.pose.pose.position.y = 0
            self.init_pose_publisher.publish(msg)
        else:
            print("Updating File Failed")
        print("Finished")

    def __del__(self):
        print("Destructor")
        if(self.process != None):
            print("Killing Process")
            # Terminate the process group to include all subprocesses
            os.killpg(os.getpgid(self.process.pid), signal.SIGKILL)
    

def main(args=None):
    rclpy.init(args=args)
    mappingController = MappingController()
    # mappingController.runSlamCommand()
    rclpy.spin(mappingController)
    mappingController.destroy_node()
    rclpy.shutdown()

  
if __name__ == '__main__':
  main()


    