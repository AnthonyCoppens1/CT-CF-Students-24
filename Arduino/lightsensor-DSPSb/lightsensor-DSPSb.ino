const int LED = 3;
const int light = A0;
int LEDValue = 0;
int lightValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(light, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightValue = analogRead(light);
  LEDValue = map(lightValue, 35, 1015, 0, 255);
  analogWrite(LED, LEDValue);
  Serial.println(lightValue);
  delay(100);






}
