const int pot = A0;
int potValue = 0;
const int LED = 3;
int LEDValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pot, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(pot);
  LEDValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(LED, LEDValue);
  Serial.println(potValue);
}
