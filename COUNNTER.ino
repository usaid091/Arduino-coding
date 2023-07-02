/* ---------Coding ini di buat untuk belajar  
 *  boleh di modifikasi asal tetap memcantumkan pembuat
 *  salam ngoprek NGAPAK TECH
 *  original code by TexoOBOT
 *  
 *  
 *  SUBSCRIBE NGAPAK TECH 
 *  bantu saya supaya channelnya berkembang agar bisa Share project project menarik lainnya
   */
  
  int Count_limit = 0; // declare count limit variable to zero

int IR_Sensor_INPUT = A0; //E18*D80NK IR Infrared Sensor input pin to Arduino pin A0

long int counter = 0; // Set counter variable to 0

int hitObject = false;

int Buzzer = 9; // Positive pin of Buzzer to Arduino pin 9

int Set_Reset_Button = A1; // Button to reset the count value to Arduino pin A1

int UP_button = A2; // Button to count up to Arduino pin A2

int Down_button = A3; // Button to count Down to Arduino pin A3

int Set_Reset_Button_State= 1;

int Up_Button_State = 1;

int Down_Button_State = 0;

int RELAY = 8; // Amnode pin of the LED to Arduino pin 8

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

pinMode(RELAY, OUTPUT); // LED as output

lc.shutdown(0,false);

lc.setIntensity(0,8);

lc.clearDisplay(0);

Serial.begin(9600);

pinMode(IR_Sensor_INPUT,INPUT_PULLUP); // IR sensor as INPUT(Used inbuilt pullup resister using program)
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

// ###Print follwing details to the LCD at the start###//

lcd.print("****************");

lcd.setCursor(0,1);

lcd.print("*Object Counter*");

lcd.setCursor(0,2);

lcd.print("* *");

lcd.setCursor(0,3);

lcd.print("****************");

//Trun on Buzzer and off after 200ms delay//

digitalWrite(Buzzer, HIGH);

delay(200);

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

lcd.print("Object Count:");

lcd.setCursor(0,1);

lcd.print(counter); // show counter value

led_display(counter);

}

void loop() {

counter_(); // call counter

counter = 0;

led_display(counter);

digitalWrite(Buzzer, LOW);

lcd.clear();

lcd.setCursor(0,0);

lcd.print("last count was:");

lcd.setCursor(0,1);

lcd.print(EEPROM.read(addr));

delay(2000);

Set_Reset_Button_State = HIGH;

set_count_limit();

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Object Count:");

lcd.setCursor(0,1);

lcd.print(counter);

led_display(counter);

// lcd.clear();

// lcd.setCursor(0,0);

// lcd.print("Object Count:");

// lcd.setCursor(0,1);

// lcd.print(counter);

}

void counter_(){

while(1){

lcd.setCursor(0,3);

lcd.print("SET RST");

Set_Reset_Button_State= digitalRead(Set_Reset_Button); // read the reset button sate(LOW or HIGH)

Down_Button_State = digitalRead(Down_button); // read the DOWN button sate(LOW or HIGH)

Up_Button_State = digitalRead(UP_button); // read the UP button sate(LOW or HIGH)

if(Set_Reset_Button_State== HIGH){ // This if loop will be executed if the SET button is HIGH

lcd.setCursor(0,1);

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
delay(100);
digitalWrite(RELAY, HIGH);
lcd.setCursor(0,2);

lcd.print("    Cnt Lmt Reached!");


//lcd.setCursor(0,3);

//lcd.print(" RST");

for (int i =0; i<150; i++){ // LED will blink for 30 sec

Set_Reset_Button_State= digitalRead(Set_Reset_Button); // read the reset button sate(LOW or HIGH)

if (Set_Reset_Button_State== LOW){ //this loop will be executed if the SET button is LOW else stay count limit reached

Set_Reset_Button_State = HIGH;

return;

}else{


}

}

delay(10);

digitalWrite(Buzzer, LOW);
delay(1000);
lcd.setCursor(0,2);

lcd.print("                      ");


//lcd.print(" RST");

delay(100);/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

counter = 0;
delay(2000);
digitalWrite(RELAY, LOW);
//digitalWrite(LED,HIGH);

//delay(1000);

//digitalWrite(LED,LOW);

//(1000);

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

int set_count_limit() //defined the count limit set function here.

{

counter=0;

//led_display();

while (Set_Reset_Button_State == HIGH)

{

Set_Reset_Button_State= digitalRead(Set_Reset_Button);

Up_Button_State = digitalRead(UP_button);

Down_Button_State = digitalRead(Down_button);

lcd.clear();

lcd.setCursor(0,0);

lcd.print("SET THE COUNT!");

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
