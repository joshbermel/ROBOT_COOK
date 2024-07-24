#ifndef DRIVE_H
#define DRIVE_H

#include <Arduino.h>

void initializeMotorPins();
void setMotorSpeed(int motorPin1, int motorPin2, bool direction, float speed);
void dynamicBrakeMotor(int motorPin1, int motorPin2);
void driveForward(int speed);
void driveBackward(int speed);
void driveLeft(int speed);
void driveRight(int speed);
void rotate180(int rotateSpeed, int rotateTime);
void stopRobot();
void testDriveForwardBackward();
void testDriveLeftRight();
void testRotate();
void setAllMotorsToZero();
void stopRobot2();

#endif // DRIVE_H