#include<Wire.h>
#include <Adafruit_PWMServoDriver.h>


// Create the PWM driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define  FL_hip 0   // The servo channel number on the servo driver
#define  FL_knee 1
#define FR_hip 2
#define FR_knee 3

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  Serial.println("Initializing Servo Driver...");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm.setPWM(0,0,angleToPulseLength(120));
  pwm.setPWM(1,0,angleToPulseLength(45));
  pwm.setPWM(2,0,angleToPulseLength(120));
  pwm.setPWM(3,0,angleToPulseLength(45));

  delay(10);

}
int angleToPulseLength(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}
void first_walk_left(int curr_angle[],int FL_hip_angle,int FL_knee_angle,int FR_hip_angle,int FR_knee_angle){
    float ratio_left=FL_knee_angle/FL_hip_angle;
    float ratio_right_hip=FR_hip_angle/FL_hip_angle;
    float ratio_right_knee=FR_knee_angle/FL_hip_angle;
  for(int i=0;i<=FL_hip_angle;i++){
    pwm.setPWM(0,0,angleToPulseLength(i+curr_angle[0]));
    pwm.setPWM(1,0,angleToPulseLength(-ratio_left*i+curr_angle[1]));
    //delay(10);
    pwm.setPWM(2,0,angleToPulseLength(-ratio_right_hip*i+curr_angle[2]));
    pwm.setPWM(3,0,angleToPulseLength(-ratio_right_knee*i+curr_angle[3]));
    delay(10);
  }
  pwm.setPWM(0,0,angleToPulseLength(curr_angle[0]+FL_hip_angle));
  pwm.setPWM(1,0,angleToPulseLength(curr_angle[1]-FL_knee_angle));
  pwm.setPWM(2,0,angleToPulseLength(curr_angle[2]-FR_hip_angle));
  pwm.setPWM(3,0,angleToPulseLength(curr_angle[3]-FR_knee_angle));

  curr_angle[0]+=FL_hip_angle;
  curr_angle[1]-=FL_knee_angle;
  curr_angle[2]-=FR_hip_angle;
  curr_angle[3]-=FR_knee_angle;

}
void walk_cycle(int curr_angle[],int FL_hip_angle,int FL_knee_angle,int FR_hip_angle,int FR_knee_angle){
  float ratio_left=FL_knee_angle/FL_hip_angle;
    float ratio_right_hip=FR_hip_angle/FL_hip_angle;
    float ratio_right_knee=FR_knee_angle/FL_hip_angle;
  for(int i=0;i<=FL_hip_angle;i++){
    pwm.setPWM(0,0,angleToPulseLength(-i+curr_angle[0]));
    pwm.setPWM(1,0,angleToPulseLength(-ratio_left*i+curr_angle[1]));
    //delay(10);
    pwm.setPWM(2,0,angleToPulseLength(+ratio_right_hip*i+curr_angle[2]));
    pwm.setPWM(3,0,angleToPulseLength(+ratio_right_knee*i+curr_angle[3]));
    delay(10);
  }
  pwm.setPWM(0,0,angleToPulseLength(curr_angle[0]-FL_hip_angle));
  pwm.setPWM(1,0,angleToPulseLength(curr_angle[1]-FL_knee_angle));
  pwm.setPWM(2,0,angleToPulseLength(curr_angle[2]+FR_hip_angle));
  pwm.setPWM(3,0,angleToPulseLength(curr_angle[3]+FR_knee_angle));

  curr_angle[0]-=FL_hip_angle;
  curr_angle[1]-=FL_knee_angle;
  curr_angle[2]+=FR_hip_angle;
  curr_angle[3]+=FR_knee_angle;


  
  for(int i=0;i<=FL_hip_angle;i++){
    pwm.setPWM(0,0,angleToPulseLength(i+curr_angle[0]));
    pwm.setPWM(1,0,angleToPulseLength(ratio_left*i+curr_angle[1]));
    //delay(10);
    pwm.setPWM(2,0,angleToPulseLength(-ratio_right_hip*i+curr_angle[2]));
    pwm.setPWM(3,0,angleToPulseLength(-ratio_right_knee*i+curr_angle[3]));
    delay(10);
  }
  pwm.setPWM(0,0,angleToPulseLength(curr_angle[0]+FL_hip_angle));
  pwm.setPWM(1,0,angleToPulseLength(curr_angle[1]+FL_knee_angle));
  pwm.setPWM(2,0,angleToPulseLength(curr_angle[2]-FR_hip_angle));
  pwm.setPWM(3,0,angleToPulseLength(curr_angle[3]-FR_knee_angle));

  curr_angle[0]+=FL_hip_angle;
  curr_angle[1]+=FL_knee_angle;
  curr_angle[2]-=FR_hip_angle;
  curr_angle[3]-=FR_knee_angle;

}
void last_walk(int curr_angle[],int FL_hip_angle,int FL_knee_angle,int FR_hip_angle,int FR_knee_angle){
   float ratio_left=FL_knee_angle/FL_hip_angle;
    float ratio_right_hip=FR_hip_angle/FL_hip_angle;
    float ratio_right_knee=FR_knee_angle/FL_hip_angle;
  for(int i=0;i<=FL_hip_angle;i++){
    pwm.setPWM(0,0,angleToPulseLength(-i+curr_angle[0]));
    pwm.setPWM(1,0,angleToPulseLength(+ratio_left*i+curr_angle[1]));
    //delay(10);
    pwm.setPWM(2,0,angleToPulseLength(+ratio_right_hip*i+curr_angle[2]));
    pwm.setPWM(3,0,angleToPulseLength(+ratio_right_knee*i+curr_angle[3]));
    delay(10);
  }
  pwm.setPWM(0,0,angleToPulseLength(curr_angle[0]-FL_hip_angle));
  pwm.setPWM(1,0,angleToPulseLength(curr_angle[1]+FL_knee_angle));
  pwm.setPWM(2,0,angleToPulseLength(curr_angle[2]+FR_hip_angle));
  pwm.setPWM(3,0,angleToPulseLength(curr_angle[3]+FR_knee_angle));

  curr_angle[0]-=FL_hip_angle;
  curr_angle[1]+=FL_knee_angle;
  curr_angle[2]+=FR_hip_angle;
  curr_angle[3]+=FR_knee_angle;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
 

  int curr_angle[4];
  curr_angle[0]=120;
  curr_angle[1]=45;
  curr_angle[2]=120;
  curr_angle[3]=45;
  first_walk_left(curr_angle,45,15,15,60);
  walk_cycle(curr_angle,60,45,60,45);
  last_walk(curr_angle,45,15,15,60);

  // Hold start position for a moment
  delay(500);

}
