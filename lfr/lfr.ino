//defining constants
const int forward = 0, right = 1, left = 2;


//Defining Motor Pins
int motor_1_f = 12;
int motor_1_b = 11;
int motor_2_f = 7;
int motor_2_b = 6;

//Defining Sensor Pins
int sen_1 = A0;
int sen_2 = A1;

void setup()
{
   Serial.begin(9600);
   pinMode(motor_1_f, OUTPUT);
   pinMode(motor_1_b, OUTPUT);
   pinMode(motor_2_f, OUTPUT);
   pinMode(motor_2_b, OUTPUT);
  
    
}

void robotMove(int dir)
{
  if(dir==forward)
  {
    digitalWrite(motor_1_f, HIGH);
    digitalWrite(motor_1_b, LOW);
    digitalWrite(motor_2_f, HIGH);
    digitalWrite(motor_2_b, LOW);  
  }
  else if(dir==right)
  {
    digitalWrite(motor_1_f, LOW);
    digitalWrite(motor_1_b, HIGH);
    digitalWrite(motor_2_f, HIGH);
    digitalWrite(motor_2_b, LOW);  
  }
  else if(dir==left)
  {
    digitalWrite(motor_1_f, HIGH);
    digitalWrite(motor_1_b, LOW);
    digitalWrite(motor_2_f, LOW);
    digitalWrite(motor_2_b, HIGH);    
    
  }
  
  


  
}



void loop()
{
 
  int sen_1_val = analogRead(sen_1);
  int sen_2_val = analogRead(sen_2);
  Serial.println(sen_1_val);
  Serial.println(sen_2_val);
  //delay(500);
  if(sen_1_val<500 && sen_2_val>500)
  {
    robotMove(left);  
    delay(100); // increase or decrease
    Serial.println("Left");
  }
  else if(sen_1_val>500 && sen_2_val<500)
  {
    robotMove(right);
    delay(100); // increase or decrease
  Serial.println("Right");  
  }  
  else
  {
   robotMove(forward); 
   Serial.println("Forward");
  }
  
}
