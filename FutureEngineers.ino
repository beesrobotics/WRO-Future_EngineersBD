
#include <Servo.h>
#include <NewPing.h>
#define trigpinL A2
#define echopinL A3
#define trigpinR A5
#define echopinR A4
#define trigpin A1
#define echopin A0
#define MaxDistanceL 200
#define MaxDistanceR 200
#define MaxDistanceF 200
NewPing sonarL(trigpinL, echopinL, MaxDistanceL);
NewPing sonarR(trigpinR, echopinR, MaxDistanceR);
NewPing sonarF(trigpin, echopin, MaxDistanceF);

int  leftdist;
int  rightdist;
int  fontdist;
Servo myservo;
String command;
int pos = 0;
unsigned long last_time = millis();


void setup() {
  Serial.begin(9600);
  myservo.attach(6);
//  motor(30,30);

  // put your setup code here, to run once:
}

void loop() {
//           leftdist = dataF();
//           rightdist = dataL();
//           fontdist = dataR();
//         Serial.print("fontdist");
//         Serial.print(fontdist);
//         Serial.print("leftdist");
//         Serial.print(leftdist);
//         Serial.print("rigtdist");
//         Serial.println(rightdist);
//         delay(50);
  if (Serial.available()){
    command = Serial.readStringUntil('\n');
    command.trim();

    if (command.equals("RIGHT")){
      myservo.write(130);
      motor(100, 100);
    }
   else if (command.equals("LEFT")){
      myservo.write(50);
      motor(100, 100);
    }
    else if (command.equals("Centered")){
      myservo.write(90);
      motor(100, 100);
    }
    else if (command.equals("stop")){
      myservo.write(90);
      motor(0, 0);
    }
    else if (command.equals("Nothing")){
           leftdist = dataL();
           rightdist = dataR();
           fontdist = dataF();
         if(rightdist > 1 && rightdist < 50){
            myservo.write(60);
            motor(100, 100);
            }
         else if(leftdist > 1 && leftdist < 50){
              myservo.write(120);
              motor(100, 100);
              }
         else if(fontdist > 1 && fontdist < 70){
          
              if (leftdist > rightdist || leftdist == 0){
                myservo.write(50);
                motor(100, 100);                
                }
             else if (leftdist < rightdist || rightdist == 0){
                myservo.write(130);
                motor(100, 100);
                }
                else {
                myservo.write(90);
                motor(100, 100);
                }
         }
     }

  }

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
long dataF() {
  unsigned int uS = sonarF.ping();
  return uS / US_ROUNDTRIP_CM;
}
