
#include <Servo.h>
#include <NewPing.h>
#define trigpinL A2
#define echopinL A3
#define trigpinR A1
#define echopinR A0
#define MaxDistanceL 200
#define MaxDistanceR 200
NewPing sonarL(trigpinL, echopinL, MaxDistanceL);
NewPing sonarR(trigpinR, echopinR, MaxDistanceR);
int  leftdist;
int  rightdist;

Servo myservo;
String command;
int pos = 0;


void setup() {
  Serial.begin(9600);
  myservo.attach(6);
  // put your setup code here, to run once:
}

void loop() {
    leftdist = dataL();
    rightdist = dataR();

   if(rightdist >= 1 && rightdist <= 40){
     myservo.write(60);

    }
    else{
    }
   if(leftdist >= 1 && leftdist <= 40){
     myservo.write(120);

   }
    else{
    
    }
  if (Serial.available()){
    command = Serial.readStringUntil('\n');
    command.trim();


    if (command.equals("RIGHT")){
      myservo.write(120);
      delay(100);
      motor(50, 50);
    }
   else if (command.equals("LEFT")){
      myservo.write(60);
      delay(100);
      motor(50, 50);
    }
    else if (command.equals("Centered")){
      myservo.write(85);
      delay(100);
      motor(50, 50);
    }
  }
//  else{
//    myservo.write(85);
//    delay(50);
//    motor(0, 0);
//  }
  // put your main code here, to run repeatedly:
}
void rightTurn(){
      for (pos = 50; pos <= 130; pos += 1) {
        myservo.write(pos);
        delay(15);
        }
}
void leftTurn(){  
      for (pos = 130; pos >= 50; pos -= 1) {
        myservo.write(pos);
        delay(15);
        }
}
  
long dataL() {
  unsigned int uS = sonarL.ping();
  return uS / US_ROUNDTRIP_CM;
}
long dataR() {
  unsigned int uS = sonarR.ping();
  return uS / US_ROUNDTRIP_CM;
}
