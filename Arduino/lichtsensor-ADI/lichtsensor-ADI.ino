const int lichtsensor = A0;
int lichtwaarde = 0;
const int LED = 9; //voor variabele stroom moet poort met ~
int LEDwaarde = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(lichtsensor, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lichtwaarde = analogRead(lichtsensor);
  LEDwaarde = map(lichtwaarde, 0, 1023, 0, 255);
  analogWrite(LED,LEDwaarde);
  Serial.println(lichtwaarde);
  delay(100);
}
