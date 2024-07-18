#ifndef DRIVE_H
#define DRIVE_H

#include <Arduino.h>

void initializeMotorPins();
void setMotorSpeed(int motorPin1, int motorPin2, bool direction, int speed);
void dynamicBrakeMotor(int motorPin1, int motorPin2);
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
void stopRobot2();
void dynamicBrakeMotor2(int motorPin1A, int motorPin1B, int motorPin2A, int motorPin2B, int motorPin3A, int motorPin3B, int motorPin4A, int motorPin4B);


#endif // DRIVE_H