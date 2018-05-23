#include <SoftwareSerial.h>
#define RxD 9
#define TxD 8

SoftwareSerial BluetoothMaestroSerial(RxD, TxD);

void setup() {
    BluetoothMaestroSerial.begin(38400);
    delay(500);
    BluetoothMaestroSerial.flush();
    delay(500);
    
    Serial.begin(9600);
    Serial.println("Modo AT:");
}

void loop() {
  if (BluetoothMaestroSerial.available()) {
    Serial.write(BluetoothMaestroSerial.read());
  }
  if (Serial.available()) {
    BluetoothMaestroSerial.write(Serial.read());
  }
}
