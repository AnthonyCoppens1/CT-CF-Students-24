const int lightsensor = A0;
int lightVal = 0;
const int LED = 10;
int LEDVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightsensor, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightsensor);
  LEDVal = map(lightVal, 1023, 0, 255, 0);
  analogWrite(LED, LEDVal);
  Serial.println(lightVal);
  delay(200);
}
