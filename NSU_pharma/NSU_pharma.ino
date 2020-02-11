#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 1;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int led = 12;
void setup() {;
  myservo.attach(9);
  pinMode(7, INPUT);   //connected to game
  pinMode(11, OUTPUT);  //connected to buzzer  
  pinMode(led, OUTPUT);
  digitalWrite(7, LOW);
  digitalWrite(11, LOW);// attaches the servo on pin 9 to the servo object
}

void loop() {
  if(digitalRead(7) == HIGH){
    digitalWrite(11, HIGH);
    digitalWrite(led, HIGH);
    
    delay(1000);
    digitalWrite(11, LOW);
    digitalWrite(led, LOW);
  }
  val = analogRead(potpin);  // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
