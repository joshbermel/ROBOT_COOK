#include "sensors.h"
#include "config.h"

void initializeSensorPins() {
    pinMode(reflectanceSensorLeftPin, INPUT);
    pinMode(reflectanceSensorRightPin, INPUT);
}

int readReflectanceSensor(int pin) {
    return analogRead(pin);
}

Direction determineDirection(int leftSensor, int rightSensor) {
    if (leftSensor >= reflectanceThreshold && rightSensor >= reflectanceThreshold) {
        return NOT_ON_LINE;
    } else if (abs(leftSensor - rightSensor) < reflectanceDifferenceThreshold) {
        return CENTERED;
    } else if (leftSensor < reflectanceThreshold && rightSensor >= reflectanceThreshold) {
        return LEFT;
    } else if (rightSensor < reflectanceThreshold && leftSensor >= reflectanceThreshold) {
        return RIGHT;
    } else if (leftSensor < rightSensor) {
        return LEFT;
    } else {
        return RIGHT;
    }
}

bool isOnLine(int leftSensorPin, int rightSensorPin) {
    int leftSensorValue = readReflectanceSensor(leftSensorPin);
    int rightSensorValue = readReflectanceSensor(rightSensorPin);
    Direction dir = determineDirection(leftSensorValue, rightSensorValue);
    return (dir == CENTERED);
}