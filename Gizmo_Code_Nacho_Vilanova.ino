#include <AccelStepper.h>
#define HALFSTEP 8

// motor pins
#define motorPin1  8     // Motor 1
#define motorPin2  9   
#define motorPin3  10   
#define motorPin4  11    

#define motorPin5  4    // Motor 2
#define motorPin6  5    
#define motorPin7  6   
#define motorPin8  7   

AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4); // Pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

// variables
int turnSteps = 2100; 
int lineSteps = 2100; // The number of steps to drive straight
int stepperSpeed = 1250; // The speed of the stepper (steps per second)
int steps1 = 0; // To keep track of the step count for motor 1
int steps2 = 0; 
float delay_time;
int val = 0;
int s= 0;
void setup() {
  
  Serial.begin(9600);
  stepper1.setMaxSpeed(2000.0);
  stepper1.move(-1);  // I found this necessary
  stepper2.setMaxSpeed(2000.0);
  stepper2.move(-1);  // Same
}
void loop() {
    val=analogRead(A0);
s=map(val,0,1000,0,2000);
Serial.println(s);
  int target;
  
    target = lineSteps;
    stepper1.move(target);
    stepper1.setSpeed(s);
    
    target = lineSteps;
    stepper2.move(target);
    stepper2.setSpeed(s);
    
  steps1 = stepper1.distanceToGo();
  steps2 = stepper1.distanceToGo();

  stepper1.runSpeedToPosition();
  stepper2.runSpeedToPosition();
}
