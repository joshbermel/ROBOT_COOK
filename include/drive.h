#ifndef DRIVE_H
#define DRIVE_H

#include <Arduino.h>

void initializeMotorPins();
void setMotorSpeed(int pwmChannel1, int pwmChannel2, bool direction, int speed);
void dynamicBrakeMotor(int pwmChannel1, int pwmChannel2);
void driveForward(int speed);
void driveBackward(int speed);
void driveLeft(int speed);
void driveRight(int speed);
void rotate180();
void stopRobot();
void testDriveForwardBackward();
void testDriveLeftRight();
void testRotate();

#endif // DRIVE_H