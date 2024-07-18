#ifndef DRIVE_H
#define DRIVE_H

#include <Arduino.h>

void initializeMotorPins();
void setMotorSpeed(int pwmPin1, int pwmPin2, bool direction, int speed);
void dynamicBrakeMotor(int pwmPin1, int pwmPin2);
void driveForward(int speed);
void driveBackward(int speed);
void driveLeft(int speed);
void driveRight(int speed);
void rotate180();
void stopRobot();
void testDriveForwardBackward();
void testDriveLeftRight();
void testRotate();
void setAllMotorsToZero();

#endif // DRIVE_H