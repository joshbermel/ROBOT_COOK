#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

enum Direction {
    LEFT,
    RIGHT,
    CENTERED,
    NOT_ON_LINE
};

void initializeSensorPins();
bool readReflectanceSensor(int pin);
Direction determineDirection(int leftSensor, int rightSensor);
bool isOnLine(int leftSensorPin, int rightSensorPin);
void testBothReflectanceSensor(int leftSensorPin, int rightSensorPin);
void testSingleReflectanceSensor(int sensorPin);
void testDetermineDirection(int leftSensorReading, int rightSensorReading);
void testIsOnLine(int leftSensorPin, int rightSensorPin);

#endif // SENSORS_H