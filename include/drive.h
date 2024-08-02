#ifndef DRIVE_H
#define DRIVE_H

#include <Arduino.h>

void initializeMotorPins();
void setMotorSpeed(int motorPin1, int motorPin2, bool direction, float speed);
void dynamicBrakeMotor(int motorPin1, int motorPin2);
void driveForwardStraight(int speed);
void driveForwardLeft(int speed);
void driveForwardRight(int speed);
void driveBackwardStraight(int speed);
void driveBackwardLeft(int speed);
void driveBackwardRight(int speed);
void driveLeft(int speed);
void driveRight(int speed);
void rotate180(int rotateSpeed, int rotateTime);
void stopRobot();
void testDriveForwardBackward();
void testDriveLeftRight();
void testRotate();
void setAllMotorsToZero();
void stopRobot2();
void reverseBackward(int speed);
void reverseForward(int speed);

#endif // DRIVE_H