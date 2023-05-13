#include <Arduino.h>

// Conexiones
// Conexiones
int ai1 = 2;
int ai2 = 3;
int bi1 = 4;
int bi2 = 5;
int LED = 13;
int sensor_distancia_izquierda = A1;
int sensor_distancia_derecha = A0;


// Inicialización
int lectura_izquierda = 0;
int lectura_derecha = 0;

void setup()
{
    Serial.begin(9600);
    Serial.println("Iniciando lectura de sensores");
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

void loop()
{
    lectura_izquierda = analogRead(sensor_distancia_izquierda);
    lectura_derecha = analogRead(sensor_distancia_derecha);

    if (lectura_izquierda >= 200  && lectura_izquierda <= 1000)
    {
        izquierda();
        delay(1000);
        adelante();
    }

    if (lectura_derecha >= 210 && lectura_derecha <= 600)
    {
        derecha();
        delay(1000);
        adelante();
    }

    delay(1000);
}
