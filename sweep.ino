/*
	this is a simple example to set the position of the motor when using the osepp driver board
	where the servo is on port 1, which corresponds to pin 10 ..
	port 2 is pin 9 according to the schematic.
*/

#include <Servo.h> 

 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object 
  myservo.write(90); 
} 
 
 
void loop() 

