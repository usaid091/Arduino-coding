#include <EEPROM.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long startTime = 0;
long duration, inches;
int set_val,percentage;
bool state,pump;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  Serial.println("WATER LEVEL:");
  lcd.setCursor(0, 1); 
 Serial.println("ALERT!!:OFF MANUAL");
  
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  
  
   set_val=EEPROM.read(0);
   if(set_val>150)set_val=150;
}
void loop() {
  
   digitalWrite(2, HIGH);
   delayMicroseconds(10);
   digitalWrite(2, LOW);
   duration = pulseIn(3, HIGH);
   inches = microsecondsToInches(duration);
   
   percentage=(set_val-inches)*100/set_val;
   
   lcd.setCursor(12, 0); 
   if(percentage<0)percentage=0;
   Serial.print(percentage);
   Serial.print("%   ");
    
   if(percentage<40&digitalRead(11))pump=1;
   if(percentage>75)pump=0;
   digitalWrite(13,!pump);

   if(millis() - startTime >= 1000) { // If 2 seconds have passed
    digitalWrite(9,pump); // Set the LED off permanently
  } else {
    digitalWrite(9, HIGH); // Set the LED on
  }

   {digitalWrite(9,pump);
   delay(1400);
   digitalWrite(9,1);
   }
  
 
  
     
   lcd.setCursor(5, 1);
   if(pump==1)Serial.print("LOW");
   else if(pump==0) Serial.print("FULL");
   
   lcd.setCursor(9, 1);
   if(!digitalRead(11))
   Serial.println("MANUAL");
   else 
   Serial.println("LEVEL");
    
    if(!digitalRead(10)&!state&digitalRead(11)){
      state=1;
      set_val=inches;
      EEPROM.write(0, set_val);
      }
      
     if(!digitalRead(10)&!state&!digitalRead(11)){
        state=1;
        pump=!pump;
     
      }
      
    if(digitalRead(10))state=0;
      
    
    delay(500);
}
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
