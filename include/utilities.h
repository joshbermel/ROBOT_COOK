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
void driveStoB();
void driveBtoCB();
void driveCBtoP();
void drivePtoCT();
void driveCTtoB();
void driveCBtoB();
void runThroughCourse();
void pushToWall();


#endif // UTILITIES_H