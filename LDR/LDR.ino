#define thresholdRed         400
#define thresholdGreen       300
#define thresholdYellow      150
#define buzz                 4
#define Red                  9 //LED 1
#define Green                10 //LED 3
#define Yellow               8 //LED 2

int lightSensitivity = 0;

void setup() {
  Serial.begin(9600);
  digitalWrite(Red, OUTPUT);
  digitalWrite(Green, OUTPUT);
  digitalWrite(Yellow, OUTPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  //digitalWrite(Red, LOW);
  //digitalWrite(Green, LOW);
  //digitalWrite(Yellow, LOW);
  lightSensitivity = analogRead(0);
  Serial.println(lightSensitivity);
  digitalWrite (buzz, LOW);
  if(lightSensitivity < thresholdRed){
    digitalWrite(Red, HIGH);
    digitalWrite (buzz, HIGH);
    delay(100);
    digitalWrite (buzz, LOW);
    //delay(500);
  }
  else {
    digitalWrite(Red, LOW);
  }
  if(lightSensitivity < thresholdGreen) {
    digitalWrite(Green, HIGH);
     digitalWrite(Red, HIGH);
    digitalWrite (buzz, HIGH);
    delay(70);
    digitalWrite (buzz, LOW);
    //delay(500);
  }
  else {
    digitalWrite(Green, LOW);
  }
  if(lightSensitivity < thresholdYellow) {
    digitalWrite(Yellow, HIGH);
    digitalWrite(Red, HIGH);
    digitalWrite (buzz, HIGH);
    delay(30);
    digitalWrite (buzz, LOW);
    //delay(500); 
  }
  else {
    digitalWrite(Yellow, LOW);
  }
  delay(500);
  }

