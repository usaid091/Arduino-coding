const int motionpin=A0;
const int ledpin=12;
const int buzzpin=13; // ledpin,motionpin and buzpin are not changed throughout the process
int motionsensvalue=0;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin, OUTPUT);
pinMode(motionpin,INPUT);
pinMode(buzzpin,OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly:
motionsensvalue=analogRead(motionpin); // reads analog data from motion sensor
if (motionsensvalue>=200){
digitalWrite(ledpin,HIGH);
tone(buzzpin,100); //turns on led and buzzer
}
else {
digitalWrite(ledpin,LOW); //turns led off led and buzzer
noTone(buzzpin);
}
}
