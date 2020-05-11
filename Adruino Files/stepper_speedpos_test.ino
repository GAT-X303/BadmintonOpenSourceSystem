/*
* BOSS
* S01 - Allan Hieng
* This program was used to test the speed of the stepper motors and revolution of the steppter motors.
*/
#include <AccelStepper.h>
#include <MultiStepper.h>

#define HALFSTEP 8  //Half-step mode (8 step control signal sequence)

// Motor pin definitions
#define mtrPin1  8     // IN1 on the ULN2003 driver 1
#define mtrPin2  9     // IN2 on the ULN2003 driver 1
#define mtrPin3  10     // IN3 on the ULN2003 driver 1
#define mtrPin4  11     // IN4 on the ULN2003 driver 1

AccelStepper stepper1(HALFSTEP, mtrPin1, mtrPin3, mtrPin2, mtrPin4);

void setup() {
  stepper1.setMaxSpeed(1500.0);
  stepper1.setAcceleration(200.0);  //Make the acc quick
  stepper1.setSpeed(1000);
  stepper1.moveTo(4096/4);  //Rotate 1 revolution
}

void loop() {

  //Change direction when the stepper reaches the target position
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(-stepper1.currentPosition());  //Reverse motor
  }
  stepper1.run();  //Start
}
