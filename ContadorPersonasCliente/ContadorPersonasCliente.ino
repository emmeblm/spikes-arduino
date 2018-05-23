#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server(10,71,22,204); // IP Roberto
IPAddress ip(10,71,23,100); //Red de la oficina 10.71.20.0 255.255.252.0
EthernetClient client;

void setup() {
  Serial.begin(9600);

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);
  }
  delay(1000);
  Serial.println("connecting...");

  // puerto 3000 servidor contador de personas
  if (client.connect(server, 3000)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.println("HTTP/1.1 200 OK /contador/personas/");
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } 
  else {
    Serial.println("connection failed");
  }
}

void loop()
{
  // if there are incoming bytes available 
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    // do nothing forevermore:
    while(true);
  }
}
