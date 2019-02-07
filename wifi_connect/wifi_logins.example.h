// Wifi logins.

// SSID 32 chars may be too long
// http://forum.arduino.cc/index.php?topic=295728.0

struct Wifi {
  const char* ssid;
  const char* password;
};

Wifi hyperoptic = { "my-ssid-1", "my-password" };
Wifi sky = { "my-ssid-2", "my-password" };
Wifi lyv = { "my-ssid-3", "my-password" };

