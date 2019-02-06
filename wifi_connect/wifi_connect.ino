// Import required libraries
#include <ESP8266WiFi.h>

// WiFi parameters
// SSID 32 chars may be too long
// http://forum.arduino.cc/index.php?topic=295728.0
// const char* ssid = "QEKN Hyperoptic 1Gb Fibre 2.4GHz";
// const char* password = "";

// const char* ssid = "SKY";
// const char* password = "";

const char* ssid = "LY";
const char* password = "";

// Lolin NodeMCU uses GPIO2 for LED.
#define LED_OUT 2

void setup(void)
{
  // Setup LED to blink to show it's alive
  pinMode(LED_OUT, OUTPUT);
  
  // Start Serial
  // Serial only works at 9600 baud according to instructions under board
  Serial.begin(9600);
  // Connect to WiFi
  WiFi.begin(ssid, password);
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
  digitalWrite(LED_OUT, HIGH);
  delay(1000);
  digitalWrite(LED_OUT, LOW);
  delay(1000);
}
