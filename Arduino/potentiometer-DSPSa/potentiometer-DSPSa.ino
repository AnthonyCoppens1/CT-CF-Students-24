const int LED = 10;
const int pot = A0;
int potValue = 0;
int LEDValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(pot);
  LEDValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(LED,LEDValue);
  Serial.println(potValue);
}
