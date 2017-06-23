#ifndef INCLUDE_VARIABLES_H_
#define INCLUDE_VARIABLES_H_

#include "main.h"

#define MOTOR_BASE_RIGHT1_ 2
#define MOTOR_BASE_RIGHT2_ 3
#define MOTOR_BASE_LEFT1_ 4
#define MOTOR_BASE_LEFT2_ 5
#define MOTOR_LIFT_LEFT_ 6
#define MOTOR_LIFT_RIGHT_ 7
#define MOTOR_PINCE_LEFT_ 8
#define MOTOR_PINCE_RIGHT_ 9
#define ENCODER_LEFT_TOP_ 1
#define ENCODER_RIGHT_TOP_ 2
#define ENCODER_LEFT_BOT_ 3
#define ENCODER_RIGHT_BOT_ 4

Encoder encoderLeft;
Encoder encoderRight;

void drive(int ch1, int ch2, int ch3, int ch4);
void lift(int speed);
void pince(int speed);
void pointTurnAuton(Encoder encoder1, Encoder encoder2, int distance);
void driveForwardAuton(Encoder encoder1, Encoder encoder2, int degrees);

#endif
