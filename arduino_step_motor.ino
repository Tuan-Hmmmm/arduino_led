#include <Stepper.h>
 int k=0;
 int n=0;
const int stepsPerRevolution = 2048;  // hehe
 int ledr=7;
 int ledg=6;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
 
void setup() {
 pinMode(ledr, OUTPUT);
 pinMode(ledg, OUTPUT);
  myStepper.setSpeed(15);
  Serial.begin(9600);
}
 
void loop() {
 {
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  digitalWrite(ledg, 1);
  digitalWrite(ledr, 0);
  delay(500);
 }
 
 { Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  digitalWrite(ledg, 0);
  digitalWrite(ledr, 1);
  delay(500);
 }
  
  

}