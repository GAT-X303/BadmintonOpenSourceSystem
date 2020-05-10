//https://cyaninfinite.com/moving-the-28byj-48-stepper-motor/s

#include <AccelStepper.h>
#include <MultiStepper.h>

#define HALFSTEP 8  //Half-step mode (8 step control signal sequence)

//Motor pin definitions
#define mtrPin1  9 // IN1 on the ULN2003 driver 1
#define mtrPin2  8 // IN2 on the ULN2003 driver 1
#define mtrPin3  7 // IN3 on the ULN2003 driver 1
#define mtrPin4  6 // IN4 on the ULN2003 driver 1

int input = 1;

int serial_input = 0;

AccelStepper stepper1(HALFSTEP, mtrPin1, mtrPin3, mtrPin2, mtrPin4);

void setup() {

  Serial.begin(9600);
  
  //
  //stepper1.setMaxSpeed(1500.0);
  stepper1.setMaxSpeed(2000.0);
  
  stepper1.setAcceleration(200.0);
  //stepper1.setAcceleration(400.0);
  
  //stepper1.setSpeed(1000);
  stepper1.setSpeed(1500);
  //


  //stepper1.moveTo(100);

  //stepper1.moveTo(4096/8); //45 degs clockwise
  //stepper1.moveTo(-4096/8); 
  //stepper1.moveTo(-4096/2);  //Rotate 1 revolution
}

void loop() {

  /*
  //Change direction when the stepper reaches the target position
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(-stepper1.currentPosition());  //Reverse motor
  }
  */


/*
  if (input == 1){
    stepper1.moveTo(512);
    if (stepper1.distanceToGo() == 0){
      stepper1.moveTo(-0);
      input = 0;
    }
  }


  if (input == 0){
    
  }

  if (input == -1){
    
  }

*/

  stepper1.run();  //Start
  
  if (Serial.available() > 0){
    
    serial_input = Serial.read();
    Serial.println(serial_input);

    if(serial_input == 0){
      stepper1.moveTo(-4096);
    }

    if (serial_input == 1){
      stepper1.moveTo(512);
      //stepper1.moveTo(1024);
    }

    if (serial_input == 2){
      stepper1.moveTo(-512);
      //stepper1.moveTo(-1024);
    }
  }

  if (serial_input == 3){
    stepper1.moveTo(-512);
    //stepper1.moveTo(0);
  }

/*
  if (stepper1.distanceToGo() == 0 && serial_input == 0){
    stepper1.moveTo(-4096/2);
  }
  */
  
}
