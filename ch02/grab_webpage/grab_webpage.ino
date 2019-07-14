// Import required libraries
#include <ESP8266WiFi.h>

// WiFi parameters
const char *ssid = "QEKN Hyperoptic 2.4Ghz 1";
const char *password = "";

// Host
const char *host = "www.example.com";

void setup() {
  // Start serial
  Serial.begin(115200);

  // We start by connecting to a wifi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {
  Serial.print("Connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (! client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // This will send the request to the server
  client.print(String("GET /") + " HTTP/1.1\r\n" +
    "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  delay(1000);

  // Read all the lines of the reply from server and print them to Serial
  while(client.available()) {
    // See https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/client-examples.html#read-reply-from-the-server
    String line = client.readStringUntil('\r');
    Serial.println(line);
  }

  Serial.println();
  Serial.println("closing connection");
  delay(5000);
}
