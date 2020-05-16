const int trigPin = 9;
const int echoPin = 10;
const int relay=12;
const int pot=A0;
int reading_from_pot;

// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(relay,OUTPUT);
pinMode(pot,INPUT);  
Serial.begin(9600);
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
///Serial.println(distance);
int reading=analogRead(reading_from_pot);
//Serial.println(reading);
unsigned int seconds=map(reading,0,1020,1,60);
Serial.println(seconds);
unsigned int final_seconds=seconds*1000;
 Serial.println(final_seconds);
 delay(1000);

if (distance<=100){
  Serial.println(final_seconds);
  digitalWrite(relay,LOW);//PUMP ON
  delay(seconds); 
  }
 else{
 digitalWrite(relay,HIGH);//PUMP OFF
    }
  reading=0 ;
}
