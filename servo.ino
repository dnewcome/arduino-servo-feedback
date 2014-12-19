#include <AFMotor.h>

AF_DCMotor motor(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
unsigned long lastTime = millis();

void setup() {

 Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Encoder test");
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  
  motor.setSpeed(100);    
  //motor.run(FORWARD);      // turn it on going forward
  //delay(1000);
  //motor.run(RELEASE);      // stopped
  
}

int state = 0;
int state2 = 0;
int clicks = 0;
int clicks2 = 0;

// loop seems to run about 3ms most of the time
void loop() {
  if(state2 != digitalRead(3)) {
    state2 = !state2;
    clicks2++;
  }
    
  if(state != digitalRead(2)) {
    state = !state;
    clicks++;
    if(clicks % 1000 == 0) {
      Serial.println(clicks);
      Serial.println(clicks2);
      Serial.println("------");
    }
    if(clicks > 2000) {
      motor.run(RELEASE);
    }
  }
  else {
    //Serial.println(".....");
  }
}
