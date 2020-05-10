int Pin0 = 8;
int Pin1 = 9;
int Pin2 = 10;
int Pin3 = 11;

int motorStep = 0;

char serialInput;

void setup() {
  Serial.begin(9600);
  pinMode(Pin0, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){
    serialInput = Serial.read();

    if (serialInput == '1'){
      motorStep = motorStep + 1;
      if(motorStep > 7){
        motorStep = 0;
      }
    } else {
      motorStep = motorStep - 1;
      if (motorStep < 0){
        motorStep = 7;
      }
    }
    
    //in the format of {Pin3,Pin2,Pin1,Pin0}
    switch(motorStep){
      case 0:
        digitalWrite(Pin0, LOW);  
        digitalWrite(Pin1, LOW); 
        digitalWrite(Pin2, LOW); 
        digitalWrite(Pin3, HIGH); 
        break;
      case 1:
        digitalWrite(Pin0, LOW);  
        digitalWrite(Pin1, LOW); 
        digitalWrite(Pin2, HIGH); 
        digitalWrite(Pin3, HIGH); 
        break;
      case 2:
        digitalWrite(Pin0, LOW);  
        digitalWrite(Pin1, LOW); 
        digitalWrite(Pin2, HIGH); 
        digitalWrite(Pin3, LOW); 
        break;
      case 3:
        digitalWrite(Pin0, LOW);  
        digitalWrite(Pin1, HIGH); 
        digitalWrite(Pin2, HIGH); 
        digitalWrite(Pin3, LOW); 
        break;
      case 4:
        digitalWrite(Pin0, LOW);  
        digitalWrite(Pin1, HIGH); 
        digitalWrite(Pin2, LOW); 
        digitalWrite(Pin3, LOW); 
        break;
      case 5:
        digitalWrite(Pin0, HIGH);  
        digitalWrite(Pin1, HIGH); 
        digitalWrite(Pin2, LOW); 
        digitalWrite(Pin3, LOW); 
        break;
      case 6:
        digitalWrite(Pin0, HIGH);  
        digitalWrite(Pin1, LOW); 
        digitalWrite(Pin2, LOW); 
        digitalWrite(Pin3, LOW); 
        break;
      case 7:
        digitalWrite(Pin0, HIGH);  
        digitalWrite(Pin1, LOW); 
        digitalWrite(Pin2, LOW); 
        digitalWrite(Pin3, LOW); 
        break;
      default:
        digitalWrite(Pin0, LOW);  
        digitalWrite(Pin1, LOW); 
        digitalWrite(Pin2, LOW); 
        digitalWrite(Pin3, LOW);
        break; 
    }
    delay(1);
  }
}
