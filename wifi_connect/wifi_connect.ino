// Import required libraries
#include <ESP8266WiFi.h>
#include "wifi_logins.h"

WifiLogin wifi = hyperoptic;

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

  char *statusStr;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('\n');
    statusStr = wifiStatusStr(WiFi.status());
    Serial.print(statusStr);
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

// WL definitions from https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266WiFi/src/include/wl_definitions.h
/*
    WL_NO_SHIELD        = 255,   // for compatibility with WiFi Shield library
    WL_IDLE_STATUS      = 0,
    WL_NO_SSID_AVAIL    = 1,
    WL_SCAN_COMPLETED   = 2,
    WL_CONNECTED        = 3,
    WL_CONNECT_FAILED   = 4,
    WL_CONNECTION_LOST  = 5,
    WL_DISCONNECTED     = 6
*/
char *wifiStatusStr(int statusCode) {
  switch(statusCode) {
    case 255:
      return "WL_NO_SHIELD";
    case 0:
      return "WL_IDLE_STATUS";
    case 1:
      return "WL_NO_SSID_AVAIL";
    case 2:
      return "WL_SCAN_COMPLETED";
    case 3:
      return "WL_CONNECTED";
    case 4:
      return "WL_CONNECT_FAILED";
    case 5:
      return "WL_CONNECTION_LOST";
    case 6:
      return "WL_DISCONNECTED";
  }
  char statusStr[2];
  itoa(statusCode, statusStr, 10);
  return statusStr;
}
