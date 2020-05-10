int outPin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(outPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(outPin, 127);
  //analogWrite(outPin, 166);
}
