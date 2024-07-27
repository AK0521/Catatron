#include<Wire.h>
#include <Adafruit_PWMServoDriver.h>


// Create the PWM driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define SERVONUM_0  0   // The servo channel number on the servo driver
#define SERVONUM_1 1
#define SERVONUM_2 2
#define SERVONUM_3 3

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  Serial.println("Initializing Servo Driver...");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm.setPWM(0,0,angleToPulseLength(90));
  pwm.setPWM(1,0,angleToPulseLength(90));
  pwm.setPWM(2,0,angleToPulseLength(90));
  pwm.setPWM(3,0,angleToPulseLength(90));

  delay(10);

}
int angleToPulseLength(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}
void first_walk_left(int curr_angle[],int angle){
  for(int i=curr_angle[0];i<=curr_angle[0]+angle;i++){
    pwm.setPWM(0,0,angleToPulseLength(i));
    pwm.setPWM(2,0,angleToPulseLength(i));
    //delay(10);
    pwm.setPWM(1,0,angleToPulseLength(180-i));
    pwm.setPWM(3,0,angleToPulseLength(180-i));
    delay(10);
  }
  curr_angle[0]+=angle;
  curr_angle[2]+=angle;
  curr_angle[1]-=angle;
  curr_angle[3]-=angle;

}
void walk_cycle(int curr_angle[],int angle){
  for(int i=curr_angle[1];i<=curr_angle[1]+angle;i++){
    pwm.setPWM(1,0,angleToPulseLength(i));
    pwm.setPWM(3,0,angleToPulseLength(i));
    //delay(10);
    pwm.setPWM(0,0,angleToPulseLength(180-i));
    pwm.setPWM(2,0,angleToPulseLength(180-i));
    delay(10);
  }
  curr_angle[0]-=angle;
  curr_angle[2]-=angle;
  curr_angle[1]+=angle;
  curr_angle[3]+=angle;
  for(int i=curr_angle[0];i<=curr_angle[0]+angle;i++){
    pwm.setPWM(0,0,angleToPulseLength(i));
    pwm.setPWM(2,0,angleToPulseLength(i));
    //delay(10);
    pwm.setPWM(1,0,angleToPulseLength(180-i));
    pwm.setPWM(3,0,angleToPulseLength(180-i));
    delay(10);
  }
  curr_angle[0]+=angle;
  curr_angle[2]+=angle;
  curr_angle[1]-=angle;
  curr_angle[3]-=angle;


}
void last_walk(int curr_angle[],int angle){
  for(int i=curr_angle[0];i>=curr_angle[0]-angle;i--){
    pwm.setPWM(0,0,angleToPulseLength(i));
    pwm.setPWM(2,0,angleToPulseLength(i));
    //delay(10);
    pwm.setPWM(1,0,angleToPulseLength(180-i));
    pwm.setPWM(3,0,angleToPulseLength(180-i));
    delay(10);
  }
  curr_angle[0]-=angle;
  curr_angle[2]-=angle;
  curr_angle[1]+=angle;
  curr_angle[3]+=angle;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
 

  int curr_angle[4];
  for(int i=0;i<4;i++){
    curr_angle[i]=90;
  }
  first_walk_left(curr_angle,30);
  walk_cycle(curr_angle,60);
  last_walk(curr_angle,30);

  // Hold start position for a moment
  delay(500);

}
