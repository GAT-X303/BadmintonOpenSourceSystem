/*
* BOSS
* S01 - Allan Hieng
* Pulse Width Modulation on the Adruino test. Measured using an oscilloscope so that it would be the values we needed 
*/

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
