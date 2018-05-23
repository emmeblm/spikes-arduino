/*
 MedidorDistancia.h - Libreria para la lectura de un sensor de distancia
 ultrasonico.
 Creado por Luisa Emme, Julio 2015.
*/

#include <Arduino.h>
#include <MedidorDistancia.h>

MedidorDistancia::MedidorDistancia(int pin_echo, int pin_trig)
{
  pinMode(pin_echo, OUTPUT);
  pinMode(pin_trig, INPUT);
  _pinEcho = pin_echo;
  _pinTrig = pin_trig;
}

float MedidorDistancia::read()
{
  float distancia;
  long tiempo;

  digitalWrite(_pinEcho, LOW);
  delayMicroseconds(5);
  digitalWrite(_pinEcho, HIGH);
  delayMicroseconds(10);
  tiempo = pulseIn(_pinTrig, HIGH);
  distancia = tiempo/58;

  return distancia;
}
