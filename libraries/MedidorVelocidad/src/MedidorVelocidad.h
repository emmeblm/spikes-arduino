/*
 MedidorVelocidad.h - Libreria para la lectura de un sensor de velocidad
 hall en un ventilador de pc.
 Creado por Luisa Emme, Julio 2015.
*/

#ifndef MedidorVelocidad_h
#define MedidorVelocidad_h
#include <Arduino.h>

const int INTERRUPT[][2] = {{2, 0}, {3, 1}};

class MedidorVelocidad
{
  public:
    MedidorVelocidad(int pin_control, int pin_lectura);
    float read();
    void changeSpeed(int speed);
  private:
    int _pinControl;
    int _pinLectura;
};

#endif
