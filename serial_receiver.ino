
// Arduino continuosly sends a string for every 0.5sec until it detects an input from the computer. It can also detect
// keyboard inputs from 1-7

#include <Servo.h>

String mySt;
char myChar = 0;
int i=0;

//SERVO PINS
int servopin1= 11; //claw
int servopin2= 10; //middle
int servopin3= 7; //bottom

Servo Servo1;
Servo Servo2;
Servo Servo3;

int myangle;//Define the angle variable to be 0-180 
int pulsewidth;//Define pulse width variable
int hand_gesture; //1-7

void servopulse(int servopin1,int myangle)//Define a pulse function 
{ 
  pulsewidth=(myangle*11)+500;//Convert the angle to a pulsewidth of 500-2480
  digitalWrite(servopin1,HIGH);//Set the servo interface level to high
  delayMicroseconds(pulsewidth);//The number of microseconds of the delay pulse width value
  digitalWrite(servopin1,LOW);//Set the servo interface level to low
  delayMicroseconds(2500-pulsewidth); 
}


void setup() {
   // start serial port at 9600 bps:
   Serial.begin(9600);
   while (!Serial) {
     ; // wait for serial port to connect. Needed for native USB port only
   }
  establishContact();  // send a byte to establish contact until receiver responds

  pinMode(servopin1,OUTPUT);//Set the servo interface to the output interface
  Serial.println("Type which hand gesture: 1-7");

  Servo1.attach(servopin1);
  Servo2.attach(servopin2);
  Servo3.attach(servopin3);
  
 }

// MAIN METHOD
void loop() {
   
 hand_gesture=Serial.read();//Readthevalueoftheserialport

  if(hand_gesture == '1')  //fist
 {
 hand_gesture = hand_gesture-'0';//Convert feature quantities to numeric variables 
  hand_gesture = hand_gesture*(180/9);//Convert numbers to angles
  Serial.print("fist "); //DEC:OutputstheASCII encoded value of bindecimal form,followed by a carriage return and line feed symbol
  Serial.println();
  for(int i=0;i<=50;i++) //Give the servos enough time to turn it to the specified angle
  {
   Servo1.write(20);
   Servo2.write(20);
   Servo3.write(60); 
  }
 } 

 
if(hand_gesture== '2') //rest
{ 
  hand_gesture = hand_gesture-'0';//Convert feature quantities to numeric variables 
  hand_gesture = hand_gesture*(180/9);//Convert numbers to angles
 // Serial.println(hand_gesture);
  Serial.print("rest "); //DEC:OutputstheASCII encoded value of bindecimal form,followed by a carriage return and line feed symbol
  Serial.println();
  for(int i=0;i<=100;i++) //Give the servos enough time to turn it to the specified angle
  {
   Servo1.write(20); //rest
   Servo2.write(120); //rest
   Servo3.write(140); //rest
  } 
 } 
 
  if(hand_gesture == '3')  //open hand
 {
 hand_gesture = hand_gesture-'0';//Convert feature quantities to numeric variables 
  hand_gesture = hand_gesture*(180/9);//Convert numbers to angles
  Serial.print("open hand "); //DEC:OutputstheASCII encoded value of bindecimal form,followed by a carriage return and line feed symbol
  Serial.println();
  for(int i=0;i<=50;i++) //Give the servos enough time to turn it to the specified angle
  {
   Servo1.write(120);
   Servo2.write(120);
   Servo3.write(140); 
  }
 }
   if(hand_gesture == '4') // wave-in
  {
    
  hand_gesture = hand_gesture-'0';//Convert feature quantities to numeric variables 
  hand_gesture = hand_gesture*(180/9);//Convert numbers to angles
  Serial.print("wave in "); //DEC:OutputstheASCII encoded value of bindecimal form,followed by a carriage return and line feed symbol
  Serial.println();
  for(int i=0;i<=50;i++) //Give the servos enough time to turn it to the specified angle
  {
   Servo1.write(20);
  Servo2.write(20);
  Servo3.write(90); 
  }
 
  }

   if(hand_gesture == '5') //wave-out
  {
    
   hand_gesture = hand_gesture-'0';//Convert feature quantities to numeric variables 
  hand_gesture = hand_gesture*(180/9);//Convert numbers to angles
  Serial.print("wave out "); //DEC:OutputstheASCII encoded value of bindecimal form,followed by a carriage return and line feed symbol
  Serial.println();
  for(int i=0;i<=50;i++) //Give the servos enough time to turn it to the specified angle
  {
   Servo1.write(20);
   Servo2.write(160);
   Servo3.write(90); 
  
   
  }
 
  }
   if(hand_gesture == '6') //point
  {
    
   hand_gesture = hand_gesture-'0';//Convert feature quantities to numeric variables 
  hand_gesture = hand_gesture*(180/9);//Convert numbers to angles
  Serial.print("point "); //DEC:OutputstheASCII encoded value of bindecimal form,followed by a carriage return and line feed symbol
  Serial.println();
  for(int i=0;i<=50;i++) //Give the servos enough time to turn it to the specified angle
  {
   Servo1.write(60);
   Servo2.write(60);
   Servo3.write(90); 
   
   
  }
 
  }

   if(hand_gesture == '7') //grip
  {
    
   hand_gesture = hand_gesture-'0';//Convert feature quantities to numeric variables 
  hand_gesture = hand_gesture*(180/9);//Convert numbers to angles
  Serial.print("grip "); //DEC:OutputstheASCII encoded value of bindecimal form,followed by a carriage return and line feed symbol
  Serial.println();
  for(int i=0;i<=50;i++) //Give the servos enough time to turn it to the specified angle
  {
   Servo1.write(20);
   Servo2.write(60);
   Servo3.write(90); 
   
   
  }
 
  }

   if (Serial.available() > 0) {
     myChar = Serial.read();
     mySt +=myChar;  //receive string from Computer
   }
   
   if ((mySt.length() >0)&(!Serial.available())) {
     Serial.print(mySt); //Print received string to Computer
     mySt="";
   }
 }


 void establishContact() {
   while (Serial.available() <= 0) {
     //Serial.print("Arduino send: ");
     //Serial.println(i);  //Print increasing value to Computer
     i+=1;
     delay(100);
   }
 }
