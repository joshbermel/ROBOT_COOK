#include <Arduino.h>
#include "drive.h"

int driveSpeed = 500;

void setup() {
    Serial.begin(115200);
    initializeMotorPins();
    Serial.println("Drive Test Setup complete.");
}

void loop() {
    testDriveForwardBackward();
    delay(3000);
    testDriveLeftRight();
    delay(3000);
    testRotate();
    delay(3000);
}

void testDriveForwardBackward() {
    Serial.println("Testing forward and backward driving...");
    driveForward(driveSpeed);
    delay(1000);
    stopRobot();
    delay(500);

    driveBackward(driveSpeed);
    delay(1000);
    stopRobot();
    delay(500);
}

void testDriveLeftRight() {
    Serial.println("Testing left and right driving...");
    driveLeft(driveSpeed);
    delay(1000);
    stopRobot();
    delay(500);

    driveRight(driveSpeed);
    delay(1000);
    stopRobot();
    delay(500);
}

void testRotate() {
    Serial.println("Testing rotate 180...");
    rotate180();
    delay(1000);
    stopRobot();
    delay(500);
}