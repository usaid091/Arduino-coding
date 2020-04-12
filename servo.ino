#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;

char auth[] = "RvWMQSEPv4M9ldict1fFYNuKGx4TNxbm"; //  your auth code 
char ssid[] = "Guest.Net";  // ssid name 
char pass[] = "Pakistan123"; // ssid password 

  void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  servo.attach(2); // NodeMCU D4 pin
  
 }
  
void loop()
{
  
  Blynk.run();
  
}
BLYNK_WRITE(V1)
{
   servo.write(param.asInt());
}
