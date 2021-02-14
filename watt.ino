#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

 //Default Arduino LCD Librarey is included 

int Read_Voltage  = A3;
int Read_Current  = A2;


void setup() {
  lcd.begin(16, 2); //Initialise 16*2 LCD
  lcd.backlight();

  lcd.print(" Arduino Wattmeter"); //Intro Message line 1
  lcd.setCursor(0, 1);
  lcd.print("  With Arduino  "); //Intro Message line 2

  delay(2000);
  lcd.clear();

}

void loop() {
 
 float Voltage_Value = analogRead(Read_Voltage);
 float Current_Value = analogRead(Read_Current);

 Voltage_Value = Voltage_Value * (5.0/1023.0) * 6.46;
 Current_Value = Current_Value * (5.0/1023.0) * 0.239;

 lcd.setCursor(0, 0);
 lcd.print("V="); lcd.print(Voltage_Value); 
 lcd.print("  "); 
 lcd.print("I=");lcd.print(Current_Value); 

 float Power_Value = Voltage_Value * Current_Value;

 lcd.setCursor(0, 1);
 lcd.print("Power="); lcd.print(Power_Value); 

 
delay(200);
}
