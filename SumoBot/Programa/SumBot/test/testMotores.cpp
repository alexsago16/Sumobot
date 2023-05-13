#include <Arduino.h>

// Conexiones
int ai1 = 2;
int ai2 = 3;
int bi1 = 4;
int bi2 = 5;
int LED = 13;

void setup()
{
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
void retroceso()
{
    digitalWrite(ai1, LOW);
    digitalWrite(ai2, HIGH);
    digitalWrite(bi1, LOW);
    digitalWrite(bi2, HIGH);
}
void loop()
{
    // adelante();
    // derecha();
    // izquierda();
    retroceso();
}