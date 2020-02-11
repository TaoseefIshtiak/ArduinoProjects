#define inA 2
#define inB 3
#define inC 4
#define inD 7
#define ena 5
#define enb 6

#define sp(r) Serial.println(r) 
 
void wheel(int lm, int rm);
int i,z, sen[6],s[6], lastSensor,lastError,lastError1;
 
int base_L=255;
int base_R=255;
int kp=07;
int kd=02;
 
void setup()
{
  Serial.begin(9600);
  mot_init();
  other_init();
}
void loop()
{
  line_follow();
 }
 
void other_init()
{
 
  lastSensor=0;
  lastError=0;
  
}
 
void mot_init()
{
  pinMode(inA,OUTPUT);
  pinMode(inB,OUTPUT);
  pinMode(inC,OUTPUT);
  pinMode(inD,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
 
  digitalWrite(inA,LOW);
  digitalWrite(inB,LOW);
  digitalWrite(inC,LOW);
  digitalWrite(inD,LOW);
}
 
void wheel(int lm, int rm)
{
  if(lm==0)
  {
    digitalWrite(inC,LOW);
    digitalWrite(inD,LOW);
  }
  if(lm>0)
  {
    digitalWrite(inC,HIGH);
    digitalWrite(inD,LOW);
  }
  else if(lm<0)
  {
    digitalWrite(inC,LOW);
    digitalWrite(inD,HIGH);
  }
 
 
  if(rm==0)
  {
    digitalWrite(inA,LOW);
    digitalWrite(inB,LOW);
  }
  if(rm>0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
  }
  else if(rm<0)
  {
    digitalWrite(inA,LOW);
    digitalWrite(inB,HIGH);
  }
  if(lm>254) lm=254;
  if(lm<-254) lm=-254;
  if(rm>254) rm=254;
  if(rm<-254) rm=-254;
 
  analogWrite(ena,abs(rm));
  analogWrite(enb,abs(lm));
 
}
 
int readSensor()
{
  for(i=0;i<6;i++)
  {
    sen[i]=analogRead(i);
    if(sen[i]>750)
    {
      s[i]=0;
     
    }
    else {
      s[i]=1;
     
    }
  }
 
  int error,sum;
  sum=s[0]+s[1]+s[2]+s[3]+s[4]+s[5];
  if(sum!=0)
  {
    error=(s[0]*10+s[1]*20+s[2]*30+s[3]*40+s[4]*50+s[5]*60)/sum-35;
  }
  else
  {
     error=420;
  }
 
  if(s[0]==1) lastSensor=1;
  else if(s[5]==1) lastSensor =2;
//  Serial.println(error);
  return error;
}
 
 
void line_follow()
{
 
int error=readSensor();
sp(error);
 if(error==420)
 {
   if(lastSensor==1) wheel(-255,255);
   else if(lastSensor==2) wheel(255,-255);
 }
 
 
 else {
int   p=kp*error;
int   d=kd*(error-lastError);
int   corr=p+d;
//   Serial.println(corr);
   wheel(base_L+corr,base_R-corr);
   if((error-lastError)!=0) delay(5);
   lastError=error;
   sp("Correction");
 sp(corr);
 }
 sp("error");
 sp(error);
 sp("Last error");
 sp(lastError);
 

}
