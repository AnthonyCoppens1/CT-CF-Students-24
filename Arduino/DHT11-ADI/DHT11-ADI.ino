#include "DHT.h"
#define DHTPIN 2 //const int DHTPIN = 2;
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)){
    Serial.println("We kunnen niets lezen!");
    return;
  }

  Serial.print("Vochtigheid: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatuur: ");
  Serial.print(t);
  Serial.println(" °C");
  delay(500);
}
