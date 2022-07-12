int ledLight = 13;
int motionSensor = 2;
uint8_t ledState = LOW;


void setup()
{
  pinMode(ledLight, OUTPUT);
  pinMode(motionSensor, INPUT);
  attachInterrupt(digitalPinToInterrupt(motionSensor), changeStateOperations, CHANGE);
  Serial.begin(9600);
}


void loop()
{
  delay(1000);
}


void printMotionReading() {
  String reading = "LOW";
  if(digitalRead(motionSensor) == HIGH) {
    reading = "HIGH";
  } 
  Serial.println("Motion sensor reading is " + reading);
}


void changeStateOperations() {
  ledState = !ledState;
  digitalWrite(ledLight, ledState);
  printMotionReading();
}
