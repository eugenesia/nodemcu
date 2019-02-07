// Import required libraries
#include <ESP8266WiFi.h>
#include "wifi_logins.h"

WifiLogin wifi = lyv;

// Lolin NodeMCU uses GPIO2 for LED.
// https://arduino.stackexchange.com/questions/38477/does-the-node-mcu-v3-lolin-not-have-a-builtin-led
// LED_BUILTIN has already been set to 2 - no need to redefine.
// #define LED_BUILTIN 2

void setup(void)
{
  // Setup LED to blink to show it's alive
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Start Serial
  // Serial only works at 9600 baud according to instructions under board
  Serial.begin(9600);
  // Connect to WiFi
  WiFi.begin(wifi.ssid, wifi.password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    Serial.print(WiFi.status());
    blink();
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  blink();
}

void blink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
