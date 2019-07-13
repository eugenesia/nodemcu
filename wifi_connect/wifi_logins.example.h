// Wifi logins.

// SSID 32 chars may be too long
// http://forum.arduino.cc/index.php?topic=295728.0
//
// In ESP8266 code for Arduino
// #define WL_SSID_MAX_LENGTH 32
// https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266WiFi/src/include/wl_definitions.h#L30

struct WifiLogin {
  const char* ssid;
  const char* password;
};

WifiLogin hyperoptic = { "my-ssid-1", "my-password" };
WifiLogin sky = { "my-ssid-2", "my-password" };
WifiLogin lyv = { "my-ssid-3", "my-password" };
