#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define triacPulse 4 //D2
#define ZVC 12 //D6

int Slider_Value;
int dimming;
int x = 0;

char auth[] = "ga5OcaMaThfYcZpwB3qTuy27JvYJIQ6R";        // You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon) in the Blynk app or check your email for auth token.

char ssid[] = "CYBER-NET Amir :) 0334-1893169";         // Your WiFi credentials.
char pass[] = "Facebook201";    // Set password to "" for open networks.


BLYNK_WRITE(V1)   // function to assign value to variable Slider_Value whenever slider changes position
{
  Slider_Value = param.asInt(); // assigning incoming value from pin V1 to a variable
}


void setup()
{

  pinMode(ZVC, INPUT_PULLUP);
  //digitalWrite(2, INPUT_PULLUP); // pull up
  pinMode(triacPulse, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  attachInterrupt(digitalPinToInterrupt(ZVC), acon, FALLING); // attach Interrupt at PIN2
}



void loop()
{
  Blynk.run();
  // When the switch is closed
  dimming = map(Slider_Value, 0, 100, 7200
  , 200); //0.2ms 7.2 ms

}

void acon()
{
  // Serial.println("REad");

  delayMicroseconds(dimming); // read AD0
  digitalWrite(triacPulse, HIGH);

  delayMicroseconds(50);  //delay 50 uSec on output pulse to turn on triac
  digitalWrite(triacPulse, LOW);

  // Serial.println(digitalRead(triacPulse));
}
