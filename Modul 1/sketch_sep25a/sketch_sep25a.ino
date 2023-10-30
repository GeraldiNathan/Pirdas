// // #define LED_BUILTIN 2

// // void setup() {
// //   // put your setup code here, to run once:
// //   pinMode(LED_BUILTIN, OUTPUT);
// // }

// // void loop() {
// //   // put your main code here, to run repeatedly:
// //   digitalWrite(LED_BUILTIN, HIGH);
// //   delay(1000);
// //   digitalWrite(LED_BUILTIN, LOW);
// //   delay(1000);
// // }

// const int switchPin = 15;
// const int ledPin = 14;

// int switchState = 0;

// void setup() {
//   Serial.begin(115200);
//   pinMode(switchPin, INPUT);
//   pinMode(ledPin, OUTPUT);
// }

// void loop() {
//   //pantek
//   switchState = digitalRead(switchPin);
//   if (switchState == HIGH){
//     digitalWrite(ledPin, HIGH);
//     delay(500);
//     digitalWrite(ledPin, LOW);
//     delay(500);
//     // digitalWrite(ledPin, HIGH);
//     // delay(500);
//     // digitalWrite(ledPin, LOW);
//     // delay(500);
//     // digitalWrite(ledPin, HIGH);
//     // delay(500);
//     // digitalWrite(ledPin, LOW);
//     // delay(500);
//     // digitalWrite(ledPin, HIGH);
//     // delay(500);
//     // digitalWrite(ledPin, LOW);
//     // delay(500);
//   } else {
//     digitalWrite(ledPin, LOW);
//   }
// }

// Modul 3

// Codelab
// #include <MPU6050_tockn.h>
// #include <Wire.h>
// #include <WiFi.h>

// MPU6050 mpu6050(Wire);
// const char* ssid = "Geleriee";
// const char* password = "12345678";

// void setup(){
//   Serial.begin(9600);
//   Wire.begin();
//   WiFi.begin(ssid, password);
//   mpu6050.begin();
//   mpu6050.calcGyroOffsets();
  
//   while (WiFi.status() != WL_CONNECTED){
//     delay(1000);
//     Serial.println("Lagi Nyambungin Ke Wifi");
//   }
//   Serial.println("Dah Nyambung");
// }

// void loop(){
//   mpu6050.update();
//   Serial.print("Anglex :"); 
//   Serial.println(mpu6050.getAngleX());
//   Serial.print("\nangleY :");
//   Serial.println(mpu6050.getAngleY());
//   Serial.print("\nanglez :");
//   Serial.println(mpu6050.getAngleZ());
//   delay(200);
// } 

