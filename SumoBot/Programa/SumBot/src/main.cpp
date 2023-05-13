#include <Arduino.h>

// Conexiones
int ai1 = 2;
int ai2 = 3;
int bi1 = 4;
int bi2 = 5;
int LED = 13;
int sensor_distancia_izquierda = A1;
int sensor_distancia_derecha = A0;
int sensor_linea_izquierda = A2;
int sensor_linea_derecho = A3;
// Variables
int lectura_linea_derecha = 0;
int lectura_linea_izquierda = 0;
int lectura_izquierda = 0;
int lectura_derecha = 0;
// Inicialización
void setup()
{
  Serial.begin(9600);
  pinMode(ai1, OUTPUT);
  pinMode(ai2, OUTPUT);
  pinMode(bi1, OUTPUT);
  pinMode(bi2, OUTPUT);
}
void adelante()
{
  digitalWrite(ai1, HIGH);
  digitalWrite(ai2, LOW);
  digitalWrite(bi1, HIGH);
  digitalWrite(bi2, LOW);
}
void derecha()
{
  digitalWrite(ai1, LOW);
  digitalWrite(ai2, HIGH);
  digitalWrite(bi1, HIGH);
  digitalWrite(bi2, LOW);
}
void izquierda()
{
  digitalWrite(ai1, HIGH);
  digitalWrite(ai2, LOW);
  digitalWrite(bi1, LOW);
  digitalWrite(bi2, HIGH);
}
void reversa()
{
  digitalWrite(ai1, LOW);
  digitalWrite(ai2, HIGH);
  digitalWrite(bi1, LOW);
  digitalWrite(bi2, HIGH);
}
void detener()
{
  digitalWrite(ai1, LOW);
  digitalWrite(ai2, LOW);
  digitalWrite(bi1, LOW);
  digitalWrite(bi2, LOW);
}
// Rutina
void loop()
{
  lectura_linea_izquierda = analogRead(sensor_linea_izquierda); // Lectura del sensor de línea izquierdo
  lectura_linea_derecha = analogRead(sensor_linea_derecho);   // Lectura del sensor de línea derecho
  // Con este código eliminamos el ruido que pueda haber en las lecturas del sensor.
  lectura_izquierda = analogRead(sensor_distancia_izquierda);
  lectura_derecha = analogRead(sensor_distancia_derecha);

  // ¡Detección de línea por el lado izquierdo!
  if (lectura_linea_izquierda < 30)
  {
    reversa();
    delay(500);
    derecha();
    delay(100);
    adelante();
  }
  // ¡Detección de línea por el lado derecho!
  if (lectura_linea_derecha < 30)
  {
    reversa();
    delay(500);
    izquierda();
    delay(100);
    adelante();
  }
  // ¡Detección de objeto por el lado izquierdo!
  if (lectura_izquierda > 200 && lectura_izquierda <= 1000)
  {
    izquierda();
    delay(1000);
    adelante();
  }
  // ¡Detección de objeto por el lado derecho!
  if (lectura_derecha >= 210 && lectura_derecha <= 600)
  {
    derecha();
    delay(1000);
    adelante();
  }
}
