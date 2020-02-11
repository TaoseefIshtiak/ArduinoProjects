int switchPin=8;
int ledPin=11;
boolean lastButton = LOW;
boolean ledOn=false;
int ledLevel = 0;

boolean debounce(boolean last){
  boolean current=digitalRead(switchPin);
  if(last!=current){
    delay(5);
    current=digitalRead(switchPin);
  }
  return current;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton=debounce(lastButton);
  if(lastButton=LOW && currentButon==LOW){
    ledlevel=ledlevel+51;  
  }
  
  lastButton=currentButton;
  //if(ledLevel>255)ledlLeve=0;
  //analogWrite(ledPin, ledLevel);
  digitalWrite(ledPin, ledOn);
}
