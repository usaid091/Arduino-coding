/*
This is code for LCD1602 Display with I2C module
 * watch the video for this code https://youtu.be/q9YC_GVHy5A
 
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * This library is based on work done by DFROBOT (www.dfrobot.com).
 */
/*
 *  This code has been modefied from the Arduino library
 *  Updated by Ahmad Nejrabi on Jan 20, 2018 at 11:09
 *  in Ajax, Ontario, Canada
 *  for Robojax.com
 *  
 *  This is code for LCD1602 Display with I2C module
 *  which can display text on the screen.
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // Robojax code for LCD with I2C
  // initialize the LCD, 
  lcd.begin();
 
  // Turn on the blacklight and print a message.
  lcd.backlight();
  // Robojax code for LCD with I2C


}

void loop()
{
  
  //start of loop Robojax code for LCD with I2C
  lcd.clear();
  lcd.print("      HELLO      ");
  lcd.setCursor (0,1); // go to start of 2nd line
 lcd.print("    IC TESTER   ");
  //lcd.print(millis() / 1000);
  delay(5000);
 //end of loopcode Robojax code for LCD with I2C
}
