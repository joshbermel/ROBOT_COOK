#ifndef UTILITIES_H
#define UTILITIES_H

#include <Arduino.h>
#include <ESP32Servo.h>
#include "sensors.h"

void frontStop(int speed, int frontsensorpin, int backsensorpin, int reverseTime);
void backStop(int speed, int frontsensorpin, int backsensorpin, int forwardTime);
void flipCounters();
void driveToWall(int speed, int microSwitchPin);
void skipLinesAndStop(int linesToSkip, int moveSpeed, Direction moveDirection, int changeTime);


#endif // UTILITIES_H