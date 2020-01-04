int lp=2,ln=4;
int rp=5 ,rn=7;
int irl=A2,irc=A3,irr=A4;
int a,b,c;
int e=3,f=6;


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
// WHEELS
pinMode(lp,OUTPUT);
pinMode(ln,OUTPUT);
pinMode(rp,OUTPUT);
pinMode(rn,OUTPUT);
//SENSOR PIN
pinMode(A2,INPUT);   
pinMode(A3,INPUT);
pinMode(A4,INPUT);
//speed
pinMode(3,255);
pinMode(6,255);
}

void loop() {
  // put your main code here, to run repeatedly:
a=analogRead(A2);
b=analogRead(A3);
c=analogRead(A4);
analogWrite(3,255);
analogWrite(6,255);
if(b>900) //move staright
{
 digitalWrite(lp,1);
 digitalWrite(ln,0); 
  digitalWrite(rp,1);
  digitalWrite(rn,0);
  }
else if(a>900) //move left
{
 digitalWrite(lp,1);
 digitalWrite(ln,0); 
  digitalWrite(rp,0);
  digitalWrite(rn,0);
  }
else if(c>900) //move right
{
 digitalWrite(lp,0);
 digitalWrite(ln,0); 
  digitalWrite(rp,1);
  digitalWrite(rn,0);
  }
 else if (a>900==b>900==c>900) //stop
 {
 digitalWrite(lp,0);
 digitalWrite(ln,0); 
  digitalWrite(rp,0);
  digitalWrite(rn,0);
   
 }
}
