int ledLight = 13;
int motionSensor = 2;
int motionReading;


void setup()
{
  pinMode(ledLight, OUTPUT);
  pinMode(motionSensor, INPUT);
  Serial.begin(9600);
}


void printMotionReading(String reading) {
  Serial.println("Motion sensor reading is " + reading);
}


void loop()
{
  motionReading = digitalRead(motionSensor);
  
  if (motionReading == HIGH) {
    digitalWrite(ledLight, HIGH);
    printMotionReading("HIGH");
  } else {
    digitalWrite(ledLight, LOW);
    printMotionReading("LOW");
  }
  delay(50);
}
