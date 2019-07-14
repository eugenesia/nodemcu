// LED on LoLin NodeMCU v3 is GPIO2
// https://arduino.stackexchange.com/questions/38477/does-the-node-mcu-v3-lolin-not-have-a-builtin-led
#define LED_OUT 2

void setup() {
  pinMode(LED_OUT, OUTPUT);
}
 
void loop() {
  digitalWrite(LED_OUT, HIGH);
  delay(1000);
  digitalWrite(LED_OUT, LOW);
  delay(1000);
}
