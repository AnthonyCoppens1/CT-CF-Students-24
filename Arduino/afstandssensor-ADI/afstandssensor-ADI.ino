long afstand;
long duur;
int trig = 11;
int echo = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(7);
  digitalWrite(trig, LOW);

  duur = pulseIn(echo, HIGH);
  duur = ((duur/2)/29.4);
  Serial.print(duur);
  Serial.println("cm");
  delay(200);




}
