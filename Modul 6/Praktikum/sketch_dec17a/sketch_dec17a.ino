#include <Wire.h>
#include <MPU6050_tockn.h>
#include <HTTPClient.h>
#include <WiFi.h>

const char* ssid = "aezakmi";
const char* password = "12345678";
// const char* serverName = "http://172.20.10.2/pirdas-modul6/insert_database.php/";
// const char* apiKey = "d7af46c2-a29e-4f00-aeef-4e7555d8b5de";
MPU6050 mpu6050(Wire);

String serverName = "http://192.168.117.198:8070/";  // Ganti dengan URL server Anda
String path = "/";

int ldr_value = 123;  // Ganti dengan nilai ldr yang sesuai

int LED_PIN = 32; 
int BUZZER_PIN = 14; 

void setup() {
  Serial.begin(9600); 
  Wire.begin();
  mpu6050.begin();
  connectToWiFi();
  // Ethernet.begin(mac);  // Replace "mac" with your Ethernet shield's MAC address

  ledcSetup(0, 5000, 8);
  ledcAttachPin(LED_PIN, 0); 

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  mpu6050.update();
  Serial.print("Angle X: ");
  float angleX = mpu6050.getAngleX();
  float angleY = mpu6050.getAngleY();
  float angleZ = mpu6050.getAngleZ();

  int buzS = 0;
  int ledS = 0;
  int t = 0;   

  // Print the values to Serial Monitor
  Serial.print("Angle X: ");
  Serial.print(angleX);
  Serial.print("\tAngle Y: ");
  Serial.println(angleY);

  if (mpu6050.getAngleX() > 20 && mpu6050.getAngleY() > 20 || mpu6050.getAngleX() < -10 && mpu6050.getAngleY() < -10) {
    ledcWrite(0, 255);
    digitalWrite(LED_PIN, LOW); // LED off
    tone(BUZZER_PIN, 1000, 1000);
    buzS = 1;
    t = 1;
    Serial.println("Bidang tidak datar!");
  } else {
    ledcWrite(0, 0);
    digitalWrite(LED_PIN, HIGH);  // LED on
    ledS = 1;
    noTone(BUZZER_PIN);
    Serial.println("Bidang datar!");
    
  }

  sendDataToServer(angleX, angleY, angleZ, buzS, ledS, t );
  

  delay(1000); 
}

void sendDataToServer(float xValue, float yValue, float zValue, float bzValue, float ledValue, float tValue) {
  // String url = serverName + "/your_endpoint";  // Ganti "/your_endpoint" dengan endpoint atau path yang sesuai di server

  HTTPClient http;
  http.begin(serverName);

  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

 // Create the URL-encoded data string
  String data = "x=" + String(xValue) +
                "&y=" + String(yValue) +
                "&z=" + String(zValue) +
                "&bz=" + String(bzValue) +
                "&led=" + String(ledValue) +
                "&t=" + String(tValue);

  Serial.println(data);

  
  // Make a POST request
  int httpResponseCode = http.POST(data);

   // Print the server response
  // Atur header untuk metode POST dan konten tipe aplikasi/x-www-form-urlencoded
  // http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  // Buat payload POST data
  // String postData = "ldr_value=" + String(ldr_value);

  // Lakukan metode POST dengan payload data
  // int httpResponseCode = http.POST(postData);

  // Periksa respon dari server
  if (httpResponseCode == 201) {
    Serial.println("Data sent successfully!");
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  // Hentikan sesi HTTP
  http.end();
}

void connectToWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi....");
  }
  Serial.println("Connected to WiFi");
  Serial.println("Local IP: " + WiFi.localIP().toString());
}