int buzz = 9;
const int pot = A0;
int potValue = 0;
int buzzValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pot, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(pot);
  buzzValue = map(potValue, 0, 1023, 0, 1000);
  tone(buzz, buzzValue);
  
}
