// int LDR_Val = 0;
// int SENSOR = 34;
// int LED = 25;

// void setup(){
//   Serial.begin(9600);
//   pinMode(LED, OUTPUT);
// }

// void loop(){
//   LDR_Val = analogRead(SENSOR);
//   Serial.print("LDR Output: ");
//   Serial.print(LDR_Val);
//   if(LDR_Val > 100){
//   Serial.print("Cahaya Terang");
//   digitalWrite(LED, LOW);
//   }else{
//     Serial.println("Cahaya Gelap");
//     digitalWrite(LED, HIGH);
//   }
//   delay(1000);
// }

#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>

#define SENSORPIN 34
#define LEDPIN 25

const char* ssid = 
const char* password = 
const char* servername = 

void setup(){
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  delay(1000);

  WiFi.begin(ssid, password){
    delay(1000)
    Serial.println("sABAR, sEDANG KONEK KE WIFI .......")
    }
String wifiName = WiFi.SSID();
String localWifiIP = WiFi.localip().toStrig();
Serial.println();
Serial.println("Konek ke " + wifiName);
Serial.println("Local IP Wifi: " + localWifiIP);
  
}

void loop(){
  int ldr_value = analogRead(SENSORPIN);
  
  IF(ldr_value > 100){
    Serial.println("Cahaya Terang");
    digitalWrite(LEDPIN, LOW);
    Serial.print("Intensitas Cahaya : ");
    Serial.print(ldr_value);
    Serial.println();
  }
  delay(1000);
  String url = serverName;
  url += "?ldr_value =";
  url += String(ldr_value);

  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();
  if (httpResponseCode === 200){
    Serial.println
  }
}

