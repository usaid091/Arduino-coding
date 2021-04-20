#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7,8); // CE, CSN         
const byte address[6] = "00001";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.
int button_pin = 9;
int a;
//String button_state ;
void setup() {
pinMode(button_pin, INPUT_PULLUP);
radio.begin();                  //Starting the Wireless communication
radio.openWritingPipe(address); //Setting the address where we will send the data
radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
radio.stopListening();          //This sets the module as transmitter
}
void loop()
{
 
if(digitalRead(button_pin) == LOW)
{ a =1;
/*const char text[20] = "Your Button State is HIGH";
button_state ="LOW";
radio.write(&text, sizeof(text)); //Sending the message to receiver*/
radio.write(&a, sizeof(a));
}
else{
  a = 0;
  radio.write(&a, sizeof(a));
}
delay(500);

 }
