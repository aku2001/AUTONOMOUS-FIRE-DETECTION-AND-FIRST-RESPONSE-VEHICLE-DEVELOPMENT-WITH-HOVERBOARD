#include <SoftwareSerial.h>

#define STOP_TRESHHOLD      50
#define MAX_SPEED 1000
#define MAX_STEER 1000
#define MESSAGE_LENGTH      4
#define HOVER_SERIAL_BAUD   115200      // [-] Baud rate for HoverSerial (used to communicate with the hoverboard)
#define SERIAL_BAUD         115200      // [-] Baud rate for built-in Serial (used for the Serial Monitor)
#define START_FRAME         0xABCD       // [-] Start frme definition for reliable serial communication
#define TIME_SEND           100         // [ms] Sending time interval
#define HEART_BEAT_INTERVAL 1000

// Message Type
#define SPEED_MSG   1
#define STEER_MSG   2
#define SONAR1_MSG  3
#define SONAR2_MSG  4
#define SONAR3_MSG  5
#define SONAR4_MSG  6
#define SONAR5_MSG  7
#define TEMP1_MSG   8
#define TEMP2_MSG   9
#define TEMP3_MSG   10
#define TEMP4_MSG   11

// About Sonar
#define MIN_SONAR_DISTANCE 20
#define STOP_SONAR_FRONT 1
#define STOP_SONAR_BACK 2

// #define DEBUG_RX                        // [-] Debug received data. Prints all bytes to serial (comment-out to disable)


// Global variables
uint8_t idx = 0;                        // Index for new data pointer
uint16_t bufStartFrame;                 // Buffer Start Frame
byte *p;                                // Pointer declaration for the new received data
byte incomingByte;
byte incomingBytePrev;

//Command and Feed Back Messages
typedef struct{
   uint16_t start;
   int16_t  steer;
   int16_t  speed;
   uint16_t checksum;
} SerialCommand;


typedef struct{
   uint16_t start;
   int16_t  cmd1;
   int16_t  cmd2;
   int16_t  speedR_meas;
   int16_t  speedL_meas;
   int16_t  batVoltage;
   int16_t  boardTemp;
   uint16_t cmdLed;
   uint16_t checksum;
} SerialFeedback;


SoftwareSerial HoverSerial(2,3);        // RX, TX

SerialCommand Command;
SerialFeedback Feedback;
SerialFeedback NewFeedback;


// ########################## SEND ##########################
void Send(int16_t uSteer, int16_t uSpeed)
{
  // Create command
  Command.start    = (uint16_t)START_FRAME;
  Command.steer    = (int16_t)uSteer;
  Command.speed    = (int16_t)uSpeed;
  Command.checksum = (uint16_t)(Command.start ^ Command.steer ^ Command.speed);

  // Write to Serial
  HoverSerial.write((uint8_t *) &Command, sizeof(Command)); 
}



// USED PINS: 4,5,6,7,8,9,10,11
byte data,datas[2],startByte=254,stopByte=255;
int cmd_vel,isReceived, msgType;
uint16_t carSpeed=0,carSteer=0;
unsigned long iTimeSend = 0;
unsigned long heartBeatTime;
float sonarDataList[5], tempDataList[4];

// Sonar Pins
const int sonarTrig1 = 4;
const int sonarEcho1 = 5;
const int sonarTrig2 = 6;
const int sonarEcho2 = 7;
const int sonarTrig3 = 8;
const int sonarEcho3 = 9;
const int sonarTrig4 = 10;
const int sonarEcho4 = 11;
const int sonarTrig5 = 12;
const int sonarEcho5 = 13;
int sonarStop = 0;

// Temp Pins
const int tempSensor1 = A0;
const int tempSensor2 = A1;
const int tempSensor3 = A2;
const int tempSensor4 = A3;


// GET COMMAND FROM SERIAL 
void getCommand(){

     while(Serial.available() > 0){
        datas[0] = Serial.read();
        msgType = datas[0] >> 4;

        if(msgType>0 && msgType<12 && Serial.available()>0){
          datas[1] = Serial.read();
          
          datas[0] = datas[0] & 0x0F;
          if(msgType == SPEED_MSG){
            carSpeed = (datas[1] | datas[0] << 8) - MAX_SPEED;
            heartBeatTime = millis();
          }
          else if(msgType == STEER_MSG){
            carSteer = (datas[1] | datas[0] << 8) - MAX_SPEED;
            heartBeatTime = millis();
          }
        }
     }
}

void sendData(){

  // Get Speed Message
  int steerMsg = (STEER_MSG << 12) + carSteer + MAX_SPEED;
  int speedMsg = (SPEED_MSG << 12) + carSpeed + MAX_SPEED;
  
  // Get Sonar Message
  int sonarMsg1 = (SONAR1_MSG << 12) + min(sonarDataList[0],1000);
  int sonarMsg2 = (SONAR2_MSG << 12) + min(sonarDataList[1],1000);
  int sonarMsg3 = (SONAR3_MSG << 12) + min(sonarDataList[2],1000);
  int sonarMsg4 = (SONAR4_MSG << 12) + min(sonarDataList[3],1000);
  int sonarMsg5 = (SONAR5_MSG << 12) + min(sonarDataList[4],1000);

  // Get Tmp Message
  int tmpMsg1 = (TEMP1_MSG << 12) + min(tempDataList[0],1000);
  int tmpMsg2 = (TEMP2_MSG << 12) + min(tempDataList[0],1000);
  int tmpMsg3 = (TEMP3_MSG << 12) + min(tempDataList[0],1000);
  int tmpMsg4 = (TEMP4_MSG << 12) + min(tempDataList[0],1000);



  // Send Speed Data
  Serial.write(highByte(speedMsg));
  Serial.write(lowByte(speedMsg));
  Serial.write(highByte(steerMsg));
  Serial.write(lowByte(steerMsg));

  // Send Sonar Data
  Serial.write(highByte(sonarMsg1));
  Serial.write(lowByte(sonarMsg1));
  Serial.write(highByte(sonarMsg2));
  Serial.write(lowByte(sonarMsg2));
  Serial.write(highByte(sonarMsg3));
  Serial.write(lowByte(sonarMsg3));
  Serial.write(highByte(sonarMsg4));
  Serial.write(lowByte(sonarMsg4));
  Serial.write(highByte(sonarMsg5));
  Serial.write(lowByte(sonarMsg5));

  // Send Temp Data
  Serial.write(highByte(tmpMsg1));
  Serial.write(lowByte(tmpMsg1));
  Serial.write(highByte(tmpMsg2));
  Serial.write(lowByte(tmpMsg2));
  Serial.write(highByte(tmpMsg3));
  Serial.write(lowByte(tmpMsg3));
  Serial.write(highByte(tmpMsg4));
  Serial.write(lowByte(tmpMsg4));
}


void sendCommand(){
  sendData();
  Send(carSteer, carSpeed);
}

int getSonarData(int sonarTrig, int sonarEcho){
  float duration,distance;
  digitalWrite(sonarTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonarTrig, LOW);

  duration = pulseIn(sonarEcho, HIGH,10000);
  if(distance == 0){
    // Max Value
    return 100;
  }
  else{
    distance = duration * 0.034 / 2;
    return int(distance);
  }
}

float getTempData(int tempSensor){
  float tempVoltage, temp;
  int readValue;
  readValue = analogRead(tempSensor);
  tempVoltage = (readValue / 1023.0)*5000;
  temp = tempVoltage /10.0; 
  return temp;
}

int getSonarDataList(){
  int i; 
  sonarStop = 0;
  sonarDataList[0] = getSonarData(sonarTrig1,sonarEcho1);
  sonarDataList[1] = getSonarData(sonarTrig2,sonarEcho2);
  sonarDataList[2] = getSonarData(sonarTrig3,sonarEcho3);
  sonarDataList[3] = getSonarData(sonarTrig4,sonarEcho4);
  sonarDataList[4] = getSonarData(sonarTrig5,sonarEcho5);

  for(i=0;i<3;i++){
    if(sonarDataList[i] < MIN_SONAR_DISTANCE){
      sonarStop = 1;
    }
  }

  for(i=3;i<5;i++){
    if(sonarDataList[i] < MIN_SONAR_DISTANCE){
      sonarStop = 2;
    }
  }

  return sonarStop;

}

void getTempDataList(){
  tempDataList[0] = getTempData(tempSensor1);
  tempDataList[0] = getTempData(tempSensor2);
  tempDataList[0] = getTempData(tempSensor3);
  tempDataList[0] = getTempData(tempSensor4);
}

//MAIN METHOD



void setup() 
{
  Serial.begin(SERIAL_BAUD);
  analogReference(INTERNAL1V1);

  // Set Sonar Pins
  pinMode(sonarTrig1, OUTPUT);
  pinMode(sonarEcho1, INPUT);
  pinMode(sonarTrig2, OUTPUT);
  pinMode(sonarEcho2, INPUT);
  pinMode(sonarTrig3, OUTPUT);
  pinMode(sonarEcho3, INPUT);
  pinMode(sonarTrig4, OUTPUT);
  pinMode(sonarEcho4, INPUT);
  pinMode(sonarTrig5, OUTPUT);
  pinMode(sonarEcho5, INPUT);

  digitalWrite(sonarTrig1, LOW);
  digitalWrite(sonarTrig2, LOW);
  digitalWrite(sonarTrig3, LOW);
  digitalWrite(sonarTrig4, LOW);
  digitalWrite(sonarTrig5, LOW);


  HoverSerial.begin(HOVER_SERIAL_BAUD);
  heartBeatTime = millis();
}


void loop()
{ 
  //Get Command From Serial 
  getCommand();

  // Get Sonar Data 
  getSonarDataList();
  getTempDataList();

  //If the last received command exceed the heart beat interval stop the car
  if(!isReceived && (millis() - heartBeatTime) > HEART_BEAT_INTERVAL){
    carSpeed = 0;
    carSteer = 0;
  }

  if(sonarStop == STOP_SONAR_FRONT && carSpeed > 0){
    carSpeed = 0;
    carSteer = 0;
  }

  if(sonarStop == STOP_SONAR_BACK && carSpeed < 0){
    carSpeed = 0;
    carSteer = 0;
  }
  
  sendCommand();

}