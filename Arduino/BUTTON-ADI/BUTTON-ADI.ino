const int LED = 10;
const int drukknop = 8;
int drukstand = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(drukknop, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  drukstand = digitalRead(drukknop);
  if (drukstand == LOW){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
}
