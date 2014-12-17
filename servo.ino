#include <AFMotor.h>

AF_DCMotor motor(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
unsigned long lastTime = millis();

void setup() {

 Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Encoder test");
  pinMode(2, INPUT_PULLUP);
  
  
  motor.setSpeed(255);    
  motor.run(FORWARD);      // turn it on going forward
  //delay(1000);
  //motor.run(RELEASE);      // stopped
  
}

int state = 0;
int clicks = 0;
void loop() {
  delay(20);
  unsigned long thisTime = millis();
  Serial.println(thisTime - lastTime);
  lastTime = thisTime;
  digitalRead(2);
  if(state != digitalRead(2)) {
    state = !state;
    clicks++;
    //Serial.println(clicks);
    if(clicks > 2000) {
      motor.run(RELEASE);
    }
  }
}
