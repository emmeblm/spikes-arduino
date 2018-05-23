/*
 MedidorVelocidad.h - Libreria para la lectura de un sensor de velocidad
 hall en un ventilador de pc.
 Creado por Luisa Emme, Julio 2015.
*/

#include <Arduino.h>
#include <MedidorVelocidad.h>

volatile int _nbTopsFan;

static void rpmFun()
{
  _nbTopsFan++;
}

MedidorVelocidad::MedidorVelocidad(int pin_control, int pin_lectura)
{
  pinMode(pin_control, OUTPUT);
  pinMode(pin_lectura, INPUT);
  _pinControl = pin_control;
  _pinLectura = pin_lectura;
  _nbTopsFan = 0;
  attachInterrupt(INTERRUPT[pin_lectura][1], rpmFun, RISING);
}

float MedidorVelocidad::read()
{
  _nbTopsFan = 0;
  int rpm = ((_nbTopsFan * 60)/2);
  int velocidadAngular = (rpm*6.283183)/60;
  int velocidadLineal = velocidadAngular*0.00385;

  return velocidadLineal;
}

void MedidorVelocidad::changeSpeed(int speed)
{
  analogWrite(_pinControl, speed);
}
