#include <Arduino.h>
#include "sensors.h"
#include "config.h"

void setup() {
    Serial.begin(115200);
    initializeSensorPins();
    Serial.println("Reflectance Test Setup complete.");
}

void loop() {
    testReadReflectanceSensor(frontReflectanceSensor);
    testReadReflectanceSensor(backReflectanceSensor);
    testDetermineDirection(frontReflectanceSensor, backReflectanceSensor);
    delay(1000);
}

void testReadReflectanceSensor(int sensorPin) {
    int sensorValue = readReflectanceSensor(sensorPin);
    Serial.print("Reflectance sensor reading from pin ");
    Serial.print(sensorPin);
    Serial.print(": ");
    Serial.println(sensorValue);
}

void testDetermineDirection(int leftSensorPin, int rightSensorPin) {
    int leftSensorValue = readReflectanceSensor(leftSensorPin);
    int rightSensorValue = readReflectanceSensor(rightSensorPin);
    Direction direction = determineDirection(leftSensorValue, rightSensorValue);

    switch (direction) {
        case CENTERED:
            Serial.println("Robot is centered on the black line.");
            break;
        case LEFT:
            Serial.println("Robot needs to move left.");
            break;
        case RIGHT:
            Serial.println("Robot needs to move right.");
            break;
        case NOT_ON_LINE:
            Serial.println("Robot is not on the black line.");
            break;
    }
}