#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);
void setup()
{
// lcd.init();  
 lcd.begin();
lcd.backlight();
  lcd.setCursor(0,0) ;
  lcd.print(" ***LOGIC IC*** ");
    lcd.setCursor(0,1) ;
  lcd.print("    TESTER ");
  delay(2000);for (int positionCounter = 0; positionCounter < 15; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
  lcd.clear();
    for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
  
   lcd.scrollDisplayRight();
    lcd.setCursor(0,0);
    lcd.print("GROUP MEMBERS");
    delay(100);
  }
  lcd.clear();
for (int positionCounter = 0; positionCounter < 17; positionCounter++) {
    lcd.setCursor(0,0);
    lcd.print("AMMAD");
    lcd.setCursor(0,1);
    lcd.print("18B-036-EE");
    lcd.scrollDisplayRight();
    delay(200);
  }
  lcd.clear();
for (int positionCounter = 0; positionCounter < 17; positionCounter++) {
    lcd.setCursor(0,0);
    lcd.print("USAID");
    lcd.setCursor(0,1);
    lcd.print("18B-022-EE");
    lcd.scrollDisplayRight();
    delay(200);
  }
   lcd.clear();
for (int positionCounter = 0; positionCounter < 17; positionCounter++) {
    lcd.setCursor(0,0);
    lcd.print("QUNBER");
    lcd.setCursor(0,1);
    lcd.print("18B-008-PE");
    lcd.scrollDisplayRight();
    delay(200);
  } 
   lcd.clear();
for (int positionCounter = 0; positionCounter < 17; positionCounter++) {
    lcd.setCursor(0,0);
    lcd.print("SADDAR");
    lcd.setCursor(0,1);
    lcd.print("18B-068-EE");
    lcd.scrollDisplayRight();
    delay(200);
  } 
  Serial.begin(9600);

pinMode(7,OUTPUT);///FOR BUTTON TO START TESTING
  
}/*PIN CONFIGRATION IN ARDUNIO MEGA
22     34->VCC FOR 14 PIN IC 
23     28
24     29
25     30
26     31
27     32     
35->GND33
37     34
38     35
39     36
*/
void loop()
{
 bool READ=digitalRead(7);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("ENTER START");
 lcd.setCursor(0,1);
 lcd.print("BUTTON");
 delay(250);
  if (READ == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("TESTING.....");
    delay(500);      
    if (NAND()==true){
      displaylcd("NAND 7400");
      }
    else if(XOR()==true){
      displaylcd("XOR 7486");
      }    
    else if(NAND_3()==true){
      displaylcd("NAND 3 7410");
      }
    else if(AND()==true){
      displaylcd("AND 7408");
      }
         else if(NOR()==true){
      displaylcd("NOR 7402");
      } 
       else if(OR()==true){
      displaylcd("OR 7432");
      }
      else if (NOT()== true){
        displaylcd("NOT 7404");
        }
        else if (XNOR()==true){
          displaylcd("XNOR 74266");
          }
      else{
        lcd.clear();
        while(digitalRead(7)==0 ){
        lcd.setCursor(0,0);
        lcd.print("IC FAIL NOT");
        lcd.setCursor(0,1);
        lcd.print("FOUND");
        }
        }
        delay(500);    
  ////TTHE VCC AND THE GNG ARE GIVEN AT PIN NO 34 (VCC)AND PIN 35 IS GND

    }
}

bool AND(){
  {
    pin_3();
  int gate_clear=0;
  int gate_fail=0;
  int gate_fail_pin[4];
  int add=0;
  //first gate/ //7408
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate1;
  int p3=3;
   digitalWrite(22,1);
   digitalWrite(23,1);
  if( digitalRead(24)==1){/// first gate clear
    gate_clear++;
    digitalWrite(22,0);
   digitalWrite(23,1);
   if(digitalRead(24)==0){
    gate_clear++;
    digitalWrite(22,0);
   digitalWrite(23,0);
   if (digitalRead(24)==0){
    Serial.println("AND GATE 1 CLEAR PIN 1,2,3");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////first gate not clear
    gate_fail++;
    Serial.println("First gate not clear 1,2,3");
   }
   if (gate_fail>0){
    gate1=false;
      
      gate_fail_pin[add]=p3;
    add++;
}
    else{
    gate1=true;
    }
///checking of gate one ended
//Second gate/ //7408
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate2;
  p3=6;
   digitalWrite(25,1);
   digitalWrite(26,1);
  if( digitalRead(27)==1){/// 2nd gate clear
    gate_clear++;
    digitalWrite(25,0);
   digitalWrite(26,1);
   if(digitalRead(27)==0){
    gate_clear++;
    digitalWrite(25,0);
   digitalWrite(26,0);
   if (digitalRead(27)==0){
    Serial.println("AND GATE 2 CLEAR PIN 4,5,6");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////2nd gate not clear
    gate_fail++;
    Serial.println("AND GATE 2 not clear PIN 4,5,6");
   }
   if (gate_fail>0){
    gate2=false;
    
    gate_fail_pin[add]=p3;
    add++;
    }
    else{
    gate2=true;
    }
//third gate/ //7408
  //pin number
  p3=11;
    gate_fail=0;
  gate_clear=0;
  bool gate3;
   digitalWrite(28,1);
   digitalWrite(29,1);
  if( digitalRead(30)==1){/// 3rd gate clear
    gate_clear++;
    digitalWrite(28,0);
   digitalWrite(29,1);
    if(digitalRead(30)==0){
    gate_clear++;
    digitalWrite(28,0);
   digitalWrite(29,0);
   if (digitalRead(30)==0){
    Serial.println("AND GATE 3 CLEAR PIN 13,12,11");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////3rd gate not clear
    gate_fail++;
    Serial.println("3rd gate not clear 13,12,11");
   }
   if (gate_fail>0){
    gate3=false;
    gate_fail_pin[add]=p3;
add++;
    }
    else{
    gate3=true;
    }
///checking of gate 3rd ended
    
//4th gate/ //7408
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate4;
  p3=8;
   digitalWrite(31,1);
   digitalWrite(32,1);
  if( digitalRead(33)==1){/// 4th gate clear
    gate_clear++;
    digitalWrite(31,0);
   digitalWrite(32,1);
   if(digitalRead(33)==0){
    gate_clear++;
    digitalWrite(31,0);
   digitalWrite(32,0);
     if (digitalRead(33)==0){
    Serial.println("AND GATE 4 CLEAR PIN 10,9,8");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
 
    }
    
   else{  ////4th gate not clear
    gate_fail++;
    Serial.println("4th gate not clear 10,9,8");
   }
   if (gate_fail>0){
    gate4=false;
    gate_fail_pin[add]=p3;
    add++;
}
    if (gate_clear>0){
   gate4=true;
    }///checking of gate 4th ended

if (gate1==true && gate2==true && gate3==true &&gate4==true){
  Serial.println("AND PASSES TEST");
  return true;
}else if(add==4){
  Serial.println("And gate test Fail");
  return false;
}
  
    }

  
  
  }

 bool OR(){
  {
    pin_3();
    
  int gate_clear=0;
  int gate_fail=0;
  int gate_fail_pin[4];
  int add=0;
  //first gate/ //7432
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate1;
  int p3=3;
   digitalWrite(22,1);
   digitalWrite(23,1);
  if( digitalRead(24)==1){/// first gate clear
    gate_clear++;
    digitalWrite(22,0);
   digitalWrite(23,1);
   if(digitalRead(24)==1){
    gate_clear++;
    digitalWrite(22,0);
   digitalWrite(23,0);
   if (digitalRead(24)==0){
    Serial.println("OR GATE 1 CLEAR PIN 1,2,3");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////first gate not clear
    gate_fail++;
    Serial.println("First gate not clear 1,2,3");
   }
   if (gate_fail>0){
    gate1=false;
      
      gate_fail_pin[add]=p3;
    add++;
}
    else{
    gate1=true;
    }
///checking of gate one ended
//Second gate/ //7432
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate2;
  p3=6;
   digitalWrite(25,1);
   digitalWrite(26,1);
  if( digitalRead(27)==1){/// 2nd gate clear
    gate_clear++;
    digitalWrite(25,0);
   digitalWrite(26,1);
   if(digitalRead(27)==1){
    gate_clear++;
    digitalWrite(25,0);
   digitalWrite(26,0);
   if (digitalRead(27)==0){
    Serial.println("OR GATE 2 CLEAR PIN 4,5,6");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////2nd gate not clear
    gate_fail++;
    Serial.println("OR GATE 2 not clear PIN 4,5,6");
   }
   if (gate_fail>0){
    gate2=false;
    
    gate_fail_pin[add]=p3;
    add++;
    }
    else{
    gate2=true;
    }
//third gate/ //7432
  //pin number
  p3=11;
    gate_fail=0;
  gate_clear=0;
  bool gate3;
   digitalWrite(28,1);
   digitalWrite(29,1);
  if( digitalRead(30)==1){/// 3rd gate clear
    gate_clear++;
    digitalWrite(28,0);
   digitalWrite(29,1);
    if(digitalRead(30)==1){
    gate_clear++;
    digitalWrite(28,0);
   digitalWrite(29,0);
   if (digitalRead(30)==0){
    Serial.println("OR GATE 3 CLEAR PIN 13,12,11");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////3rd gate not clear
    gate_fail++;
    Serial.println("3rd gate not clear 13,12,11");
   }
   if (gate_fail>0){
    gate3=false;
    gate_fail_pin[add]=p3;
add++;
    }
    else{
    gate3=true;
    }
///checking of gate 3rd ended
    
//4th gate/ //7432
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate4;
  p3=8;
   digitalWrite(31,1);
   digitalWrite(32,1);
  if( digitalRead(33)==1){/// 4th gate clear
    gate_clear++;
    digitalWrite(31,0);
   digitalWrite(32,1);
   if(digitalRead(33)==1){
    gate_clear++;
    digitalWrite(31,0);
   digitalWrite(32,0);
     if (digitalRead(33)==0){
    Serial.println("OR GATE 4 CLEAR PIN 10,9,8");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
 
    }
    
   else{  ////4th gate not clear
    gate_fail++;
    Serial.println("4th gate not clear 10,9,8");
   }
   if (gate_fail>0){
    gate4=false;
    gate_fail_pin[add]=p3;
    add++;
}
    if (gate_clear>0){
   gate4=true;
    }///checking of gate 4th ended

if (gate1==true && gate2==true && gate3==true &&gate4==true){
  Serial.println("OR PASSES TEST");
  return true;
}else if(add==4){
  Serial.println("OR gate test Fail");
   return false;
}
  else{
        Serial.println("list of fault gate pin");
         return false;
         for (int i=0;i<add;i++){
          Serial.println(gate_fail_pin[i]);
          }
    }}}
    
  bool NOR(){
    pin_1();
  int gate_clear=0;
  int gate_fail=0;
  int gate_fail_pin[4];
  int add=0;
  //first gate/ //7402
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate1;
  int p3=1;
   digitalWrite(23,1);
   digitalWrite(24,1);
  if( digitalRead(22)==0){/// first gate clear
    gate_clear++;
    digitalWrite(23,0);
   digitalWrite(24,1);
   if(digitalRead(22)==0){
    gate_clear++;
    digitalWrite(23,0);
   digitalWrite(24,0);
   if (digitalRead(22)==1){
    Serial.println("NOR GATE 1 CLEAR PIN 1,2,3");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////first gate not clear
    gate_fail++;
    Serial.println("First gate not clear 1,2,3");
   }
   if (gate_fail>0){
    gate1=false;
      
      gate_fail_pin[add]=p3;
    add++;
}
    else{
    gate1=true;
    }
///checking of gate one ended
//Second gate/ //7402
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate2;
  p3=4;
   digitalWrite(26,1);
   digitalWrite(27,1);
  if( digitalRead(25)==0){/// 2nd gate clear
    gate_clear++;
    digitalWrite(26,0);
   digitalWrite(27,1);
   if(digitalRead(25)==0){
    gate_clear++;
    digitalWrite(26,0);
   digitalWrite(27,0);
   if (digitalRead(25)==1){
    Serial.println("NOR GATE 2 CLEAR PIN 4,5,6");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////2nd gate not clear
    gate_fail++;
    Serial.println("NOR GATE 2 not clear PIN 4,5,6");
   }
   if (gate_fail>0){
    gate2=false;
    
    gate_fail_pin[add]=p3;
    add++;
    }
    else{
    gate2=true;
    }
//third gate/ //7402
  //pin number
  p3=11;
    gate_fail=0;
  gate_clear=0;
  bool gate3;
   digitalWrite(29,1);
   digitalWrite(30,1);
  if( digitalRead(28)==0){/// 3rd gate clear
    gate_clear++;
    digitalWrite(29,0);
   digitalWrite(30,1);
    if(digitalRead(28)==0){
    gate_clear++;
    digitalWrite(29,0);
   digitalWrite(30,0);
   if (digitalRead(28)==1){
    Serial.println("NOR GATE 3 CLEAR PIN 13,12,11");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////3rd gate not clear
    gate_fail++;
    Serial.println("3rd gate not clear 13,12,11");
   }
   if (gate_fail>0){
    gate3=false;
    gate_fail_pin[add]=p3;
add++;
    }
    else{
    gate3=true;
    }
///checking of gate 3rd ended
    
//4th gate/ //7402
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate4;
  p3=10;
   digitalWrite(32,1);
   digitalWrite(33,1);
  if( digitalRead(31)==0){/// 4th gate clear
    gate_clear++;
    digitalWrite(32,0);
   digitalWrite(33,1);
   if(digitalRead(31)==0){
    gate_clear++;
    digitalWrite(32,0);
   digitalWrite(33,0);
     if (digitalRead(31)==1){
    Serial.println("NOR GATE 4 CLEAR PIN 10,9,8");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
 
    }
    
   else{  ////4th gate not clear
    gate_fail++;
    Serial.println("4th gate not clear 10,9,8");
   }
   if (gate_fail>0){
    gate4=false;
    gate_fail_pin[add]=p3;
    add++;
}
    if (gate_clear>0){
   gate4=true;
    }///checking of gate 4th ended

if (gate1==true && gate2==true && gate3==true &&gate4==true){
  Serial.println("NOR PASSES TEST");
  return true;
}else if(add==4){
  Serial.println("NOR gate test Fail");
  return false;
}
  else{
        Serial.println("list of fault gate pin");
         return false;
         for (int i=0;i<add;i++){
          Serial.println(gate_fail_pin[i]);
          }
    }
    }

bool NAND(){
  {

    pin_3();
    digitalWrite(34,1);
digitalWrite(35,0);
  int gate_clear=0;
  int gate_fail=0;
  int gate_fail_pin[4];
  int add=0;
  //first gate/ //7400
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate1;
  int p3=3;
   digitalWrite(22,1);
   digitalWrite(23,1);
  if( digitalRead(24)==0){/// first gate clear
    gate_clear++;
    digitalWrite(22,0);
   digitalWrite(23,1);
   if(digitalRead(24)==1){
    gate_clear++;
    digitalWrite(22,0);
   digitalWrite(23,0);
   if (digitalRead(24)==1){
    Serial.println("NAND GATE 1 CLEAR PIN 1,2,3");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////first gate not clear
    gate_fail++;
    Serial.println("First gate not clear 1,2,3");
   }
   if (gate_fail>0){
    gate1=false;
      
      gate_fail_pin[add]=p3;
    add++;
}
    else{
    gate1=true;
    }
///checking of gate one ended
//Second gate/ //7408
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate2;
  p3=6;
   digitalWrite(25,1);
   digitalWrite(26,1);
  if( digitalRead(27)==0){/// 2nd gate clear
    gate_clear++;
    digitalWrite(25,0);
   digitalWrite(26,1);
   if(digitalRead(27)==1){
    gate_clear++;
    digitalWrite(25,0);
   digitalWrite(26,0);
   if (digitalRead(27)==1){
    Serial.println("NAND GATE 2 CLEAR PIN 4,5,6");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////2nd gate not clear
    gate_fail++;
    Serial.println("NAND GATE 2 not clear PIN 4,5,6");
   }
   if (gate_fail>0){
    gate2=false;
    
    gate_fail_pin[add]=p3;
    add++;
    }
    else{
    gate2=true;
    }
//third gate/ //7408
  //pin number
  p3=11;
    gate_fail=0;
  gate_clear=0;
  bool gate3;
   digitalWrite(28,1);
   digitalWrite(29,1);
  if( digitalRead(30)==0){/// 3rd gate clear
    gate_clear++;
    digitalWrite(28,0);
   digitalWrite(29,1);
    if(digitalRead(30)==1){
    gate_clear++;
    digitalWrite(28,0);
   digitalWrite(29,0);
   if (digitalRead(30)==1){
    Serial.println("NAND GATE 3 CLEAR PIN 13,12,11");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////3rd gate not clear
    gate_fail++;
    Serial.println("3rd gate not clear 13,12,11");
   }
   if (gate_fail>0){
    gate3=false;
    gate_fail_pin[add]=p3;
add++;
    }
    else{
    gate3=true;
    }
///checking of gate 3rd ended
    
//4th gate/ //7408
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate4;
  p3=8;
   digitalWrite(31,1);
   digitalWrite(32,1);
  if( digitalRead(33)==0){/// 4th gate clear
    gate_clear++;
    digitalWrite(31,0);
   digitalWrite(32,1);
   if(digitalRead(33)==1){
    gate_clear++;
    digitalWrite(31,0);
   digitalWrite(32,0);
     if (digitalRead(33)==1){
    Serial.println("NAND GATE 4 CLEAR PIN 10,9,8");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
 
    }
    
   else{  ////4th gate not clear
    gate_fail++;
    Serial.println("4th gate not clear 10,9,8");
   }
   if (gate_fail>0){
    gate4=false;
    gate_fail_pin[add]=p3;
    add++;
}
    if (gate_clear>0){
   gate4=true;
    }///checking of gate 4th ended
Serial.println(gate1);
if (gate1==true && gate2==true && gate3==true &&gate4==true){
  Serial.println("NAND PASSES TEST");
return true;
}else if(add==4){
  Serial.println("NAND gate test Fail");
 return false;
}
  else{
        Serial.println("list of fault gate pin");
         return false;
         for (int i=0;i<add;i++){
          Serial.println(gate_fail_pin[i]);
          }
    }
    }}

bool XOR(){
  {
  pin_3();
  int gate_clear=0;
  int gate_fail=0;
  int gate_fail_pin[4];
  int add=0;
  //first gate/ //7486
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate1;
  int p3=3;
   digitalWrite(22,1);
   digitalWrite(23,1);
  if( digitalRead(24)==0){/// first gate clear
    gate_clear++;
    digitalWrite(22,0);
   digitalWrite(23,1);
   if(digitalRead(24)==1){
    gate_clear++;
    digitalWrite(22,0);
   digitalWrite(23,0);
   if (digitalRead(24)==0){
    Serial.println("XOR GATE 1 CLEAR PIN 1,2,3");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////first gate not clear
    gate_fail++;
    Serial.println("First gate not clear 1,2,3");
   }
   if (gate_fail>0){
    gate1=false;
      
      gate_fail_pin[add]=p3;
    add++;
}
    else{
    gate1=true;
    }
///checking of gate one ended
//Second gate/ //7486
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate2;
  p3=6;
   digitalWrite(25,1);
   digitalWrite(26,1);
  if( digitalRead(27)==0){/// 2nd gate clear
    gate_clear++;
    digitalWrite(25,0);
   digitalWrite(26,1);
   if(digitalRead(27)==1){
    gate_clear++;
    digitalWrite(25,0);
   digitalWrite(26,0);
   if (digitalRead(27)==0){
    Serial.println("XOR GATE 2 CLEAR PIN 4,5,6");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////2nd gate not clear
    gate_fail++;
    Serial.println("XOR GATE 2 not clear PIN 4,5,6");
   }
   if (gate_fail>0){
    gate2=false;
    
    gate_fail_pin[add]=p3;
    add++;
    }
    else{
    gate2=true;
    }
//third gate/ //7486
  //pin number
  p3=11;
    gate_fail=0;
  gate_clear=0;
  bool gate3;
   digitalWrite(28,1);
   digitalWrite(29,1);
  if( digitalRead(30)==0){/// 3rd gate clear
    gate_clear++;
    digitalWrite(28,0);
   digitalWrite(29,1);
    if(digitalRead(30)==1){
    gate_clear++;
    digitalWrite(28,0);
   digitalWrite(29,0);
   if (digitalRead(30)==0){
    Serial.println("XOR GATE 3 CLEAR PIN 13,12,11");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////3rd gate not clear
    gate_fail++;
    Serial.println("3rd gate not clear 13,12,11");
   }
   if (gate_fail>0){
    gate3=false;
    gate_fail_pin[add]=p3;
add++;
    }
    else{
    gate3=true;
    }
///checking of gate 3rd ended
    
//4th gate/ //7486
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate4;
  p3=8;
   digitalWrite(31,1);
   digitalWrite(32,1);
  if( digitalRead(33)==0){/// 4th gate clear
    gate_clear++;
    digitalWrite(31,0);
   digitalWrite(32,1);
   if(digitalRead(33)==1){
    gate_clear++;
    digitalWrite(31,0);
   digitalWrite(32,0);
     if (digitalRead(33)==0){
    Serial.println("XOR GATE 4 CLEAR PIN 10,9,8");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
 
    }
    
   else{  ////4th gate not clear
    gate_fail++;
    Serial.println("4th gate not clear 10,9,8");
   }
   if (gate_fail>0){
    gate4=false;
    gate_fail_pin[add]=p3;
    add++;
}
    if (gate_clear>0){
   gate4=true;
    }///checking of gate 4th ended

if (gate1==true && gate2==true && gate3==true &&gate4==true){
  Serial.println("XOR PASSES TEST");
  return true; 
}else if(add==4){
  Serial.println("XOR gate test Fail");
return false;
}
  else{
        Serial.println("list of fault gate pin");
         return false;
         for (int i=0;i<add;i++){
          Serial.println(gate_fail_pin[i]);
          }
    }}} 
   
bool AND_3(){
  // 7411(3-AND)
  pin_12();
  int gate_clear=0;
  int gate_fail=0;
  ///i,f j shold be declare gate 1 
  int i=0;//1
  int f=0;//2
  int j=0;//13
  int z=0;
  int sz=0;
  Serial.println("start");
  for (int i=0;i<=1;i++){
    
    for(int f=0;f<=1;f++){
     for(int j=0;j<=1;j++){
      Serial.print("important");
    digitalWrite(22,i);
     digitalWrite(23,f);
     digitalWrite(28,j);
    if (digitalRead(29)==0){
       z++;
      Serial.print(" 1:");
      Serial.print(i);
      Serial.print(" 2:");
      Serial.print(f);
      Serial.print(" 13:");
      Serial.println(j);
      Serial.println("3-AND Pass");
    }
    if(i==1 && f==1 && j==1 && digitalRead(10)==1)    
    {
       z++;
      Serial.print(" 1:");
      Serial.print(i);
      Serial.print(" 2:");
      Serial.print(f);
      Serial.print(" 13:");
      Serial.println(j);
      
      Serial.println("second case pass");
    }
    
  
  }
}
  }
if(z==7 && sz==1){
    gate_clear++;
Serial.println("3-AND GATE 1 PASS");
    }else{
      gate_fail++;
  Serial.println("3-AND GATE 1 Fail");
      }
  

///i,f j shold be declare gate 2
   i=0;//3
   f=0;//4
   j=0;//5
   z=0;
   sz=0;
  Serial.println("start");
  for (int i=0;i<=1;i++){
    
    for(int f=0;f<=1;f++){
     for(int j=0;j<=1;j++){
      Serial.print("important");
    digitalWrite(24,i);
     digitalWrite(25,f);
     digitalWrite(26,j);
    if (digitalRead(27)==0){
       z++;
      Serial.print(" 3:");
      Serial.print(i);
      Serial.print(" 4:");
      Serial.print(f);
      Serial.print(" 5:");
      Serial.println(j);
      Serial.println("3-AND Pass");
    }
    if(i==1 && f==1 && j==1 && digitalRead(27)==1)    
    {
       sz++;
      Serial.print(" 3:");
      Serial.print(i);
      Serial.print(" 4:");
      Serial.print(f);
      Serial.print(" 5:");
      Serial.println(j);
      
      Serial.println("second case pass");
    }
    
  
  }
}
  }
if(z==7 && sz==1){
    gate_clear++;
Serial.println("3-AND GATE 2 PASS");
    }else{
      gate_fail++;
  Serial.println("3-AND GATE 2 Fail");
      }
  


///i,f j shold be declare gate 3
   i=0;//11
   f=0;//10
   j=0;//9
   z=0;
   sz=0;
  Serial.println("start");
  for (int i=0;i<=1;i++){
    
    for(int f=0;f<=1;f++){
     for(int j=0;j<=1;j++){
      Serial.print("important");
    digitalWrite(30,i);
     digitalWrite(31,f);
     digitalWrite(32,j);
    if (digitalRead(33)==0){
       z++;
      Serial.print(" 11:");
      Serial.print(i);
      Serial.print(" 10:");
      Serial.print(f);
      Serial.print(" 9:");
      Serial.println(j);
      Serial.println("3-AND Pass");
    }
    if(i==1 && f==1 && j==1 && digitalRead(33)==1)    
    {
       sz++;
      Serial.print(" 11:");
      Serial.print(i);
      Serial.print(" 10:");
      Serial.print(f);
      Serial.print(" 9:");
      Serial.println(j);
      
      Serial.println("second case pass");
    }
    
  
  }
}
  }
 if(z==7 && sz==1){
    gate_clear++;
Serial.println("3-AND GATE 3 PASS");
    }else{
      gate_fail++;
  Serial.println("3-AND GATE 3 Fail");
      }
  

if (gate_clear==3){
  Serial.println("3-AND GATE PASS finally");
  return true;
  }else if(gate_fail==3){
    Serial.println("3-AND GATE fail");
    return false;
    }
}    
   
bool NAND_3(){
  // 7410(3-NAND)
  pin_12();
  int gate_clear=0;
  int gate_fail=0;
  ///i,f j shold be declare gate 1 
  int i=0;//1
  int f=0;//2
  int j=0;//13
  int z=0;
  int sz=0;
  Serial.println("start");
  for (int i=0;i<=1;i++){
    
    for(int f=0;f<=1;f++){
     for(int j=0;j<=1;j++){
      Serial.print("important");
    digitalWrite(22,i);
     digitalWrite(23,f);
     digitalWrite(28,j);
    if (digitalRead(29)==1){
       z++;
      Serial.print(" 1:");
      Serial.print(i);
      Serial.print(" 2:");
      Serial.print(f);
      Serial.print(" 13:");
      Serial.println(j);
      Serial.println("3-NAND Pass");
    }
    if(i==1 && f==1 && j==1 && digitalRead(10)==0)    
    {
       z++;
      Serial.print(" 1:");
      Serial.print(i);
      Serial.print(" 2:");
      Serial.print(f);
      Serial.print(" 13:");
      Serial.println(j);
      
      Serial.println("second case pass");
    }
    
  
  }
}
  }
if(z==7 && sz==1){
    gate_clear++;
Serial.println("3-NAND GATE 1 PASS");
    }else{
      gate_fail++;
  Serial.println("3-NAND GATE 1 Fail");
      }
  

///i,f j shold be declare gate 2
   i=0;//3
   f=0;//4
   j=0;//5
   z=0;
   sz=0;
  Serial.println("start");
  for (int i=0;i<=1;i++){
    
    for(int f=0;f<=1;f++){
     for(int j=0;j<=1;j++){
      Serial.print("important");
    digitalWrite(24,i);
     digitalWrite(25,f);
     digitalWrite(26,j);
    if (digitalRead(27)==1){
       z++;
      Serial.print(" 3:");
      Serial.print(i);
      Serial.print(" 4:");
      Serial.print(f);
      Serial.print(" 5:");
      Serial.println(j);
      Serial.println("3-NAND Pass");
    }
    if(i==1 && f==1 && j==1 && digitalRead(27)==0)    
    {
       sz++;
      Serial.print(" 3:");
      Serial.print(i);
      Serial.print(" 4:");
      Serial.print(f);
      Serial.print(" 5:");
      Serial.println(j);
      
      Serial.println("second case pass");
    }
    
  
  }
}
  }
if(z==7 && sz==1){
    gate_clear++;
Serial.println("3-NAND GATE 2 PASS");
    }else{
      gate_fail++;
  Serial.println("3-NAND GATE 2 Fail");
      }
  


///i,f j shold be declare gate 3
   i=0;//11
   f=0;//10
   j=0;//9
   z=0;
   sz=0;
  Serial.println("start");
  for (int i=0;i<=1;i++){
    
    for(int f=0;f<=1;f++){
     for(int j=0;j<=1;j++){
      Serial.print("important");
    digitalWrite(30,i);
     digitalWrite(31,f);
     digitalWrite(32,j);
    if (digitalRead(33)==1){
       z++;
      Serial.print(" 11:");
      Serial.print(i);
      Serial.print(" 10:");
      Serial.print(f);
      Serial.print(" 9:");
      Serial.println(j);
      Serial.println("3-NAND Pass");
    }
    if(i==1 && f==1 && j==1 && digitalRead(33)==0)    
    {
       sz++;
      Serial.print(" 11:");
      Serial.print(i);
      Serial.print(" 10:");
      Serial.print(f);
      Serial.print(" 9:");
      Serial.println(j);
      
      Serial.println("second case pass");
    }
    
  
  }
}
  }
 if(z==7 && sz==1){
    gate_clear++;
Serial.println("3-NAND GATE 3 PASS");
    }else{
      gate_fail++;
  Serial.println("3-NAND GATE 3 Fail");
      }
  

if (gate_clear==3){
  Serial.println("3-NAND GATE PASS");
  return true;
  }else if(gate_fail==3){
    Serial.println("3-NAND GATE fail");
    return false;
    }
}    
void pin_3(){
  
  digitalWrite(35,0);
  digitalWrite(34,1);
   for(int i=22;i<=41;i++){
  if(i==24||i==27||i==30||i==33){
  pinMode(i,INPUT);}
  else{
    pinMode(i,OUTPUT);
    }
  }
  }
void pin_12(){
  digitalWrite(35,0);
  digitalWrite(34,1);
  
   for(int i=22;i<=41;i++){
  if(i==29||i==27||i==33){
  pinMode(i,INPUT);}
  else{
    pinMode(i,OUTPUT);
    }
  }
  }  
void pin_1(){
  digitalWrite(35,0);
  digitalWrite(34,1);
  
   for(int i=22;i<=41;i++){
  if(i==22||i==25||i==28||i==31){
  pinMode(i,INPUT);}
  else{
    pinMode(i,OUTPUT);
    }
  }
  }  
    
/*PIN CONFIGRATION IN ARDUNIO MEGA
22     34->VCC FOR 14 PIN IC 
23     28
24     29
25     30
26     31
27     32     
35->GND33
37     34
38     35
39     36
*/
void displaylcd(String a){
  
      lcd.clear();
      while(digitalRead(7)==0){
      lcd.setCursor(0,0);
      lcd.print("IC checked");
      lcd.setCursor(0,1);
      lcd.print(a);
      }
  
  }
bool NOT(){
  /*PIN CONFIGRATION IN ARDUNIO MEGA
22     34->VCC FOR 14 PIN IC 
23     28
24     29
25     30
26     31
27     32     
35->GND33
37     34
38     35
39     36
*/
  digitalWrite(35,0);
  digitalWrite(34,1);
  int gateclear=0;
  int gatefail=0;
   for(int i=22;i<=41;i++){
  if(i%2==0){
  pinMode(i,OUTPUT);}
  else{
    pinMode(i,INPUT);
    }
  }
  digitalWrite(22,0);//1 gate
   if(digitalRead(23)==1){
    gateclear++;
    }
    else{
      gatefail++;
      }
  digitalWrite(24,0);//2 gate
   if(digitalRead(25)==1){
    gateclear++;
    }
    else{
      gatefail++;
      }
  digitalWrite(26,0);//3 gate
   if(digitalRead(27)==1){
    gateclear++;
    }
    else{
      gatefail++;
      }
  digitalWrite(28,0);//4 gate
   if(digitalRead(29)==1){
    gateclear++;
    }
    else{
      gatefail++;
      }
  digitalWrite(30,0);//5 gate
   if(digitalRead(31)==1){
    gateclear++;
    }
    else{
      gatefail++;
      }
  digitalWrite(32,0);//6 gate
   if(digitalRead(33)==1){
    gateclear++;
    }
    else{
      gatefail++;
      }
  if (gateclear==6){
    return true;
    }else {
      return false;
      }
  }       
bool XNOR(){
  {
digitalWrite(35,0);
  digitalWrite(34,1);
   for(int i=22;i<=41;i++){
  if(i==24||i==25||i==30||i==31){
  pinMode(i,INPUT);}
  else{
    pinMode(i,OUTPUT);
    }
  }
  
  int gate_clear=0;
  int gate_fail=0;
  int gate_fail_pin[4];
  int add=0;
  //first gate/ //4077
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate1;
  int p3=3;
   digitalWrite(22,1);
   digitalWrite(23,1);
  if( digitalRead(24)==1){/// first gate clear
    gate_clear++;
    digitalWrite(22,0);
   digitalWrite(23,1);
   if(digitalRead(24)==0){
    gate_clear++;
    digitalWrite(22,0);
   digitalWrite(23,0);
   if (digitalRead(24)==1){
    Serial.println("XNOR GATE 1 CLEAR PIN 1,2,3");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////first gate not clear
    gate_fail++;
    Serial.println("First gate not clear 1,2,3");
   }
   if (gate_fail>0){
    gate1=false;
      
      gate_fail_pin[add]=p3;
    add++;
}
    else{
    gate1=true;
    }
///checking of gate one ended
//Second gate/ //4077
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate2;
  p3=6;
   digitalWrite(27,1);
   digitalWrite(26,1);
  if( digitalRead(25)==1){/// 2nd gate clear
    gate_clear++;
    digitalWrite(27,0);
   digitalWrite(26,1);
   if(digitalRead(25)==0){
    gate_clear++;
    digitalWrite(27,0);
   digitalWrite(26,0);
   if (digitalRead(25)==1){
    Serial.println("XNOR GATE 2 CLEAR PIN 4,5,6");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////2nd gate not clear
    gate_fail++;
    Serial.println("XNOR GATE 2 not clear PIN 4,5,6");
   }
   if (gate_fail>0){
    gate2=false;
    
    gate_fail_pin[add]=p3;
    add++;
    }
    else{
    gate2=true;
    }
//third gate/ //4077
  //pin number
  p3=11;
    gate_fail=0;
  gate_clear=0;
  bool gate3;
   digitalWrite(28,1);
   digitalWrite(29,1);
  if( digitalRead(30)==1){/// 3rd gate clear
    gate_clear++;
    digitalWrite(28,0);
   digitalWrite(29,1);
    if(digitalRead(30)==0){
    gate_clear++;
    digitalWrite(28,0);
   digitalWrite(29,0);
   if (digitalRead(30)==1){
    Serial.println("XNOR GATE 3 CLEAR PIN 13,12,11");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
   
    }
    
   else{  ////3rd gate not clear
    gate_fail++;
    Serial.println("3rd gate not clear 13,12,11");
   }
   if (gate_fail>0){
    gate3=false;
    gate_fail_pin[add]=p3;
add++;
    }
    else{
    gate3=true;
    }
///checking of gate 3rd ended
    
//4th gate/ //4077
  //pin number
  gate_fail=0;
  gate_clear=0;
  bool gate4;
  p3=8;
   digitalWrite(33,1);
   digitalWrite(32,1);
  if( digitalRead(31)==1){/// 4th gate clear
    gate_clear++;
    digitalWrite(33,0);
   digitalWrite(32,1);
   if(digitalRead(31)==0){
    gate_clear++;
    digitalWrite(33,0);
   digitalWrite(32,0);
     if (digitalRead(31)==1){
    Serial.println("XNOR GATE 4 CLEAR PIN 10,9,8");
    }else{
      gate_fail++;
      }
   }else{
    gate_fail++;
      }
 
    }
    
   else{  ////4th gate not clear
    gate_fail++;
    Serial.println("4th gate not clear 10,9,8");
   }
   if (gate_fail>0){
    gate4=false;
    gate_fail_pin[add]=p3;
    add++;
}
    if (gate_clear>0){
   gate4=true;
    }///checking of gate 4th ended

if (gate1==true && gate2==true && gate3==true &&gate4==true){
  Serial.println("XNOR PASSES TEST");
  return true; 
}else if(add==4){
  Serial.println("XNOR gate test Fail");
return false;
}
  else{
        Serial.println("list of fault gate pin");
         return false;
         for (int i=0;i<add;i++){
          Serial.println(gate_fail_pin[i]);
          }
    }}} 
    
    
