#include <Stepper.h>
#define  STEPS  720    // steps per revolution (limited to 315°)
#define  COIL1  0
#define  COIL2  1
#define  COIL3  2
#define  COIL4  4

#define PotIn  3

// create an instance of the stepper class:
Stepper stepper(STEPS, COIL1, COIL2, COIL3, COIL4);

void setup(){
  stepper.setSpeed(30);    // set the motor RPM
  stepper.step(630);      //Reset Position(630 steps counter-clockwise).
  delay(50);
}
int pos=0;                 //Position in steps(0-630)= (0°-315°)

void loop(){
  int val = analogRead(PotIn);   //get the potentiometer value (range 0-1023)
  val= map(val,0,1023,100,630);    // map pot range in the stepper range. 100 so it dosent over travle on the gauge
  if(abs(val - pos)> 2){         //if diference is greater than 2 steps.
      if((val - pos)> 0){
          stepper.step(-1);      // move one step to the left.
          pos++;
          }
      if((val - pos)< 0){
          stepper.step(1);       // move one step to the right.
          pos--;
          }
      }

}
