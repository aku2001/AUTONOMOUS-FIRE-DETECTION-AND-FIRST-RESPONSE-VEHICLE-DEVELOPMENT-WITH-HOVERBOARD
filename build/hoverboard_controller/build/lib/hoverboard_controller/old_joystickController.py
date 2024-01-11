import pygame
import time
import serial

baudRate = 115200
port = "/dev/ttyUSB0"

maxSpeed = 100

startByte = b'\xfe'
stopByte = b'\xff'

msg =bytearray(4)
msg[0] = 254
msg[3] = 255


buttons = {'x':0,'o':0,'t':0,'s':0,
           'L1':0,'R1':0,'L2':0,'R2':0,
           'share':0,'options':0,
           'axis1':0.,'axis2':0.,'axis3':0.,'axis4':0.}
axiss=[0.,0.,0.,0.,0.,0.]



def initializeSerial():
    global arduino
    try:
        arduino = serial.Serial(port=port,baudrate=baudRate, timeout=.1)
        time.sleep(1)
        return True
    except:
        return False

def checkConnection():
    global controller
    pygame.joystick.quit()
    pygame.joystick.init()
    joystick_count = pygame.joystick.get_count()
    if(joystick_count > 0):
        controller = pygame.joystick.Joystick(0)
        controller.init()
        return True
    else:
        return False


def giveCommand():
    global maxSpeed
    commands = getJS()

    if(commands["t"] == 1):
        maxSpeed = 10
    elif(commands["x"] == 1):
        maxSpeed = 50
    elif(commands["o"] == 1):
        maxSpeed = 75
    elif(commands["s"] == 1):
        maxSpeed = 100
    

    speed = int((commands["axis2"]) * maxSpeed) + 100
    steer = int((commands["axis1"]) * maxSpeed) + 100

    # print("speed: ",speed," steer: ",steer)
    
    msg[1] = int(speed)
    msg[2] = int(steer)

    arduino.write(msg)
    time.sleep(0.01)
    readData()
    
def readDatav2():
    while(arduino.in_waiting > 0):
        print(arduino.readline())

def readData():
    receivedMessage = []
    data = arduino.read()
    while(arduino.in_waiting > 0 and data != startByte):
        data = arduino.read()

    
    while(arduino.in_waiting > 0):
        data = arduino.read()
        if(data != stopByte):
            receivedMessage.append(int.from_bytes(data,"big"))
        else:
            break
    
    if(len(receivedMessage) == 2):
        print("--------------------------------------------")
        print("New Message: ")
        print("Speed: ",receivedMessage[0])
        print("Steer: ",receivedMessage[1])




def getJS(name=''):
 
    global buttons
    # retrieve any events ...
    for event in pygame.event.get():                                # Analog Sticks
        if event.type == pygame.JOYAXISMOTION:
            axiss[event.axis] = round(event.value,2)
        elif event.type == pygame.JOYBUTTONDOWN:                    # When button pressed
            #print(event.dict, event.joy, event.button, 'PRESSED')
            for x,(key,val) in enumerate(buttons.items()):
                if x<10:
                    if controller.get_button(x):buttons[key]=1
        elif event.type == pygame.JOYBUTTONUP:                      # When button released
            #print(event.dict, event.joy, event.button, 'released')
            for x,(key,val) in enumerate(buttons.items()):
                if x<10:
                    if event.button ==x:buttons[key]=0
 
    # to remove element 2 since axis numbers are 0 1 3 4
    buttons['axis1'],buttons['axis2'] ,buttons['axis3'] ,buttons['axis4']  = [axiss[0],axiss[1],axiss[3],axiss[4]]
    if name == '':
        return buttons
    else:
        return buttons[name]




if __name__ == "__main__":

    pygame.init()
    
    #Check the Serial communication
    while(not initializeSerial()):
        print("Serial connection couldn't be established")
        time.sleep(0.1)
        continue

    #check the joystick connection
    while(not checkConnection()):
        print("Joystic Connection couldn't be established")
        time.sleep(0.1)
        continue

    checkTime = 5
    lastChecked = time.time()
    connection = True

    while True:
        
        if(connection):
            giveCommand()                          
            

        else:
            msg[1] = 100
            msg[2] = 100

            arduino.write(msg)
            
            print("There is no connection")
            connection = checkConnection()
        
        time.sleep(0.01)