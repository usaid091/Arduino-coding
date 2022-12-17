int pin7=9;           //Direction control pins
int pin8=10;           //Direction control pins
#define potentiometer  A0
#define bt_F A1
#define M1_Ena 11
int read_ADC =0;
int duty_cycle;
int set = 0;

void setup(){
pinMode(bt_F, INPUT_PULLUP);
pinMode(potentiometer, INPUT);
pinMode(M1_Ena, OUTPUT);
pinMode(pin7,OUTPUT); //Arduino Pin#7 as Output 
pinMode(pin8,OUTPUT); //Arduino Pin#8 as Output 
}

void loop(){
read_ADC = analogRead(potentiometer);
duty_cycle = map(read_ADC, 0, 1023, 0, 255);   

analogWrite(M1_Ena, duty_cycle);

if(digitalRead (bt_F) == 0){set = 1;}

if(set==1){

digitalWrite(pin7,HIGH);   //Pin#7 as High
digitalWrite(pin8,LOW);    //Pin#8 as Low
delay(4000);               //Delay 4 seconds Motor rotates in clock wise direction
digitalWrite(pin7,LOW);    //Pin#7 as Low
digitalWrite(pin8,LOW);    //Pin#8 as Low 
delay(3000);               //Delay 3 seconds Motor halts
digitalWrite(pin8,HIGH);   //Pin#8 as High
digitalWrite(pin7,LOW);    //Pin#7 as Low
delay(4000);               //Delay for 4 seconds Motor rotates in anti clock wise direction
digitalWrite(pin7,LOW);    //Pin#7 as Low
digitalWrite(pin8,LOW);    //Pin#8 as Low
delay(2000);               //Delay for 2 seconds Motor halts
}
}
