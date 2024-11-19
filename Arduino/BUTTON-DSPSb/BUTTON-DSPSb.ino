const int LED = 12;
const int button = 6;
int buttonPosition = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonPosition = digitalRead(button);
  if (buttonPosition == HIGH){
    digitalWrite(LED, LOW);
  }
  else{
    digitalWrite(LED, HIGH);
  }
}
