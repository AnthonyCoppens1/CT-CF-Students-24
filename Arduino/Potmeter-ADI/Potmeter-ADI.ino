const int potmeter = A0;
const int LED = 10;
int ledVal = 0;
int potVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(potmeter,INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potmeter);
  ledVal = map(potVal,0, 1023, 0, 255);
  analogWrite(LED, ledVal);
  Serial.println(potVal);
}
