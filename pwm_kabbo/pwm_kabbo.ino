int led = 6;
int buzz = 9;

int x ;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);

  // put your setup code here, to run once:

}

void loop() {
  for (x = 0; x <= 255; x += 10)
  {
    analogWrite(led, x);
    delay(1000);
    digitalWrite (buzz, HIGH);
    delay(x);
    digitalWrite (buzz, LOW);
    delay(x);
  }

  // put your main code here, to run repeatedly:
  for (x = 255; x >= 0; x -= 10) {
    analogWrite(led, x);
    delay(1000);
    digitalWrite (buzz, HIGH);
    delay(x);
    digitalWrite (buzz, LOW);
    delay(x);
    }
}
