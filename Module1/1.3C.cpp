int ledLightOne = 13;
int ledLightTwo = 12;

int motionSensorOne = 2;
int motionSensorTwo = 3;

uint8_t ledOneState = LOW;
uint8_t ledTwoState = LOW;


void setup()
{
  pinMode(ledLightOne, OUTPUT);
  pinMode(ledLightTwo, OUTPUT);
  
  pinMode(motionSensorOne, INPUT);
  attachInterrupt(digitalPinToInterrupt(motionSensorOne), changeStateOperationsMotionOne, CHANGE);
  
  pinMode(motionSensorTwo, INPUT);
  attachInterrupt(digitalPinToInterrupt(motionSensorTwo), changeStateOperationsMotionTwo, CHANGE);
  
  Serial.begin(9600);
}


void loop()
{
  delay(1000);
}


void printSensorReading(int sensor, String sensorName) {
  String reading = "LOW";
  if(digitalRead(sensor) == HIGH) {
    reading = "HIGH";
  } 
  Serial.println(sensorName + " sensor reading is " + reading);
  reading = "LOW";
}


void changeStateOperationsMotionOne() {
  noInterrupts();
  ledOneState = !ledOneState;
  digitalWrite(ledLightOne, ledOneState);
  printSensorReading(motionSensorOne, "Motion 1");
  interrupts();
}


void changeStateOperationsMotionTwo() {
  noInterrupts();
  ledTwoState = !ledTwoState;
  digitalWrite(ledLightTwo, ledTwoState);
  printSensorReading(motionSensorTwo, "Motion 2");
  interrupts();
}
