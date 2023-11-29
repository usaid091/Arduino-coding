
  int Count_limit = 0; // declare count limit variable to zero

int IR_Sensor_INPUT = A0; //E18*D80NK IR Infrared Sensor input pin to Arduino pin A0

long int counter = 0; // Set counter variable to 0

long int RELAY = 0;

int hitObject = false;

int Buzzer = 9; // Positive pin of Buzzer to Arduino pin 9

int Set_Reset_Button = A1; // Button to reset the count value to Arduino pin A1

int UP_button = A2; // Button to count up to Arduino pin A2

int Down_button = A3; // Button to count Down to Arduino pin A3

int Set_Reset_Button_State= 1;

int Up_Button_State = 1;

int Down_Button_State = 0;

int ssr = 8; // Amnode pin of the LED to Arduino pin 8

int RELAY_1 = 7; // Amnode pin of the LED to Arduino pin 8

#include "LedControl.h" // include the Led display library:

LedControl lc=LedControl(12,11,10,1);// initialize the library with the numbers of the interface pins

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

#include <EEPROM.h> // include the EEPROM library to store last count even after power loose

int addr = 0; //Set EEPROM Address to zero

void setup() {

pinMode(Set_Reset_Button, INPUT_PULLUP); // SET PUSH Button as input

pinMode(UP_button, INPUT_PULLUP); // UP PUSH Button as input

pinMode(Down_button, INPUT_PULLUP); //DOWN PUSH Button as input

pinMode(Buzzer, OUTPUT); // Buzzer as output
pinMode(RELAY_1, OUTPUT); // LED as output

pinMode(ssr, OUTPUT); // LED as output

lc.shutdown(0,false);

lc.setIntensity(0,8);

lc.clearDisplay(0);

Serial.begin(9600);

pinMode(IR_Sensor_INPUT,INPUT_PULLUP); // IR sensor as INPUT(Used inbuilt pullup resister using program)
  lcd.begin();
  // Print a message to the LCD.
  lcd.backlight();

// ###Print follwing details to the LCD at the start###//

lcd.print("********************");

lcd.setCursor(0,1);

lcd.print("*GATRON INDUSTRIES*");

lcd.setCursor(0,2);

lcd.print("     *LIMITED*   ");

lcd.setCursor(0,3);

lcd.print("********************");
lcd.setCursor(0,4);
delay(2000);
lcd.clear();
lcd.print("********************");

lcd.setCursor(0,1);

lcd.print("**PREFORMS COUNTER**");

lcd.setCursor(0,2);

lcd.print("     *SYSTEM*   ");

lcd.setCursor(0,3);

lcd.print("********************");
lcd.setCursor(0,4);
delay(2000);
lcd.clear();
lcd.print("********************");

lcd.setCursor(0,1);

lcd.print("**** DESIGNED BY ***");

lcd.setCursor(0,2);

lcd.print("***SYED USAID ALI***");

lcd.setCursor(0,3);

lcd.print("********************");
lcd.setCursor(0,4);
delay(2000);
lcd.clear();

//Trun on Buzzer and off after 200ms delay//

digitalWrite(Buzzer, HIGH);

delay(400);

digitalWrite(Buzzer, LOW);

delay(1000);

lcd.clear();

lcd.setCursor(0,0);

lcd.print("last count was:");

lcd.setCursor(0,1);

lcd.print(EEPROM.read(addr));// show the previous count

delay(2000);

set_count_limit(); //cal set_count function

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Preform Count:");

lcd.setCursor(0,1);

lcd.print(counter); // show counter value

led_display(counter);

}

void loop() {
counter_();
counter = 0;// call counter

led_display(counter);

digitalWrite(Buzzer, LOW);

lcd.clear();

lcd.setCursor(0,0);

lcd.print("last count was:");

lcd.setCursor(0,1);

lcd.print(EEPROM.read(addr));

delay(2000);

Set_Reset_Button_State = LOW;

//digitalWrite(RELAY, HIGH);

set_count_limit();

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Object Count:");

lcd.setCursor(0,1);

lcd.print(counter);

led_display(counter);

RELAY_();
counter = 0;
led_display(counter);

digitalWrite(Buzzer, LOW);

lcd.clear();

lcd.setCursor(0,0);

lcd.print("last count was:");

lcd.setCursor(0,1);

lcd.print(EEPROM.read(addr));

delay(2000);

Set_Reset_Button_State = LOW;

//digitalWrite(RELAY, HIGH);

set_count_limit();

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Object Count:");

lcd.setCursor(0,1);

lcd.print(counter);

led_display(counter);
}

void counter_(){

while(1){

digitalWrite(RELAY_1, 0);
lcd.setCursor(0,3);

lcd.print("SET RST");

Set_Reset_Button_State= digitalRead(Set_Reset_Button); // read the reset button sate(LOW or HIGH)

Down_Button_State = digitalRead(Down_button); // read the DOWN button sate(LOW or HIGH)

Up_Button_State = digitalRead(UP_button); // read the UP button sate(LOW or HIGH)

if(Set_Reset_Button_State== HIGH){ // This if loop will be executed if the SET button is HIGH

lcd.setCursor(0,1);

digitalWrite(ssr, HIGH);

int val = digitalRead(IR_Sensor_INPUT); // read the IR_Sensor

if( (val == 0) && (hitObject == false) ){ // this code will execute when object in range

counter++;

hitObject = true;

EEPROM.write(addr, counter); // store the count value in EEPROM

Serial.print("Counter = ");

lcd.print(counter);

led_display(counter);

if(counter == Count_limit){ // this loop will be executed once the count reach the count limit

digitalWrite(Buzzer, HIGH); // buzzer ON 30 sec
delay(400);
lcd.setCursor(0,2);

lcd.print("  R.Cnt Lmt Reached");

digitalWrite(ssr, LOW);
//##################################################
delay(2000);
//digitalWrite(RELAY_1, 1);
//delay(1500);
digitalWrite(Buzzer, LOW);

//##################################################
//Set_Reset_Button_State= digitalRead(Set_Reset_Button); // read the reset button sate(LOW or HIGH

delay(1000);
lcd.setCursor(0,2);
lcd.print(" ");
break;
}
else{

digitalWrite(Buzzer, HIGH);

delay(20);

digitalWrite(Buzzer, LOW);

lcd.setCursor(0,2);


}

}

else if( (val ==1) && (hitObject == true) ){ // this code will execute when object is not in range

hitObject = false;

}

}

else if (Set_Reset_Button_State== LOW){ // this code will execute when reset button pressed

counter = 0;

digitalWrite(Buzzer, HIGH);

delay(200);

digitalWrite(Buzzer, LOW);

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Object Count:");

lcd.setCursor(0,1);

lcd.print(counter);

led_display(counter);

}

if(Down_Button_State == LOW){ // Count set loop will be executed once down button is pressed.

digitalWrite(ssr, LOW);
digitalWrite(Buzzer, HIGH);

delay(70);

digitalWrite(Buzzer, LOW);

lcd.clear();

lcd.setCursor(0,0);

lcd.print("last count was:");

lcd.setCursor(0,1);

lcd.print(EEPROM.read(addr));

delay(800);

set_count_limit(); // call set count limit

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Object Count:");

lcd.setCursor(0,1);

counter = 0;

lcd.print(counter);

led_display(counter);

}
}

}///// END

void RELAY_(){

while(1){

digitalWrite(ssr, 0);
lcd.setCursor(0,3);

lcd.print("SET RST");

Set_Reset_Button_State= digitalRead(Set_Reset_Button); // read the reset button sate(LOW or HIGH)

Down_Button_State = digitalRead(Down_button); // read the DOWN button sate(LOW or HIGH)

Up_Button_State = digitalRead(UP_button); // read the UP button sate(LOW or HIGH)

if(Set_Reset_Button_State== HIGH){ // This if loop will be executed if the SET button is HIGH

lcd.setCursor(0,1);

digitalWrite(RELAY_1, HIGH);

int val = digitalRead(IR_Sensor_INPUT); // read the IR_Sensor

if( (val == 0) && (hitObject == false) ){ // this code will execute when object in range

counter++;

hitObject = true;

EEPROM.write(addr, counter); // store the count value in EEPROM

Serial.print("Counter = ");

lcd.print(counter);

led_display(counter);

if(counter == Count_limit){ // this loop will be executed once the count reach the count limit

digitalWrite(Buzzer, HIGH); // buzzer ON 30 sec
delay(400);
lcd.setCursor(0,2);

lcd.print(" L.Cnt Lmt Reached");

digitalWrite(RELAY_1, LOW);
//##################################################
delay(2000);
//digitalWrite(RELAY_1, 1);
//delay(1500);
digitalWrite(Buzzer, LOW);

delay(1000);
lcd.setCursor(0,2);
lcd.print(" ");
break;
}
else{

digitalWrite(Buzzer, HIGH);

delay(20);

digitalWrite(Buzzer, LOW);

lcd.setCursor(0,2);


}

}

else if( (val ==1) && (hitObject == true) ){ // this code will execute when object is not in range

hitObject = false;

}

}

else if (Set_Reset_Button_State== LOW){ // this code will execute when reset button pressed

counter = 0;

digitalWrite(Buzzer, HIGH);

delay(200);

digitalWrite(Buzzer, LOW);

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Object Count:");

lcd.setCursor(0,1);

lcd.print(counter);

led_display(counter);

}

if(Down_Button_State == LOW){ // Count set loop will be executed once down button is pressed.

digitalWrite(RELAY_1, LOW);
digitalWrite(Buzzer, HIGH);

delay(70);

digitalWrite(Buzzer, LOW);

lcd.clear();

lcd.setCursor(0,0);

lcd.print("last count was:");

lcd.setCursor(0,1);

lcd.print(EEPROM.read(addr));

delay(800);

set_count_limit(); // call set count limit

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Object Count:");

lcd.setCursor(0,1);

counter = 0;

lcd.print(counter);

led_display(counter);

}
}
}



///////////////////////////////////////////////////////
///new functon/////

int set_count_limit() //defined the count limit set function here.

{
counter=0;
//RELAY=0;

//led_display();

while (Set_Reset_Button_State == HIGH)

{

Set_Reset_Button_State= digitalRead(Set_Reset_Button);

Up_Button_State = digitalRead(UP_button);

Down_Button_State = digitalRead(Down_button);

lcd.clear();

lcd.setCursor(0,0);

lcd.print("SET THE COUNTER");

lcd.setCursor(0,1);

lcd.print("Count Limit:");

lcd.setCursor(0,2);

lcd.print(Count_limit);

lcd.setCursor(0,3);

lcd.print("DOWN UP SET");

delay(50);

if (Up_Button_State == LOW) //Increase the count Limit

{

Count_limit++;

lcd.setCursor(0,2);

lcd.print(Count_limit);

digitalWrite(Buzzer, HIGH);

delay(70);

digitalWrite(Buzzer, LOW);

}

else if(Down_Button_State == LOW) //Decrese the count Limit


{ if (Count_limit > 0)

{

Count_limit--;

lcd.setCursor(0,2);

lcd.print(Count_limit);

digitalWrite(Buzzer, HIGH);

delay(70);

digitalWrite(Buzzer, LOW);

}

}

}

digitalWrite(Buzzer, HIGH);

delay(70);

digitalWrite(Buzzer, LOW);

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Count Limit Set:");

if(Count_limit==0){ // if the count limit is zero then the counter set infinite limit

lcd.print("infinity");

}else{

lcd.setCursor(0,1);

lcd.print(Count_limit);

}

delay(3000);

}

void led_display(int v){ // led display function

int ones;
  int tens;
  int hundreds;
  int thousands;
  int sepuluhribu;
  int seratusribu;
  int satujuta;
  int sepuluhjuta;
  
  if(v < 10000000){
    ones=v%10;
    v=v/10;
    tens=v%10;
    v=v/10;
    hundreds=v%10;
    v=v/10;
    thousands=v;        

    //Now print the number digit by digit
    lc.setDigit(0,7,(byte)sepuluhjuta,false);
    lc.setDigit(0,6,(byte)satujuta,false);
    lc.setDigit(0,5,(byte)seratusribu,false);
    lc.setDigit(0,4,(byte)sepuluhribu,false);
    lc.setDigit(0,3,(byte)thousands,false);
    lc.setDigit(0,2,(byte)hundreds,false);
    lc.setDigit(0,1,(byte)tens,false);
    lc.setDigit(0,0,(byte)ones,false);
  } 
  else{
    lc.setChar(0,0,'E',false);
  }  }
