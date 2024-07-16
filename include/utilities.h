#ifndef UTILITIES_H
#define UTILITIES_H

#include <Arduino.h>
#include <ESP32Servo.h>
#include "sensors.h"

void leftStop(int speed, int leftSensorPin, int rightSensorPin);
void rightStop(int speed, int leftSensorPin, int rightSensorPin);
void flipCounters(int speed, int leftSensorPin, int rightSensorPin, int microSwitchPin);
void skipLinesAndStop(int leftSensorPin, int rightSensorPin, int linesToSkip, int moveSpeed, Direction moveDirection);
void driveToWall(int speed, int microSwitchPin);

#endif // UTILITIES_H