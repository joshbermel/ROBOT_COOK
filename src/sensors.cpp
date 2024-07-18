#include "sensors.h"
#include "config.h"

void initializeSensorPins() {
    pinMode(reflectanceSensorLeftPin, INPUT);
    pinMode(reflectanceSensorRightPin, INPUT);
}

int readReflectanceSensor(int SensorPin) {
    // return analogRead(pin1);
    return analogRead(SensorPin);
}

void testBothReflectanceSensor(int leftSensorPin, int rightSensorPin) {
    // return analogRead(pin1);
    Serial.println("Left Pin Reading:");
    Serial.println(analogRead(leftSensorPin));

    Serial.println("Right Pin Reading:");
    Serial.println(analogRead(rightSensorPin));
}

void testSingleReflectanceSensor(int sensorPin) {
    // return analogRead(pin1);
    Serial.println("Sensor pin Reading:");
    Serial.println(analogRead(sensorPin));
}

Direction determineDirection(int leftSensorReading, int rightSensorReading) {
    if (leftSensorReading <= reflectanceThreshold && rightSensorReading <= reflectanceThreshold) {
        return NOT_ON_LINE;
    } else if (abs(leftSensorReading - rightSensorReading) < reflectanceDifferenceThreshold && leftSensorReading > reflectanceThreshold && rightSensorReading > reflectanceThreshold) {
        return CENTERED;
    } else if (leftSensorReading > reflectanceThreshold && rightSensorReading <= reflectanceThreshold) {
        return LEFT;
    } else if (rightSensorReading > reflectanceThreshold && leftSensorReading <= reflectanceThreshold) {
        return RIGHT;
    } else {
        return NOT_ON_LINE;
    }
}

// MONKEY, USE A READING, NOT A PIN
void testDetermineDirection(int leftSensorReading, int rightSensorReading) {
    if (leftSensorReading <= reflectanceThreshold && rightSensorReading <= reflectanceThreshold) {
        Serial.println("NOT_ON_LINE");
    } else if (abs(leftSensorReading - rightSensorReading) < reflectanceDifferenceThreshold && leftSensorReading > reflectanceThreshold && rightSensorReading > reflectanceThreshold) {
        Serial.println("CENTERED");
    } else if (leftSensorReading > reflectanceThreshold && rightSensorReading <= reflectanceThreshold) {
        Serial.println("LEFT");
    } else if (rightSensorReading > reflectanceThreshold && leftSensorReading <= reflectanceThreshold) {
        Serial.println("RIGHT");
    } else {
        Serial.println("NOT_ON_LINE");
    }
}

bool isOnLine(int leftSensorPin, int rightSensorPin) {
    int leftSensorValue = readReflectanceSensor(leftSensorPin);
    int rightSensorValue = readReflectanceSensor(rightSensorPin);
    Direction dir = determineDirection(leftSensorValue, rightSensorValue);
    return dir == CENTERED;
}

void testIsOnLine(int leftSensorPin, int rightSensorPin) {
    int leftSensorValue = readReflectanceSensor(leftSensorPin);
    int rightSensorValue = readReflectanceSensor(rightSensorPin);
    Direction dir = determineDirection(leftSensorValue, rightSensorValue);
    if (dir == CENTERED) {
        Serial.println("centered");
    }
    else {
        Serial.println("not centered");
    }
}