

/**
 * Overview | Arduino Lesson 16. Stepper Motors | Adafruit Learning System
 * https://learn.adafruit.com/adafruit-arduino-lesson-16-stepper-motors?view=all
 *
 * Adafruit Arduino - Lesson 16. Stepper
 */
#include <Stepper.h>
int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;
int numberOfSteppsPerRevolution = 512;
Stepper motor(numberOfSteppsPerRevolution, in1Pin, in2Pin, in3Pin, in4Pin);
void setup(){
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  Serial.begin(9600);
  motor.setSpeed(50);
}
void loop(){
  if (Serial.available()>0){
    int steps = Serial.parseInt();
    motor.step(steps);
  }
}
