#include <Arduino.h>
#include "drive.h"
#include "sensors.h"
#include "config.h"

int crawlSpeed = 100;

void setup() {
    Serial.begin(115200);
    initializeMotorPins();
    initializeSensorPins();
    Serial.println("Reflectance Drive Test Setup Complete.");
}

void loop() {
    // testLeftStop(driveSpeed, frontReflectanceSensor, reflectanceSensorRightPin);
    delay(4000);
    // testRightStop(driveSpeed, reflectanceSensorLeftPin, reflectanceSensorRightPin);
    delay(4000);
    // testBackwardStop(driveSpeed, reflectanceSensorLeftPin, reflectanceSensorRightPin);
    delay(4000);
}

void testLeftStop(int speed, int leftSensorPin, int rightSensorPin) {
    while (true) {
        int leftSensorValue = readReflectanceSensor(leftSensorPin);
        int rightSensorValue = readReflectanceSensor(rightSensorPin);
        Direction dir = determineDirection(leftSensorValue, rightSensorValue);

        if (dir == CENTERED) {
            stopRobot();
            Serial.println("Robot is centered on the line.");
            break;
        } else if (dir == LEFT) {
            Serial.println("Robot needs to move left.");
            driveLeft(crawlSpeed);
        } else if (dir == RIGHT) {
            Serial.println("Robot needs to move right.");
            driveRight(crawlSpeed);
        } else {
            Serial.println("Robot is not on the line, moving left.");
            driveLeft(speed);
        }
        delay(50);
    }
}

void testRightStop(int speed, int leftSensorPin, int rightSensorPin) {
    while (true) {
        int leftSensorValue = readReflectanceSensor(leftSensorPin);
        int rightSensorValue = readReflectanceSensor(rightSensorPin);
        Direction dir = determineDirection(leftSensorValue, rightSensorValue);

        if (dir == CENTERED) {
            stopRobot();
            Serial.println("Robot is centered on the line.");
            break;
        } else if (dir == LEFT) {
            Serial.println("Robot needs to move left.");
            driveLeft(crawlSpeed);
        } else if (dir == RIGHT) {
            Serial.println("Robot needs to move right.");
            driveRight(crawlSpeed);
        } else {
            Serial.println("Robot is not on the line, moving right.");
            driveRight(speed);
        }
        delay(50);
    }
}

void testBackwardStop(int speed, int leftSensorPin, int rightSensorPin) {
    bool rotating = false;
    while (true) {
        if (!rotating) {
            int leftSensorValue = readReflectanceSensor(leftSensorPin);
            int rightSensorValue = readReflectanceSensor(rightSensorPin);
            Direction dir = determineDirection(leftSensorValue, rightSensorValue);

            if (dir == CENTERED) {
                stopRobot();
                Serial.println("Robot is centered on the line, time to rotate");
                rotate180(rotateSpeed, rotateTime);
                rotating = true;
                delay(1000);
            } else {
                Serial.println("Robot hasn't reached the line yet, continuing reverse");
                driveBackward(speed);
            }
        } else {
            driveForward(speed);
            delay(1000);
            stopRobot();
            Serial.println("Robot has reached the next counter, stopping.");
            break;
        }
        delay(50);
    }
}