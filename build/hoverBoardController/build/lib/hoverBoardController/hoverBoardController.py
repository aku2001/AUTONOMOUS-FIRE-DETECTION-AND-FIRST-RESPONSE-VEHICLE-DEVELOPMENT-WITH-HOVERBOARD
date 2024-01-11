import pygame
import time
import serial
import math

# SERIAL COMMUNICATION
BAUD_RATE = 115200
PORT = "/dev/ttyUSB0"
MESSAGE_LENGTH = 4
START_BYTE = b'\xfe'
STOP_BYTE = b'\xff'

# HOVERBOARD PHSICAL INFO
TIRE_RADIUS = 0.2
TIRE_CIRCUMFERENCE = 2 * math.pi * TIRE_RADIUS

# HOVERBOARD INFO
HOVERBOARD_BASE_RPM= 40
HOVERBOARD_BASE_SPEED = 100
HOVERBOARD_STOP_SPEED = 40
HOVERBOARD_MAX_SPEED = 1000

# Message Types
SPEED_MSG = 1
STEER_MSG = 2
SONAR1_MSG = 3
SONAR2_MSG = 4
SONAR3_MSG = 5
SONAR4_MSG = 6
SONAR5_MSG = 7
TEMP1_MSG = 8
TEMP2_MSG = 9
TEMP3_MSG = 10
TEMP4_MSG = 11


HEARTBEAT_INTERVAL = 1  # second



import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist


class HoverboardController(Node):

    def __init__(self):
        super().__init__('hoverboard_controller')
        

        # Set the serial message to stop the hoverboard
        self.hoverBoardSpeed = 0
        self.hoverBoardSteer = 0

        # For the heartbeat indicator
        self.lastTime = time.time()

        # Initialize Serial Communication
        while(not self.initializeSerial()):
            print("Serial connection couldn't be established")
            time.sleep(0.1)
        

        # Initalize Subscriber
        self.subscription = self.create_subscription(Twist, '/cmd_vel', self.controllerCallback, 10)
        self.subscription  # prevent unused variable warning

        # Set the frequency for communication between the computer and the board
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.sendData)
    
    def sendData(self):
        self.serialMsg =bytearray(4)
        # If the time of the last command received is bigger than the interval stop the car
        if(time.time() - self.lastTime > HEARTBEAT_INTERVAL):
            self.hoverBoardSpeed = 0
            self.hoverBoardSteer = 0

        # Convert the steer and speed integer data into 2 byte short
        hoverBoardSteerMsg =  (STEER_MSG << 12 ) + self.hoverBoardSteer  
        bytes = hoverBoardSteerMsg.to_bytes(2, byteorder='big')
        self.serialMsg[0] = bytes[0]
        self.serialMsg[1] = bytes[1]

        hoverBoardSpeedMsg =  (SPEED_MSG << 12 ) + self.hoverBoardSpeed  
        bytes = hoverBoardSpeedMsg.to_bytes(2, byteorder='big')
        self.serialMsg[2] = bytes[0]
        self.serialMsg[3] = bytes[1]

        # Send the byte array message
        # self.ser.write(self.serialMsg)
        self.readData()


    def controllerCallback(self, msg):
        # Convert the cmd_vel msg into hoverboard message

        self.lastTime = time.time()
        
        # Linear Speed
        # Convert m/s to rpm and then to hoverboard speed
        rpm= msg.linear.x * 60 / TIRE_CIRCUMFERENCE
        if(rpm >= HOVERBOARD_BASE_RPM):
            self.hoverBoardSpeed = min(HOVERBOARD_MAX_SPEED, HOVERBOARD_BASE_SPEED +  (int(rpm - HOVERBOARD_BASE_RPM)//6*10))
        elif(rpm <= -HOVERBOARD_BASE_RPM):
            self.hoverBoardSpeed = max(-HOVERBOARD_MAX_SPEED, -HOVERBOARD_BASE_SPEED - (int(abs(rpm) - HOVERBOARD_BASE_RPM)//6*10))
        else:
            self.hoverBoardSpeed = 0

        # Angular Speed
        # Convert m/s to rpm and then to hoverboard speed
        rpm= msg.angular.z * 60 / TIRE_CIRCUMFERENCE
        if(rpm != 0):
            self.hoverBoardSteer = int(rpm/6)*10
        else:
            self.hoverBoardSteer = 0     
        
        # print("Sent: speed: {}, steer: {}".format(self.hoverBoardSpeed,self.hoverBoardSteer))


    def initializeSerial(self):
        try:
            self.ser = serial.Serial(port=PORT,baudrate=BAUD_RATE, timeout=.1)
            time.sleep(1)
            return True
        except Exception as e:
            print(e)
            return False
    
    def readData(self):
        msgReceived = False
        datas = bytearray()

        while(self.ser.in_waiting > 0):
            
            datas.extend(self.ser.read())
            msgType = datas[0] >> 4
            if(msgType>0 and msgType < 12 and self.ser.in_waiting > 0):
                datas.extend(self.ser.read())
                msgReceived = True
            else:
                msgReceived = False

            if(msgReceived):
                if(msgType == SPEED_MSG):
                    speed = int.from_bytes(datas,byteorder="big")
                    speed -= (SPEED_MSG << 12 ) 
                    print("Speed : ",speed)
                elif(msgType == STEER_MSG):
                    steer = int.from_bytes(datas,byteorder="big")
                    steer -= (STEER_MSG << 12 ) 
                    print("Steer : ",steer)
                else:
                    print("Msg Type: ",msgType)




def main(args=None):
    rclpy.init(args=args)

    hoverBoardController = HoverboardController()

    rclpy.spin(hoverBoardController)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    hoverBoardController.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()