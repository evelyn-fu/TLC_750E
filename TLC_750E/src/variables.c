#include "variables.h"
#include "main.h"
#include <math.h>

void drive(int ch1, int ch2, int ch3, int ch4){//a corresponds to the individual analog button axes
  motorSet(MOTOR_BASE_LEFT1_, ch3 + ch2 + ch4 + ch1);
  motorSet(MOTOR_BASE_LEFT2_, ch3 + ch2 - ch4 + ch1);
  motorSet(MOTOR_BASE_RIGHT1_, -(ch3 + ch2 - ch4 - ch1));
  motorSet(MOTOR_BASE_RIGHT2_, -(ch3 + ch2 + ch4 - ch1));
}
void lift(int speed) {
  motorSet(MOTOR_LIFT_LEFT_, -speed);
  motorSet(MOTOR_LIFT_RIGHT_, speed);
}
void pince(int speed) {
  motorSet(MOTOR_PINCE_RIGHT_, -speed);
  motorSet(MOTOR_PINCE_RIGHT_, speed);
}
void driveForwardAuton(Encoder encoder1, Encoder encoder2, int distance) { //distance is in inches
  int goal = distance * 28.66;
  int encoder1start = encoderGet(encoder1);
  int encoder2start = encoderGet(encoder2);
  int encoder1count;
  int encoder2count;
  while(1) {
    encoder1count = (encoderGet(encoder1) / sqrt(2)) - encoder1start;
    encoder2count = (encoderGet(encoder2) / sqrt(2)) - encoder2start;
    if ((encoder1count < goal) && (encoder2count < goal)) {
      motorSet(MOTOR_BASE_LEFT1_, 127);
      motorSet(MOTOR_BASE_LEFT2_, 127);
      motorSet(MOTOR_BASE_RIGHT1_, -127);
      motorSet(MOTOR_BASE_RIGHT2_, -127);
    }
  }
}
void pointTurnAuton(Encoder encoder1, Encoder encoder2, int degrees) {
  int goal = degrees/226.5;
  int encoder1start = encoderGet(encoder1);
  int encoder2start = encoderGet(encoder2);
  int encoder1count;
  int encoder2count;
  while(1) {
    encoder1count = encoderGet(encoder1) - encoder1start;
    encoder2count = encoderGet(encoder2) - encoder2start;
    if ((encoder1count < goal) && (encoder2count < goal)) {
      motorSet(MOTOR_BASE_LEFT1_, 127);
      motorSet(MOTOR_BASE_LEFT2_, 127);
      motorSet(MOTOR_BASE_RIGHT1_, 127);
      motorSet(MOTOR_BASE_RIGHT2_, 127);
    }
  }
}
