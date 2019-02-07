// Wifi logins.

// SSID 32 chars may be too long
// http://forum.arduino.cc/index.php?topic=295728.0

struct WifiLogin {
  const char* ssid;
  const char* password;
};

WifiLogin hyperoptic = { "my-ssid-1", "my-password" };
WifiLogin sky = { "my-ssid-2", "my-password" };
WifiLogin lyv = { "my-ssid-3", "my-password" };

