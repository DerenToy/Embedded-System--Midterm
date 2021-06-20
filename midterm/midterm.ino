#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX,TX
String nameUno = "DEREN UNO";
int password = 1412;
String uart = "9600,0,0";

const int trig = 2;
const int echo = 3;
const int buzzer = 9;

float duration,cm;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
  
  mySerial.begin(38400);
  delay(5000);
  mySerial.print("AT+NAME=");
  mySerial.println(nameUno);
  Serial.print("The name has been set: ");
  Serial.println(nameUno);
  delay(1000);
  mySerial.print("AT+PSWD=");
  mySerial.println(password);
  Serial.print("The password has been set: ");
  Serial.println(password);
  delay(1000);
  mySerial.print("AT+UART=");
  mySerial.println(uart);
  Serial.print("The baud rate has been set: ");
  Serial.println(uart);
  delay(2000);
  Serial.println("Process completed.");
  
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  cm = (duration / 2) / 29.1;

 Serial.print("Distance:");
  Serial.print(cm);
  Serial.print("cm");
  delay(100);
  Serial.println();

  if (cm <= 10) {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(90);
  }
  else if (cm <= 20) {
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(150);
  }
  else if (cm <= 30) {
    digitalWrite(buzzer, HIGH);
    delay(350);
    digitalWrite(buzzer, LOW);
    delay(250);
  }
  else if (cm <= 40) {
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(450);
  }
  else if (cm <= 50) {
    digitalWrite(buzzer, HIGH);
    delay(750);
    digitalWrite(buzzer, LOW);
  }
  else {
     
  }  
}
