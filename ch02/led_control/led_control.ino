// Import required libraries
#include <ESP8266WiFi.h>

void setup() {

  // Set GPIO D5 as output
  // NodeMCU needs pin targeted using D5 instead of 5
  // See https://tttapa.github.io/ESP8266/Chap04%20-%20Microcontroller.html
  pinMode(D5, OUTPUT);
}
void loop() {
  digitalWrite(D5, LOW);
  delay(1000);

  digitalWrite(D5, HIGH);
  delay(1000);
}
