#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create the PWM driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define  FL_hip 0   // The servo channel number on the servo driver
#define  FL_knee 1
#define FR_hip 2
#define FR_knee 3
#define BL_hip 4
#define BL_knee 5
#define BR_hip 6
#define BR_knee 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Initializing Servo Driver...");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm.setPWM(0, 0, angleToPulseLength(120));
  pwm.setPWM(1, 0, angleToPulseLength(45));
  pwm.setPWM(2, 0, angleToPulseLength(120));
  pwm.setPWM(3, 0, angleToPulseLength(45));
  pwm.setPWM(4, 0, angleToPulseLength(105));
  pwm.setPWM(5, 0, angleToPulseLength(60));
  pwm.setPWM(6, 0, angleToPulseLength(105));
  pwm.setPWM(7, 0, angleToPulseLength(60));

  delay(10);
}

int angleToPulseLength(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void first_walk_left(int curr_angle[], int FL_hip_angle, int FL_knee_angle, int FR_hip_angle, int FR_knee_angle, int BL_hip_angle, int BL_knee_angle, int BR_hip_angle, int BR_knee_angle) {
  float FL_ratio_left = FL_knee_angle / FL_hip_angle;
  float FR_ratio_hip = FR_hip_angle / FL_hip_angle;
  float FR_ratio_knee = FR_knee_angle / FL_hip_angle;
  float BL_ratio_hip = BL_hip_angle / FL_hip_angle;
  float BL_ratio_knee = BL_knee_angle / FL_hip_angle;
  float BR_ratio_hip = BR_hip_angle / FL_hip_angle;
  float BR_ratio_knee = BR_knee_angle / FL_hip_angle;

  for (int i = 0; i <= FL_hip_angle; i++) {
    pwm.setPWM(0, 0, angleToPulseLength(-i + curr_angle[0]));
    pwm.setPWM(1, 0, angleToPulseLength(+FL_ratio_left * i + curr_angle[1]));
    pwm.setPWM(2, 0, angleToPulseLength(+FR_ratio_hip * i + curr_angle[2]));
    pwm.setPWM(3, 0, angleToPulseLength(+FR_ratio_knee * i + curr_angle[3]));
    pwm.setPWM(4, 0, angleToPulseLength(-BL_ratio_hip * i + curr_angle[4]));
    pwm.setPWM(5, 0, angleToPulseLength(-BL_ratio_knee * i + curr_angle[5]));
    pwm.setPWM(6, 0, angleToPulseLength(+BR_ratio_hip * i + curr_angle[6]));
    pwm.setPWM(7, 0, angleToPulseLength(+BR_ratio_knee * i + curr_angle[7]));

    delay(10);
  }
  
  curr_angle[0] -= FL_hip_angle;
  curr_angle[1] += FL_knee_angle;
  curr_angle[2] += FR_hip_angle;
  curr_angle[3] += FR_knee_angle;
  curr_angle[4] -= BL_hip_angle;
  curr_angle[5] -= BL_knee_angle;
  curr_angle[6] += BR_hip_angle;
  curr_angle[7] += BR_knee_angle;

  // Print current angles
  printCurrentAngles(curr_angle);
}

void walk_cycle(int curr_angle[], int FL_hip_angle, int FL_knee_angle, int FR_hip_angle, int FR_knee_angle, int BL_hip_angle, int BL_knee_angle, int BR_hip_angle, int BR_knee_angle) {
  float FL_ratio_left = FL_knee_angle / FL_hip_angle;
  float FR_ratio_hip = FR_hip_angle / FL_hip_angle;
  float FR_ratio_knee = FR_knee_angle / FL_hip_angle;
  float BL_ratio_hip = BL_hip_angle / FL_hip_angle;
  float BL_ratio_knee = BL_knee_angle / FL_hip_angle;
  float BR_ratio_hip = BR_hip_angle / FL_hip_angle;
  float BR_ratio_knee = BR_knee_angle / FL_hip_angle;

  for (int i = 0; i <= FL_hip_angle; i++) {
    pwm.setPWM(0, 0, angleToPulseLength(+i + curr_angle[0]));
    pwm.setPWM(1, 0, angleToPulseLength(+FL_ratio_left * i + curr_angle[1]));
    pwm.setPWM(2, 0, angleToPulseLength(-FR_ratio_hip * i + curr_angle[2]));
    pwm.setPWM(3, 0, angleToPulseLength(-FR_ratio_knee * i + curr_angle[3]));
    pwm.setPWM(4, 0, angleToPulseLength(BL_ratio_hip * i + curr_angle[4]));
    pwm.setPWM(5, 0, angleToPulseLength(-BL_ratio_knee * i + curr_angle[5]));
    pwm.setPWM(6, 0, angleToPulseLength(+BR_ratio_hip * i + curr_angle[6]));
    pwm.setPWM(7, 0, angleToPulseLength(-BR_ratio_knee * i + curr_angle[7]));
    delay(10);
  }
  
  curr_angle[0] += FL_hip_angle;
  curr_angle[1] += FL_knee_angle;
  curr_angle[2] -= FR_hip_angle;
  curr_angle[3] -= FR_knee_angle;
  curr_angle[4] += BL_hip_angle;
  curr_angle[5] -= BL_knee_angle;
  curr_angle[6] += BR_hip_angle;
  curr_angle[7] -= BR_knee_angle;

  // Print current angles
  printCurrentAngles(curr_angle);
  
  for (int i = 0; i <= FL_hip_angle; i++) {
    pwm.setPWM(0, 0, angleToPulseLength(-i + curr_angle[0]));
    pwm.setPWM(1, 0, angleToPulseLength(-FL_ratio_left * i + curr_angle[1]));
    pwm.setPWM(2, 0, angleToPulseLength(+FR_ratio_hip * i + curr_angle[2]));
    pwm.setPWM(3, 0, angleToPulseLength(+FR_ratio_knee * i + curr_angle[3]));
    pwm.setPWM(4, 0, angleToPulseLength(-BL_ratio_hip * i + curr_angle[4]));
    pwm.setPWM(5, 0, angleToPulseLength(+BL_ratio_knee * i + curr_angle[5]));
    pwm.setPWM(6, 0, angleToPulseLength(-BR_ratio_hip * i + curr_angle[6]));
    pwm.setPWM(7, 0, angleToPulseLength(+BR_ratio_knee * i + curr_angle[7]));
    delay(10);
  }

  curr_angle[0] -= FL_hip_angle;
  curr_angle[1] -= FL_knee_angle;
  curr_angle[2] += FR_hip_angle;
  curr_angle[3] += FR_knee_angle;
  curr_angle[4] -= BL_hip_angle;
  curr_angle[5] += BL_knee_angle;
  curr_angle[6] -= BR_hip_angle;
  curr_angle[7] += BR_knee_angle;

  // Print current angles
  printCurrentAngles(curr_angle);
}

void last_walk(int curr_angle[], int FL_hip_angle, int FL_knee_angle, int FR_hip_angle, int FR_knee_angle, int BL_hip_angle, int BL_knee_angle, int BR_hip_angle, int BR_knee_angle) {
  float FL_ratio_left = FL_knee_angle / FL_hip_angle;
  float FR_ratio_hip = FR_hip_angle / FL_hip_angle;
  float FR_ratio_knee = FR_knee_angle / FL_hip_angle;
  float BL_ratio_hip = BL_hip_angle / FL_hip_angle;
  float BL_ratio_knee = BL_knee_angle / FL_hip_angle;
  float BR_ratio_hip = BR_hip_angle / FL_hip_angle;
  float BR_ratio_knee = BR_knee_angle / FL_hip_angle;

  for (int i = 0; i <= FL_hip_angle; i++) {
    pwm.setPWM(0, 0, angleToPulseLength(+i + curr_angle[0]));
    pwm.setPWM(1, 0, angleToPulseLength(-FL_ratio_left * i + curr_angle[1]));
    pwm.setPWM(2, 0, angleToPulseLength(-FR_ratio_hip * i + curr_angle[2]));
    pwm.setPWM(3, 0, angleToPulseLength(-FR_ratio_knee * i + curr_angle[3]));
    pwm.setPWM(4, 0, angleToPulseLength(+BL_ratio_hip * i + curr_angle[4]));
    pwm.setPWM(5, 0, angleToPulseLength(+BL_ratio_knee * i + curr_angle[5]));
    pwm.setPWM(6, 0, angleToPulseLength(-BR_ratio_hip * i + curr_angle[6]));
    pwm.setPWM(7, 0, angleToPulseLength(-BR_ratio_knee * i + curr_angle[7]));
    delay(10);
  }

  curr_angle[0] += FL_hip_angle;
  curr_angle[1] -= FL_knee_angle;
  curr_angle[2] -= FR_hip_angle;
  curr_angle[3] -= FR_knee_angle;
  curr_angle[4] += BL_hip_angle;
  curr_angle[5] += BL_knee_angle;
  curr_angle[6] -= BR_hip_angle;
  curr_angle[7] -= BR_knee_angle;

  // Print current angles
  printCurrentAngles(curr_angle);
}

void loop() {
  int curr_angle[8] = {120, 45, 120, 45, 105, 60, 105, 60};
  
  // Example walking pattern
 first_walk_left(curr_angle,45,15,15,60,10,20,30,45);
  walk_cycle(curr_angle,60,45,60,45,40,65,40,65);
  last_walk(curr_angle,45,15,15,60,10,20,30,45);

}

void printCurrentAngles(int curr_angle[]) {
 
  for (int i = 0; i < 8; i++) {
    Serial.print(curr_angle[i]);
    Serial.print(" ");
  }
  Serial.println();
}
