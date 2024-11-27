const int LED = 10;
const int button = 8;
int switchPosition = 0;
bool light = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchPosition = digitalRead(button);
  if (switchPosition == HIGH && light == false){
    digitalWrite(LED, HIGH);
    light = true;
  }
  else if (switchPosition == HIGH && light == true){
    digitalWrite(LED, LOW);
    light = false;
  }
  delay(250);
}
