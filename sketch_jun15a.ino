#include <Servo.h>             //Servo library
 
Servo servo;        //initialize a servo object for the connected servo  
                
int angle = 0;
int startbutton=12;
int stopbutton=10;    
 
void setup() 
{ 
  servo.attach(3);      // attach the signal pin of servo to pin3 of arduino
  pinMode(startbutton,INPUT); //START BUTTON
  pinMode(stopbutton,INPUT); //STOP BUTTON
  Serial.begin(9600);
} 
  
void loop() 
{ 
  if (digitalRead(startbutton)==HIGH ){
    Serial.println("inside start button ");
    while(digitalRead(stopbutton)==LOW){
      
    Serial.println("inside stop button ");
      for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo.write(angle);                 //command to rotate the servo to the specified angle
    delay(10);                       
 
  delay(10); //change the speed
  
  for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo.write(angle);              //command to rotate the servo to the specified angle
    delay(10);                       
  } 

    delay(10);//change the speed
      }
    }
    
}
