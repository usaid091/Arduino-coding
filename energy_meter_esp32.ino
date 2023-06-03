#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "EmonLib.h"
#include <EEPROM.h>
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
 
EnergyMonitor emon;
#define vCalibration 83.3
#define currCalibration 0.50
 
BlynkTimer timer;
char auth[] = "oP6G4KQuwZafjfBJJJeDrvOFXvAmk5bi";
char ssid[] = "OPPO A96";
char pass[] = "u7jpvd9x";
 
float kWh = 0;
unsigned long lastmillis = millis();
 
void myTimerEvent()
{
  emon.calcVI(20, 2000);
  kWh = kWh + emon.apparentPower * (millis() - lastmillis) / 3600000000.0;
  yield();
  Serial.print("Vrms: ");
  Serial.print(emon.Vrms, 2);
  Serial.print("V");
 
  Serial.print("\tIrms: ");
  Serial.print(emon.Irms, 4);
  Serial.print("A");
 
  Serial.print("\tPower: ");
  Serial.print(emon.apparentPower, 4);
  Serial.print("W");
 
  Serial.print("\tkWh: ");
  Serial.print(kWh, 5);
  Serial.println("kWh");
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vrms:");
  lcd.print(emon.Vrms, 2);
  lcd.print("V");
  lcd.setCursor(0, 1);
  lcd.print("Irms:");
  lcd.print(emon.Irms, 4);
  lcd.print("A");
  delay(2500);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Power:");
  lcd.print(emon.apparentPower, 4);
  lcd.print("W");
  lcd.setCursor(0, 1);
  lcd.print("kWh:");
  lcd.print(kWh, 4);
  lcd.print("W");
  delay(2500);
 
  lastmillis = millis();
 
  Blynk.virtualWrite(V0, emon.Vrms);
  Blynk.virtualWrite(V1, emon.Irms);
  Blynk.virtualWrite(V2, emon.apparentPower);
  Blynk.virtualWrite(V3, kWh);
}
 
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  lcd.init();
  lcd.backlight();
  emon.voltage(35, vCalibration, 1.7);  // Voltage: input pin, calibration, phase_shift
  emon.current(34, currCalibration);    // Current: input pin, calibration.
 
  timer.setInterval(5000L, myTimerEvent);
  lcd.setCursor(3, 0);
  lcd.print("IoT Energy");
  lcd.setCursor(5, 1);
  lcd.print("Meter");
  delay(3000);
  lcd.clear();
}
 
void loop()
{
  Blynk.run();
  timer.run();
}
