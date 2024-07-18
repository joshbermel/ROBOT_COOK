#include "drive.h"
#include "config.h"

void initializeMotorPins() {
    pinMode(backRightMotorPin1, OUTPUT);
    pinMode(backRightMotorPin2, OUTPUT);
    pinMode(backLeftMotorPin1, OUTPUT);
    pinMode(backLeftMotorPin2, OUTPUT);
    pinMode(frontRightMotorPin1, OUTPUT);
    pinMode(frontRightMotorPin2, OUTPUT);
    pinMode(frontLeftMotorPin1, OUTPUT);
    pinMode(frontLeftMotorPin2, OUTPUT);

    analogWriteFrequency(100);
}

void setMotorSpeed(int pwmPin1, int pwmPin2, bool direction, int speed) {
    if (direction) {
        analogWrite(pwmPin1, speed);
        delay(5);
        analogWrite(pwmPin2, 0);
        delay(5);
    } else {
        analogWrite(pwmPin1, 0);
        delay(5);
        analogWrite(pwmPin2, speed);
        delay(5);
    }
}

void dynamicBrakeMotor(int motorPin1, int motorPin2) {
    int currentSpeed1 = analogRead(motorPin1);
    int currentSpeed2 = analogRead(motorPin2);

    if (currentSpeed1 > 0) {
        analogWrite(motorPin1, 0);
        delay(5);
        analogWrite(motorPin2, 255);
        delay(5);
    } else if (currentSpeed2 > 0) {
        analogWrite(motorPin1, 255);
        delay(5);
        analogWrite(motorPin2, 0);
        delay(5);
    }

    delay(50);
    analogWrite(motorPin1, 0);
    delay(5);
    analogWrite(motorPin2, 0);
    delay(5);
}

void driveForward(int speed) {
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, true, speed);
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, true, speed);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, speed);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, true, speed);
}

void driveBackward(int speed) {
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, false, speed);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, false, speed);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, false, speed);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, false, speed);
}

void driveLeft(int speed) {
    int adjustedSpeed = speed * 1.5;
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, false, speed);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, true, speed);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, speed);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, false, speed);
}

void driveRight(int speed) {
    int adjustedSpeed = speed * 1.5;
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, true, speed);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, false, speed);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, false, speed);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, true, speed);
}

void rotate180() {
    int speed = 150;
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, true, speed);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, false, speed);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, speed);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, false, speed);

    delay(1100);

    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, true, 0);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, false, 0);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, 0);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, false, 0);
}

void stopRobot() {
    dynamicBrakeMotor(frontLeftMotorPin1, frontLeftMotorPin2);
    dynamicBrakeMotor(frontRightMotorPin1, frontRightMotorPin2);
    dynamicBrakeMotor(backLeftMotorPin1, backLeftMotorPin2);
    dynamicBrakeMotor(backRightMotorPin1, backRightMotorPin2);
}

void testDriveForwardBackward() {
    driveForward(255);
    delay(1000);
    setAllMotorsToZero();
    delay(500);

    driveBackward(255);
    delay(1000);
    setAllMotorsToZero();
    delay(500);
}

void testDriveLeftRight() {
    Serial.println("Testing left and right driving...");
    driveLeft(150);
    delay(750);
    setAllMotorsToZero();
    delay(500);

    driveRight(150);
    delay(750);
    setAllMotorsToZero();
    delay(500);
}

void testRotate() {
    Serial.println("Testing rotate 180...");
    rotate180();
    delay(1000);
    setAllMotorsToZero();
    delay(500);
}

void setAllMotorsToZero() {
    analogWrite(backRightMotorPin1, 0);
    analogWrite(backRightMotorPin2, 0);
    analogWrite(backLeftMotorPin1, 0);
    analogWrite(backLeftMotorPin2, 0);
    analogWrite(frontRightMotorPin1, 0);
    analogWrite(frontRightMotorPin2, 0);
    analogWrite(frontLeftMotorPin1, 0);
    analogWrite(frontLeftMotorPin2, 0);
}