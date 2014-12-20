#include <AFMotor.h>

AF_DCMotor motor(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
unsigned long lastTime = millis();

void setup() {

  
 Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Encoder test");
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(0, doEncoder, RISING);
  
  motor.setSpeed(255);
}

volatile int state = 0;
volatile int state2 = 0;
volatile int clicks = 0;
volatile int clicks2 = 0;
volatile int dir = 0;
volatile int pos = 0;

void loop() {
  if(pos > 10) {
    motor.run(FORWARD);
  }
  else if(pos < -10) {
    motor.run(BACKWARD);
  }
  else {
    motor.run(RELEASE);
  }
}

// loop seems to run about 3ms most of the time
void doEncoder() {
  noInterrupts();
  
  dir = digitalRead(3) ? 1 : -1;
  
  
  clicks++;
  pos += dir;
  
  // freezes interrupts if too much data
  // sent to serial port..
  // Serial.println(pos); 
   
  /*
  if(clicks % 1000 == 0) {
    Serial.println(clicks);
    Serial.println(clicks2);
    Serial.println("------");
  }
  */
  interrupts();
}
