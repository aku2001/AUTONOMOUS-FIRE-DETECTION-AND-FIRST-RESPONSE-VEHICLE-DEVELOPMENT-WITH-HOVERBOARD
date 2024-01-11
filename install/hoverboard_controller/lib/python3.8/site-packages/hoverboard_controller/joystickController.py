import pygame
import time
import serial
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist

# About Joystick Input
buttons = {'x':0,'o':0,'t':0,'s':0,
           'L1':0,'R1':0,'L2':0,'R2':0,
           'share':0,'options':0,
           'axis1':0.,'axis2':0.,'axis3':0.,'axis4':0.}
axiss=[0.,0.,0.,0.,0.,0.]

CONNECTION_HEARTBEAT = 5


class JoystickController(Node):

    def __init__(self):
        super().__init__('joystick_controller')
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.cmdMsg = Twist()
        
        # Set the frequency of the cmd_vel msg
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.publishCmdVel)
        
        # Max speed for the cmd_vel
        self.maxSpeed = 5
        self.maxSpeedPercantage = 0.25 
        self.connection = False



    def checkConnection(self):
        pygame.joystick.quit()
        pygame.joystick.init()
        joystick_count = pygame.joystick.get_count()
        if(joystick_count > 0):
            self.controller = pygame.joystick.Joystick(0)
            self.controller.init()
            return True
        else:
            return False

    def getJoystickData(self):
 
        # retrieve any events ...
        for event in pygame.event.get():                                # Analog Sticks
            if event.type == pygame.JOYAXISMOTION:
                axiss[event.axis] = round(event.value,2)
            elif event.type == pygame.JOYBUTTONDOWN:                    # When button pressed
                #print(event.dict, event.joy, event.button, 'PRESSED')
                for x,(key,val) in enumerate(buttons.items()):
                    if x<10:
                        if self.controller.get_button(x):buttons[key]=1
            elif event.type == pygame.JOYBUTTONUP:                      # When button released
                #print(event.dict, event.joy, event.button, 'released')
                for x,(key,val) in enumerate(buttons.items()):
                    if x<10:
                        if event.button ==x:buttons[key]=0
    
        # to remove element 2 since axis numbers are 0 1 3 4
        buttons['axis1'],buttons['axis2'] ,buttons['axis3'] ,buttons['axis4']  = [axiss[0],axiss[1],axiss[3],axiss[4]]
       
        return buttons

    

    def publishCmdVel(self):
        
        # Check if joystick is connected
        if(not self.connection):
            self.connection = self.checkConnection()
        
        if(self.connection):
            # Get joystick data
            commands = self.getJoystickData()

            # Get the speed mode
            if(commands["t"] == 1):
                self.maxSpeedPercantage = 0.25
            elif(commands["x"] == 1):
                self.maxSpeedPercantage = 0.5
            elif(commands["o"] == 1):
                self.maxSpeedPercantage = 0.75
            elif(commands["s"] == 1):
                self.maxSpeedPercantage = 1
            
            # Create speed
            speed = -float((commands["axis2"]) * self.maxSpeed *self.maxSpeedPercantage) 
            steer = float((commands["axis1"]) * self.maxSpeed *self.maxSpeedPercantage)
        
        else:
            speed = 0.
            steer = 0.

        # Create Twist Message
        self.cmdMsg.linear.x = speed
        self.cmdMsg.angular.z = steer
        

        print("speed: ",speed," steer: ",steer)
        self.publisher.publish(self.cmdMsg)





def main(args=None):
    rclpy.init(args=args)

    joystickController = JoystickController()

    rclpy.spin(joystickController)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    joystickController.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    pygame.init()
    main()
