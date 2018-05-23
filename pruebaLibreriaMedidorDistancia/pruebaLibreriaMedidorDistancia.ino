#include <MedidorDistancia.h>

MedidorDistancia medidorDistancia(8, 7);
float distancia;

void setup() {
  Serial.begin(9600);
}

void loop() {
  distancia = medidorDistancia.read();
  Serial.println(distancia);
}
