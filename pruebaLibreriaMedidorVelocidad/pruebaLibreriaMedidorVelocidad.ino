#include <MedidorVelocidad.h>

#define POTENCIOMETRO A0

MedidorVelocidad medidorVelocidad(3, 2);
int velocidadPwm;

void setup() {
  pinMode(POTENCIOMETRO, INPUT);

}

void loop() {
  int velocidad = analogRead(POTENCIOMETRO);
  calcularPwm(velocidad);
  medidorVelocidad.changeSpeed(velocidadPwm);
  medidorVelocidad.read();
  delay(2000);
}

void calcularPwm(int velocidad) {
  velocidadPwm = velocidad / 4;
  if(velocidadPwm < 15 ) {
    velocidadPwm = 0;
  } else if(velocidadPwm > 255) {
    velocidadPwm = 255;
  }
}
