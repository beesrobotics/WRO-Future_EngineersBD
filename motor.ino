
#define PWMR 11
#define IN1R 13
#define IN2R 12

#define PWML 10
#define IN1L 9
#define IN2L 8

void motor(int spl,int spr)
{
  int sl = 0;
  int sr = 0;
  sl = (spl*255)/100;
  sr = (spr*255)/100;
  pinMode(PWML,OUTPUT);
  pinMode(IN1L,OUTPUT);
  pinMode(IN2L,OUTPUT);

  pinMode(PWMR,OUTPUT);
  pinMode(IN1R,OUTPUT);
  pinMode(IN2R,OUTPUT);
  if(sr>255)
  {
    sr = 255;
  }
  else if(sr<-255)
  {
    sr = -255;
  }
  if(sl>255)
  {
    sl = 255;
  }
  else if(sl<-255)
  {
    sl = -255;
  }
  if (sl>0)
  {
    digitalWrite(IN1L,HIGH);
    digitalWrite(IN2L,LOW);
    analogWrite(PWML,sl);
  }
  else if(sl<0)
  {
    digitalWrite(IN1L,LOW);
    digitalWrite(IN2L,HIGH);
    analogWrite(PWML,-sl);
  }
  else
  {
    digitalWrite(IN1L,LOW);
    digitalWrite(IN2L,LOW);
    analogWrite(PWML,255);
  }
  if(sr>0)
  {
    digitalWrite(IN1R,HIGH);
    digitalWrite(IN2R,LOW);
    analogWrite(PWMR,sr);
  }
  else if (sr<0)
  {
    digitalWrite(IN1R,LOW);
    digitalWrite(IN2R,HIGH);
    analogWrite(PWMR,-sr);
  }
  else
  {
    digitalWrite(IN1R,LOW);
    digitalWrite(IN2R,LOW);
    analogWrite(PWMR,255);
  }
}
