const int rood = 12;
const int geel = 10;
const int groen = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(rood,OUTPUT);
  pinMode(geel,OUTPUT);
  pinMode(groen,OUTPUT);
}

void loop() {
  digitalWrite(rood,LOW);
  digitalWrite(groen,HIGH);
  delay(5000);
  digitalWrite(groen, LOW);
  digitalWrite(geel,HIGH);
  delay(1000);
  digitalWrite(geel,LOW);
  digitalWrite(rood,HIGH);
  delay(5000);

}
