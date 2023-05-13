#include <Arduino.h>

int LED = 13;
int lectura_linea_1;
int lectura_linea_2;
void setup() {
pinMode(LED,OUTPUT);
Serial.begin(9600);
}
void loop() {
delay(100);
lectura_linea_1 = analogRead(A2);
lectura_linea_2 = analogRead(A3);
Serial.println(lectura_linea_1);
Serial.println(lectura_linea_2);
if(lectura_linea_1 < 30 || lectura_linea_2 < 30)
digitalWrite(LED,HIGH);
else
digitalWrite(LED,LOW);
}