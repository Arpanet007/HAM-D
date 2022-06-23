// C++ code
//
#include <IRremote.h>     
int RECV_PIN =10;     
int c1=3;
int a1=4;
int c2=5;
int a2=6;
int c3=7;
int a3=8;
int c4=9;
int a4=11;
IRrecv irrecv(RECV_PIN);     
decode_results results;     
void setup(){     
 Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
 pinMode(c1, OUTPUT);     
 pinMode(a1, OUTPUT);     
 pinMode(c2, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(c4, OUTPUT);
  pinMode(a4, OUTPUT);
}     
void loop(){    
   irrecv.decode();
  
   if (irrecv.decode(&results)){  
     int value=results.value;
Serial.println(value,DEC);      
       switch(value){     
         case -30301: //Keypad button "1"     
         //forward
         
         digitalWrite(c2,HIGH);
         digitalWrite(a2,LOW); 
         
         digitalWrite(a4,HIGH);
         digitalWrite(c4,LOW);
         break;
              
            
         case 2295: //Keypad button "2"     
         //backward   
         digitalWrite(a2,HIGH);
         digitalWrite(c2,LOW);  
         
         digitalWrite(c4,HIGH);
         digitalWrite(a4,LOW);
         break;
              
              
         case 18615: //Keypad button "3"     
          //turn left   
         digitalWrite(a1,HIGH);
         digitalWrite(c1,LOW); 
           
         digitalWrite(a3,HIGH);
         digitalWrite(c3,LOW);
         break;
              
              
         case 10455: //Keypad button "4"     
         //turn right   
         digitalWrite(c1,HIGH);
         digitalWrite(a1,LOW); 
           
         digitalWrite(c3,HIGH);
         digitalWrite(a3,LOW);
         break;
         }     
       irrecv.resume();      
   }     
}