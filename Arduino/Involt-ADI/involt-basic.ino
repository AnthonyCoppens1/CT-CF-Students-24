/*
  INVOLT BASIC ARDUINO SKETCH
  by Ernest Warzocha 2016
  ------------------------------------------------------
  This file is for serial communication between Arduino 
  Uno and Involt App. It can be used with Bluetooth 2.0
  device connected via hardware serial.
*/

/*
  involtPin array contains values received from app.
  Each UI element refers to pin number which is index of
  this array. involtString is array for values received
  with "S" pin. You can increase the length of array to
  store more values then arduino total pins. Use them 
  in sketch for not only pin-to-pin communication.
*/
int    involtPin[14] = {}; //equals involt.pin.P in app
String involtString[2] ={}; //equals involt.pin.S in app

/*
  Buffer for received data. If you plan to receive more 
  chars at once just increase the array length.
*/
char involt[16];

/*
  String for responding to function received from app.
*/
String fname;
int ledvalue = 0;
const int pot = A0;

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE 11

DHT dht(DHTPIN, DHTTYPE);
int buzzer = 3;
int buzz = 0;

void setup() {
 /*
  Connection speed must be same as app.
  Should remain unchanged.
 */
  pinMode(10, OUTPUT);
  dht.begin();

 Serial.begin(57600);
}

void loop() {
  involtReceive();

  digitalWrite(10, involtPin[10]);
  ledvalue = map(analogRead(pot), 0, 1023, 0, 255);
  analogWrite(5, ledvalue);
  involtSend(0, analogRead(pot));

  float h = dht.readHumidity();
  involtSend(12, h);
  /*if (h > 70){
    tone(buzzer, 523.3);
  }
  else{
    noTone(buzzer);
  }*/
  buzz = map(analogRead(A0), 0, 1023, 0, 1000);
  tone(buzzer, buzz);
  



  //PUT YOUR CODE HERE

  //Clear the function to trigger it only once.
  fname = "";
}

/*
  INVOLT FUNCTIONS
  ------------------------------------------------------

  involtReceive
  ------------------------------------------------------ 
  read the data from app and parse the values received 
  into proper array. The read until is used due to
  issues with missing chars when reading direct strings.
  
  involtSend, involtSendString
  ------------------------------------------------------
  send int or string to app. Multiple prints are to
  reduce the sketch size (compared to sprintf()).

  involtSendFunction
  ------------------------------------------------------
  send function name to trigger it in app.
*/

void involtReceive(){
  if(Serial.available()>0) {
    Serial.readBytesUntil('\n',involt,sizeof(involt));
    int pin;
    if (involt[0] == 'P'){
      int value;
      sscanf(involt, "P%dV%d", &pin, &value);
      involtPin[pin] = value;
    }
    else if (involt[0] == 'S'){
      char value[sizeof(involt)];
      sscanf(involt, "S%dV%s", &pin, &value);
      involtString[pin] = value;
    }
    else if (involt[0] == 'F'){
      char value[sizeof(involt)];
      sscanf(involt, "F%s", &value);
      fname = value;
    };
    memset(involt,0,sizeof(involt));
  };
};

void involtSend(int pinNumber, int sendValue){
  Serial.print('A'); 
  Serial.print(pinNumber); 
  Serial.print('V'); 
  Serial.print(sendValue); 
  Serial.println('E');
  Serial.flush();
};

void involtSendString(int pinNumber, String sendString){
  Serial.print('A'); 
  Serial.print(pinNumber); 
  Serial.print('V'); 
  Serial.print(sendString); 
  Serial.println('E'); 
  Serial.flush();

};

void involtSendFunction(String functionName){
  Serial.print('F'); 
  Serial.print(functionName); 
  Serial.println('E'); 
  Serial.flush();
};

