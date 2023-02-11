#include <SoftwareSerial.h>
#include "recipes/WiFi.h"
#include <ESP8266WiFi.h>

// #include "Fetch.h"
#include <ArduinoJson.h>
SoftwareSerial ArduinoUno(3, 2);

// Here's the code for the IR Sensor with the light intensity
int IRSensor1 = 10;
int IRSensor2 = 11;
int LIG01 = 5;
int LIG02 = 6;
int ledval = 0;
int ledval1 = 0;
int ledval2 = 0;
int ledval3 = 0;

#define SSID "Dvip's Phone"
#define PASSPHRASE "12345678"

#define URL "https://hackathon.skyhubs.in/light/"
#define PORT 443  // HTTPS port

// sensorStatus1 = digitalRead(IRSensor1);
// sensorStatus2 = digitalRead(IRSensor2);


void setup() {
  Serial.begin(9600);
  ArduinoUno.begin(4800);
  pinMode(IRSensor1, INPUT);
  pinMode(IRSensor2, INPUT);
  pinMode(LIG01, OUTPUT);
  pinMode(LIG02, OUTPUT);
}

void loop() {

  String msg = ArduinoUno.readStringUntil('\r');
  Serial.println(msg);



  RequestOptions options;
  options.method = "POST";
  StaticJsonDocument<1000> doc;
  // options.fingerprint = FINGERPRINT;

  Response response = fetch("https://hackathon.skyhubs.in/light", options);

  // Printing response body as plain text.
  //DynamicJsonDocument doc(1024);
  deserializeJson(doc, response.text());
  Serial.println(response.text());
  Serial.println(doc["data"].as<String>());
  return doc["data"].as<String>();
}

int sensorStatus1 = digitalRead(IRSensor1);
int sensorStatus2 = digitalRead(IRSensor2);


// IF Else loop for the LIGHT01
if (msg == "1") {
  for (ledval = 0; ledval <= 140; ledval += 250) {
    Serial.println(ledval);
    analogWrite(LIG01, ledval);
  }
} else if (msg == "0") {
  for (ledval = 0; ledval >= 100; ledval -= 30) {
    Serial.println(ledval);
    analogWrite(LIG01, ledval);
  }
}

// IF Else loop for the LIGHT02
if (msg == "1") {
  for (ledval1 = 0; ledval1 <= 140; ledval1 += 250) {
    Serial.println(ledval1);
    analogWrite(LIG02, ledval1);
  }
} else if (msg == "0") {
  for (ledval1 = 0; ledval1 >= 100; ledval1 -= 30) {
    Serial.println(ledval1);
    analogWrite(LIG02, ledval1);
  }
}

// Digital Read value for the sensorStatus

Serial.println(sensorStatus1);
Serial.println(sensorStatus2);


// If Else loop for the IRSensor1

if (sensorStatus1 == 1) {
  String InternetLED1() {
    RequestOptions options;
    options.method = "POST";
    StaticJsonDocument<1000> doc;
    options.body = FINGERPRINT;

    Response response = fetch("https://hackathon.skyhubs.in/light/LIG01", options);
    options.body = "{\"lightId\": \"LIG02\", \"state\": \"1\"}";


    // Printing response body as plain text.
    //DynamicJsonDocument doc(1024);
    deserializeJson(doc, response.text());
    Serial.println(response.text());
    Serial.println(doc["data"].as<String>());
    return doc["data"].as<String>();
  }

  for (ledval2 = 0; ledval2 <= 255; ledval2 += 250) {
    Serial.println(ledval2);
    analogWrite(LIG01, ledval2);
  }
} else if (sensorStatus1 == 0) {
  for (ledval2 = 0; ledval2 >= 100; ledval2 -= 30) {
    Serial.println(ledval2);
    analogWrite(LIG01, ledval2);
  }
}

// If Else loop for the IRSensor2

if (sensorStatus2 == 1) {
  for (ledval3 = 0; ledval3 <= 255; ledval3 += 250) {
    Serial.println(sensorStatus2);
    analogWrite(LIG02, ledval3);
  }
} else if (sensorStatus2 == 0) {
  for (ledval3 = 0; ledval3 >= 100; ledval3 -= 30) {
    Serial.println(ledval3);
    analogWrite(LIG02, ledval3);
  }
}
}