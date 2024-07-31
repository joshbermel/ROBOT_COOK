#ifndef UTILITIES_H
#define UTILITIES_H

#include <Arduino.h>
#include <ESP32Servo.h>
#include "sensors.h"

void frontStop(int speed, int frontsensorpin, int backsensorpin, int ReverseTime);
void backStop(int speed, int frontsensorpin, int backsensorpin);
void flipCounters();
void driveToWall(int speed, int microSwitchPin);
void skipLinesAndStop2(int linesToSkip, int moveSpeed, Direction moveDirection, int reverseTime);

#endif // UTILITIES_H