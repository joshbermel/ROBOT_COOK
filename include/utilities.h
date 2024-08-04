#ifndef UTILITIES_H
#define UTILITIES_H

#include <Arduino.h>
#include <ESP32Servo.h>
#include "sensors.h"

void frontStop(int speed, int frontsensorpin, int backsensorpin, Direction touchingSide);
void backStop(int speed, int frontsensorpin, int backsensorpin, Direction touchingSide);
void flipCounters();
void skipLinesAndStop(int linesToSkip, int moveSpeed, Direction moveDirection, Direction touchingSide);
void driveToWall();
void driveStoB(int changeTime);
void driveBtoCB(int changeTime);
void driveCBtoP(int changeTime);
void drivePtoCT(int changeTime);
void driveCTtoB(int changeTime);
void driveCBtoB(int changeTime);
void runThroughCourse();
void pushToWall();


#endif // UTILITIES_H