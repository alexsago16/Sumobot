#include <Arduino.h>

// Conexiones
int sensor_distancia_1 = A1;
// Inicialización
int lectura = 0;
void setup() {
Serial.begin(9600);
Serial.println("Iniciando lectura de sensor");
}
// Programa
void loop() {
lectura = analogRead(sensor_distancia_1);
Serial.println(lectura);
delay(2000);
}