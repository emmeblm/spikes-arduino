#include <SoftwareSerial.h>
#define LED 13
#define RxD 10
#define TxD 11

char input;
SoftwareSerial bluetooth(RxD, TxD);

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  bluetooth.begin(115200);
  bluetooth.println("Bluetooth conectado.");
}

void loop() {
  if (bluetooth.available() > 0) {
    
    input = bluetooth.read();
    switch(input) {
      case '0':
        digitalWrite(LED,LOW);
        bluetooth.println("Led off");
        break;
      case '1':
        digitalWrite(LED,HIGH);
        bluetooth.println("Led on");
        break;
      default:
        bluetooth.println("Orden valida. Introduzca 0 o 1.");
     }
     
     bluetooth.flush();
  }
}
