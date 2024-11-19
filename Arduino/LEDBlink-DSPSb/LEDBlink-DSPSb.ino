const int RED = 12; //0 or 1 signal
const int YELLOW = 10;
const int GREEN = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT); //in port 12 you have an output (LED)
  pinMode(YELLOW,OUTPUT);
  pinMode(GREEN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED,HIGH); //HIGH = 1, LOW = 0
  delay(5000);
  digitalWrite(RED,LOW);
  digitalWrite(YELLOW, HIGH);
  delay(1000);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  delay(5000);
  digitalWrite(GREEN, LOW);
}
