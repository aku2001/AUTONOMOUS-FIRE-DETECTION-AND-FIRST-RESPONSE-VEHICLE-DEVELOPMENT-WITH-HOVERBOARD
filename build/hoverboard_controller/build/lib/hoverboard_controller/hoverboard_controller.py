import pygame
import time
import serial
import math
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


# SERIAL COMMUNICATION
BAUD_RATE = 115200
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




class HoverboardController(Node):

    def __init__(self):
        super().__init__('hoverboard_controller')

        # Get params
        self.declare_parameter('serial_port', '/dev/ttyUSB1') 
        self.port = self.get_parameter('serial_port').value       

        # Set the serial message to stop the hoverboard
        self.hoverBoardSpeed = 0
        self.hoverBoardSteer = 0
        self.sonarMsg = [-1,-1,-1,-1,1]
        self.tmpMsg = [-1,-1,-1,-1]
        self.speedInfoMsg = [5,5]

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
        hoverBoardSteerMsg =  (STEER_MSG << 12 ) + self.hoverBoardSteer + HOVERBOARD_MAX_SPEED
        bytes = hoverBoardSteerMsg.to_bytes(2, byteorder='big')
        self.serialMsg[0] = bytes[0]
        self.serialMsg[1] = bytes[1]

        hoverBoardSpeedMsg =  (SPEED_MSG << 12 ) + self.hoverBoardSpeed + HOVERBOARD_MAX_SPEED
        bytes = hoverBoardSpeedMsg.to_bytes(2, byteorder='big')
        self.serialMsg[2] = bytes[0]
        self.serialMsg[3] = bytes[1]

        # Send the byte array message
        self.ser.write(self.serialMsg)
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

        # Invert Linear Speed
        self.hoverBoardSpeed *= -1

        # Angular Speed
        # Convert m/s to rpm and then to hoverboard speed
        rpm= msg.angular.z * 60 / TIRE_CIRCUMFERENCE
        if(rpm != 0):
            self.hoverBoardSteer = int(rpm/6)*10
        else:
            self.hoverBoardSteer = 0    

        if(self.hoverBoardSpeed == 0 and self.hoverBoardSteer != 0):
            if(self.hoverBoardSteer < 0):
                self.hoverBoardSteer = -HOVERBOARD_BASE_SPEED / 2
            else:
                self.hoverBoardSteer = HOVERBOARD_BASE_SPEED / 2
            
            self.hoverBoardSpeed = -abs(self.hoverBoardSteer * 2)
            self.hoverBoardSpeed = int(self.hoverBoardSpeed)
            self.hoverBoardSteer = int(self.hoverBoardSteer)
        elif(abs(self.hoverBoardSteer) > abs(self.hoverBoardSpeed/2)):
            if(self.hoverBoardSteer < 0):
                self.hoverBoardSteer = int(-abs(self.hoverBoardSpeed/2))
            elif(self.hoverBoardSteer > 0):
                self.hoverBoardSteer = int(abs(self.hoverBoardSpeed/2))


        
        print("Sent: speed: {}, steer: {}".format(self.hoverBoardSpeed,self.hoverBoardSteer))


    def initializeSerial(self):
        try:
            self.ser = serial.Serial(port=self.port,baudrate=BAUD_RATE, timeout=.1)
            time.sleep(1)
            return True
        except Exception as e:
            print(e)
            return False
    
    def readData(self):
        msgReceived = False

        while(self.ser.in_waiting > 0):
            datas = bytearray()
            
            data = self.ser.read()
            datas.extend(data)

            msgType = datas[0] >> 4

            if(msgType>0 and msgType < 12 and self.ser.in_waiting > 0):
                datas.extend(self.ser.read())                
                msgReceived = True
            else:
                msgReceived = False

            if(msgReceived):
                if(msgType == SPEED_MSG):
                    self.speedInfoMsg[0] = int.from_bytes(datas,byteorder="big")
                    self.speedInfoMsg[0] = self.speedInfoMsg[0] - (SPEED_MSG << 12 ) - HOVERBOARD_MAX_SPEED
                elif(msgType == STEER_MSG):
                    self.speedInfoMsg[1] = int.from_bytes(datas,byteorder="big")
                    self.speedInfoMsg[1] = self.speedInfoMsg[1] - (STEER_MSG << 12 ) - HOVERBOARD_MAX_SPEED 
                elif(msgType == SONAR1_MSG):
                    self.sonarMsg[0] = int.from_bytes(datas,byteorder="big")
                    self.sonarMsg[0] = self.sonarMsg[0] - (SONAR1_MSG << 12 )
                elif(msgType == SONAR2_MSG):
                    self.sonarMsg[1] = int.from_bytes(datas,byteorder="big")
                    self.sonarMsg[1] = self.sonarMsg[1] - (SONAR2_MSG << 12 )
                elif(msgType == SONAR3_MSG):
                    self.sonarMsg[2] = int.from_bytes(datas,byteorder="big")
                    self.sonarMsg[2] = self.sonarMsg[2] - (SONAR3_MSG << 12 )
                elif(msgType == SONAR4_MSG):
                    self.sonarMsg[3] = int.from_bytes(datas,byteorder="big")
                    self.sonarMsg[3] = self.sonarMsg[3] - (SONAR4_MSG << 12 )
                elif(msgType == SONAR5_MSG):
                    self.sonarMsg[4] = int.from_bytes(datas,byteorder="big")
                    self.sonarMsg[4] = self.sonarMsg[4] - (SONAR5_MSG << 12 )
                elif(msgType == TEMP1_MSG):
                    self.tmpMsg[0] = int.from_bytes(datas,byteorder="big")
                    self.tmpMsg[0] = self.tmpMsg[0] - (TEMP1_MSG << 12 )
                elif(msgType == TEMP2_MSG):
                    self.tmpMsg[1] = int.from_bytes(datas,byteorder="big")
                    self.tmpMsg[1] = self.tmpMsg[1] - (TEMP2_MSG << 12 )
                elif(msgType == TEMP3_MSG):
                    self.tmpMsg[2] = int.from_bytes(datas,byteorder="big")
                    self.tmpMsg[2] = self.tmpMsg[2] - (TEMP3_MSG << 12 )
                elif(msgType == TEMP4_MSG):
                    self.tmpMsg[3] = int.from_bytes(datas,byteorder="big")
                    self.tmpMsg[3] = self.tmpMsg[3] - (TEMP4_MSG << 12 )
                else:
                    print("Msg Type: ",msgType)
                    return
                

                # print("Msg Type: ",msgType)
                # self.printData()
                


    def printData(self):
        print("Speed Info: {}, {}".format(self.speedInfoMsg[0],self.speedInfoMsg[1]))
        print("Sonar Data: {}, {}, {}, {}, {}".format(self.sonarMsg[0],self.sonarMsg[1],self.sonarMsg[2],self.sonarMsg[3],self.sonarMsg[4]))
        print("Temp Data: {}, {}, {}, {}".format(self.tmpMsg[0],self.tmpMsg[1],self.tmpMsg[2],self.tmpMsg[3]))

    def saveMap(self):
        pass







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