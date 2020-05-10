//https://cyaninfinite.com/moving-the-28byj-48-stepper-motor/s

#include <AccelStepper.h>
#include <MultiStepper.h>

#define HALFSTEP 8  //Half-step mode (8 step control signal sequence)

//Motor pin definitions
#define bearing_mtrPin1  13
#define bearing_mtrPin2  12
#define bearing_mtrPin3  11
#define bearing_mtrPin4  10

#define feeder_mtrPin1 9
#define feeder_mtrPin2 8
#define feeder_mtrPin3 7
#define feeder_mtrPin4 6

#define pwm_pin 3

#define piston_mtrPin1 A0
#define piston_mtrPin2 A1
#define piston_mtrPin3 A2
#define piston_mtrPin4 A3
//


//some stepper motor areas
#define clockswise_fullCricle 4096
#define counter_fullCircle -4096
#define left 
//

#define brushlessOff 149
#define brushlessOn 160


int feederPos = 0;
int serial_input = 0;

AccelStepper bearing_stepper(HALFSTEP, bearing_mtrPin1, bearing_mtrPin3, bearing_mtrPin2, bearing_mtrPin4);
AccelStepper feeder_stepper(HALFSTEP, feeder_mtrPin1, feeder_mtrPin3, feeder_mtrPin2, feeder_mtrPin4);
AccelStepper piston_stepper(HALFSTEP, piston_mtrPin1, piston_mtrPin3, piston_mtrPin2, piston_mtrPin4);

void setup() {

  Serial.begin(9600);

  //sets the PWM to 50% b/c the motors need starting value >0% but <63%
  pinMode(pwm_pin, OUTPUT);
  analogWrite(pwm_pin, brushlessOff);

  //set parameters to the stepper motors
  bearing_stepper.setMaxSpeed(2000.0);
  bearing_stepper.setAcceleration(200.0);
  bearing_stepper.setSpeed(1500);

  feeder_stepper.setMaxSpeed(3000.0);
  feeder_stepper.setAcceleration(300.0);
  feeder_stepper.setSpeed(1500);

  piston_stepper.setMaxSpeed(2000.0);
  piston_stepper.setAcceleration(200.0);
  piston_stepper.setSpeed(1500);
  //
}

void loop() {

  //start the stepper motors
  feeder_stepper.run();
  bearing_stepper.run();
  piston_stepper.run();
  
  if (Serial.available() > 0){

    serial_input = Serial.read();
    
    Serial.println(serial_input);

    //close left shot
    if (serial_input == 1){
      pistonPosCloseLeftRight();
      turnLeft();
      feedBird(feederPos);
    }

    //close middle shot
    if (serial_input == 2){
      pistonPosCloseMiddle();
      turnCenter();
      feedBird(feederPos);
    }

    //close right shot
    if (serial_input == 3){
      pistonPosCloseLeftRight();
      turnRight();
      feedBird(feederPos);
    }

    //left middle shot
    if (serial_input == 4){
      pistonPosMed();
      turnLeft();
      feedBird(feederPos);
    }

    //center middle shot
    if (serial_input == 5){
      pistonPosMed();
      turnCenter();
      feedBird(feederPos);
    }

    //right middle shot
    if (serial_input == 6){
      pistonPosMed();
      turnRight();
      feedBird(feederPos);
    }

    //left far shot
    if (serial_input == 7){
      pistonPosFar();
      turnLeft();
      feedBird(feederPos);
    }

    //center far shot
    if (serial_input == 8){
      pistonPosFar();
      turnCenter();
      feedBird(feederPos);
    }

    //right far shot
    if (serial_input == 9){
      pistonPosFar();
      turnRight();
      feedBird(feederPos);
    }

    if (serial_input == 10){
      pistonPosFar();
      turnCenter();
    }

    //turns off the motor
    if (serial_input == 11){
      analogWrite(pwm_pin, brushlessOff);
    }

    //turns on the motor
    if (serial_input == 12){
      analogWrite(pwm_pin, brushlessOn);
    }

  }
    
}

//close
void pistonPosFar(){
  piston_stepper.moveTo(0);
}

void pistonPosMed(){
  piston_stepper.moveTo(1500);
}

void pistonPosCloseLeftRight(){
  piston_stepper.moveTo(1600);
}

void pistonPosCloseMiddle(){
  piston_stepper.moveTo(2600);
}


void feedBird(int Pos){
  int currentPos = feeder_stepper.currentPosition();
  feeder_stepper.moveTo(currentPos - 4096);
}

void turnRight(){
  bearing_stepper.moveTo(-450);
}

void turnCenter(){
  int current_pos = bearing_stepper.currentPosition();
  if (current_pos > 0){
    bearing_stepper.moveTo(-0);
  }
  if(current_pos < 0){
    bearing_stepper.moveTo(0);
  }
}

void turnLeft(){
  bearing_stepper.moveTo(450);
}
