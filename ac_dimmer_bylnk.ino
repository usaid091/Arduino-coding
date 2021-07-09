/*
   This is the code for AC Dimmer using Arduino Board.
   To watch it's full tutorial video, head on to my YouTube Channel
   http://www.youtube.com/techiesms
*/


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define triacPulse 4 //D2
#define ZVC 5 //D6

int Slider_Value;
int dimming;
int x = 0;

char auth[] = "DI_Ro9TrEIUvToMhUL7gW0JzU_rBCDhn";        // You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon) in the Blynk app or check your email for auth token.

char ssid[] = "Coderatoty (Air-OS)";         // Your WiFi credentials.
char pass[] = "q1werty6068";    // Set password to "" for open networks.

void acon();

void ICACHE_RAM_ATTR acon()
{
  // Serial.println("REad");

  delayMicroseconds(dimming); // read AD0
  digitalWrite(triacPulse, HIGH);

  delayMicroseconds(50);  //delay 50 uSec on output pulse to turn on triac
  digitalWrite(triacPulse, LOW);

  // Serial.println(digitalRead(triacPulse));
}

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

  Serial.println(Slider_Value);
  dimming = map(Slider_Value, 0, 100, 7200, 200); //0.2ms 7.2 ms
}
