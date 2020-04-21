int pbuttonPin = 2;// connect output to push button
int relayPin = 10;// Connected to relay (LED)

int val = 0; // push value from pin 2
int lightON = 0;//light status
int pushed = 0;//push status


void setup() {
  Serial.begin(9600);
  pinMode(pbuttonPin, INPUT_PULLUP); 
  pinMode(relayPin, OUTPUT);
 digitalWrite(relayPin, HIGH);// keep the load OFF at the begining. If you wanted to be ON, change the HIGH to LOW
}

void loop() {
// E-innovators tutorial for relay with arduino.
  val = digitalRead(pbuttonPin);// read the push button value

  if(val == HIGH && lightON == LOW){

    pushed = 1-pushed;
    delay(100);
  }    

  lightON = val;

      if(pushed == HIGH){
        Serial.println("Light ON");
        digitalWrite(relayPin, LOW); 
       
      }else{
        Serial.println("Light OFF");
        digitalWrite(relayPin, HIGH);
        }     
delay(100);
}
