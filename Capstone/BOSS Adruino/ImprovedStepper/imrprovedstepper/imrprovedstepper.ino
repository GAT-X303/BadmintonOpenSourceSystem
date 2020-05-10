//https://cyaninfinite.com/moving-the-28byj-48-stepper-motor/s

#include <AccelStepper.h>
#include <MultiStepper.h>

#define HALFSTEP 8  //Half-step mode (8 step control signal sequence)

//Motor pin definitions
#define mtrPin1  8 // IN1 on the ULN2003 driver 1
#define mtrPin2  9 // IN2 on the ULN2003 driver 1
#define mtrPin3  10 // IN3 on the ULN2003 driver 1
#define mtrPin4  11 // IN4 on the ULN2003 driver 1

AccelStepper stepper_1(HALFSTEP, mtrPin1, mtrPin3, mtrPin2, mtrPin4);

int serial_input;
int current_pos = 0;

void setup() {
  Serial.begin(9600);
  stepper_1.setMaxSpeed(2000.0);
  stepper_1.setAcceleration(200.0);
  stepper_1.setSpeed(1500);
}


void loop() {
  stepper_1.run();
  
  if (Serial.available() > 0){
    
    serial_input = Serial.read();

    //left turn
    if (serial_input == 1){
      
    }

    //right turn
    if (serial_input == 2){
      
    }

    //feeding 
    if (serial_input == 3){
      current_pos = turn360(current_pos);
    }
  }
}

int returnNetural (int pos){
}

int turn360 (int pos){
  int new_pos = pos + (4096);
  stepper_1.moveTo(new_pos);
  return 0;
}

int turnLeft (int pos){
  
}

void turnRight (int pos){
  
}
