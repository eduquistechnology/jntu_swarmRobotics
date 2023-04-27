#include <ESP8266WiFi.h>

// WiFi credentials
const char* ssid = "MyNetwork"; // replace with your desired WiFi network name
const char* password = "MyPassword"; // replace with your desired WiFi network password

// IP address of the other NodeMCU
IPAddress remoteIP(192, 168, 4, 2); // replace with the IP address of the other NodeMCU

// UDP port number
unsigned int localPort = 8888; // replace with any number between 0 and 65535

// Create UDP object
WiFiUDP udp;

void setup() {
  // Connect to WiFi network
  Serial.begin(9600);
  WiFi.softAP(ssid, password);
  Serial.println("WiFi AP created.");

  // Begin UDP communication
  udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(udp.localPort());
}

void loop() {
  // Send data to the other NodeMCU
  udp.beginPacket(remoteIP, localPort);
  udp.write("Hello, NodeMCU 2!");
  udp.endPacket();
  Serial.println("Sent data to NodeMCU 2.");

  // Receive data from the other NodeMCU
  char packetBuffer[255];
  int packetSize = udp.parsePacket();
  if (packetSize) {
    int len = udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = '\0';
      Serial.print("Received data from NodeMCU 2: ");
      Serial.println(packetBuffer);
    }
  }

  // Wait for a moment before repeating the loop
  delay(1000);
}
