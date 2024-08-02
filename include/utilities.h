#ifndef UTILITIES_H
#define UTILITIES_H

#include <Arduino.h>
#include <ESP32Servo.h>
#include "sensors.h"

void frontStop(int speed, int frontsensorpin, int backsensorpin, int reverseTime, Direction touchingSide);
void backStop(int speed, int frontsensorpin, int backsensorpin, int forwardTime, Direction touchingSide);
void flipCounters();
void driveToWall(int speed, int microSwitchPin);
void skipLinesAndStop(int linesToSkip, int moveSpeed, Direction moveDirection, int changeTime, Direction touchingSide);
void driveToWall2();
void driveStoB(int changeTime);
void driveBtoCB(int changeTime);
void driveCBtoP(int changeTime);
void drivePtoCT(int changeTime);
void driveCTtoB(int changeTime);
void driveCBtoB(int changeTime);
void runThroughCourse();


#endif // UTILITIES_H