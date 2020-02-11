int buzz = 4;
int x;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzz, OUTPUT);
}

void loop() {
   digitalWrite (buzz, HIGH);
    delay(50);
    digitalWrite (buzz, LOW);
    delay(500);
}
