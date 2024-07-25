#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

enum Direction {
    FORWARD,
    BACKWARD,
    CENTERED,
    NOT_ON_LINE,
    LEFT,
    RIGHT
};

void initializeSensorPins();
bool readReflectanceSensor(int pin);
Direction determineDirection(int frontSensorPin, int backSensorPin);
bool isOnLine();
void testBothReflectanceSensor();
void testSingleReflectanceSensor(int sensorPin);
void testDetermineDirection(int frontSensorPin, int backSensotPin);
void testIsOnLine();

#endif // SENSORS_H