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
int involtPin[14] = {};       //equals involt.pin.P in app
String involtString[2] = {};  //equals involt.pin.S in app

/*
  Buffer for received data. If you plan to receive more 
  chars at once just increase the array length.
*/
char involt[16];

/*
  String for responding to function received from app.
*/
String fname;

// Define notes
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

// Happy Birthday melody
int melody[] = {
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_B4,           // "Happy Birthday to You"
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5,           // "Happy Birthday to You"
  NOTE_G4, NOTE_G4, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4,  // "Happy Birthday Dear [Name]"
  NOTE_F5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_C5            // "Happy Birthday to You"
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  4, 8, 4, 4, 4, 2,
  4, 8, 4, 4, 4, 2,
  4, 8, 4, 4, 8, 8, 2,
  4, 8, 4, 4, 4, 2
};


#include "DHT.h";
#define DHTPIN 2  //const int DHTPIN = 2;
#define DHTTYPE 11

DHT dht(DHTPIN, DHTTYPE);
int buzzer = 3;

const int LED = 10;
int ledValue = 0;

const int LED2 = 5;


void setup() {
  /*
  Connection speed must be same as app.
  Should remain unchanged.  
 */
  pinMode(LED, OUTPUT);
  dht.begin();
  Serial.begin(57600);
}

void loop() {
  involtReceive();
  digitalWrite(LED, involtPin[LED]);  //THIS IS NUMBER 10 or PIN 10

  ledValue = map(analogRead(A0), 0, 1023, 0, 255);
  analogWrite(LED2, ledValue);
  involtSend(0, analogRead(A0));

  float humidity = dht.readHumidity();
  involtSend(12, humidity);

  if (humidity > 80) {
    // Play the melody
    for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];  // Calculate duration
      tone(buzzer, melody[thisNote], noteDuration);       // Play the note
      delay(noteDuration * 1.30);                         // Delay between notes
      noTone(buzzer);                                     // Turn off the tone
    }
  }
  else{
    noTone(buzzer);
  }


  float temperature = dht.readTemperature();

  // Check if reading failed
  if (isnan(temperature)) {
    Serial.println("Error reading temperature");
    return;
  }

  involtSend(11, temperature);

  // Send temperature value to involt as JSON
  Serial.print("{\"temperature\":");
  Serial.print(temperature);
  Serial.println("}");

  // Delay before the next reading
  delay(1000); // Update every 1 second


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

void involtReceive() {
  if (Serial.available() > 0) {
    Serial.readBytesUntil('\n', involt, sizeof(involt));
    int pin;
    if (involt[0] == 'P') {
      int value;
      sscanf(involt, "P%dV%d", &pin, &value);
      involtPin[pin] = value;
    } else if (involt[0] == 'S') {
      char value[sizeof(involt)];
      sscanf(involt, "S%dV%s", &pin, &value);
      involtString[pin] = value;
    } else if (involt[0] == 'F') {
      char value[sizeof(involt)];
      sscanf(involt, "F%s", &value);
      fname = value;
    };
    memset(involt, 0, sizeof(involt));
  };
};

void involtSend(int pinNumber, int sendValue) {
  Serial.print('A');
  Serial.print(pinNumber);
  Serial.print('V');
  Serial.print(sendValue);
  Serial.println('E');
  Serial.flush();
};

void involtSendString(int pinNumber, String sendString) {
  Serial.print('A');
  Serial.print(pinNumber);
  Serial.print('V');
  Serial.print(sendString);
  Serial.println('E');
  Serial.flush();
};

void involtSendFunction(String functionName) {
  Serial.print('F');
  Serial.print(functionName);
  Serial.println('E');
  Serial.flush();
};
