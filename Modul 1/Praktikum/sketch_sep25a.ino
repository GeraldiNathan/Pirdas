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

const int switchPin = 15;
const int ledPin = 14;

int switchState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  switchState = digitalRead(switchPin);
  if (switchState == HIGH){
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

