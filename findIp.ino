#include <ESP8266WiFi.h>

const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Code here
}
