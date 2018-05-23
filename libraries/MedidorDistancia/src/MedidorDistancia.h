/*
 MedidorDistancia.h - Libreria para la lectura de un sensor de distancia
 ultrasonico.
 Creado por Luisa Emme, Julio 2015.
*/

#ifndef MedidorDistancia_h
#define MedidorDistancia_h
#include <Arduino.h>

class MedidorDistancia
{
  public:
    MedidorDistancia(int pin_echo, int pin_trig);
    float read();
  private:
    int _pinEcho;
    int _pinTrig;
};

#endif
