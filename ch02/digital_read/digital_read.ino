// Import required libraries
#include <ESP8266WiFi.h>

void setup(void)
{
  // Start Serial (to display results on the Serial monitor)
  Serial.begin(115200);

  // Set GPIO 5 as input
  pinMode(D5, INPUT);
}

void loop() {

  // Read GPIO 5 and print it on Serial port
  Serial.print("State of GPIO D5: ");
  Serial.println(digitalRead(D5));

  // Wait 1 second
  delay(1000);
}
