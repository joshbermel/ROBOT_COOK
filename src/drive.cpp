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

    ledcSetup(backRightPwmChannel1, pwmFrequency, pwmResolution);
    ledcSetup(backRightPwmChannel2, pwmFrequency, pwmResolution);
    ledcSetup(backLeftPwmChannel1, pwmFrequency, pwmResolution);
    ledcSetup(backLeftPwmChannel2, pwmFrequency, pwmResolution);
    ledcSetup(frontRightPwmChannel1, pwmFrequency, pwmResolution);
    ledcSetup(frontRightPwmChannel2, pwmFrequency, pwmResolution);
    ledcSetup(frontLeftPwmChannel1, pwmFrequency, pwmResolution);
    ledcSetup(frontLeftPwmChannel2, pwmFrequency, pwmResolution);

    ledcAttachPin(backRightMotorPin1, backRightPwmChannel1);
    ledcAttachPin(backRightMotorPin2, backRightPwmChannel2);
    ledcAttachPin(backLeftMotorPin1, backLeftPwmChannel1);
    ledcAttachPin(backLeftMotorPin2, backLeftPwmChannel2);
    ledcAttachPin(frontRightMotorPin1, frontRightPwmChannel1);
    ledcAttachPin(frontRightMotorPin2, frontRightPwmChannel2);
    ledcAttachPin(frontLeftMotorPin1, frontLeftPwmChannel1);
    ledcAttachPin(frontLeftMotorPin2, frontLeftPwmChannel2);
}

void setMotorSpeed(int pwmChannel1, int pwmChannel2, bool direction, int speed) {
    if (direction) {
        ledcWrite(pwmChannel1, speed);
        ledcWrite(pwmChannel2, 0);
    } else {
        ledcWrite(pwmChannel1, 0);
        ledcWrite(pwmChannel2, speed);
    }
}

void dynamicBrakeMotor(int pwmChannel1, int pwmChannel2) {
    int currentSpeed1 = ledcRead(pwmChannel1);
    int currentSpeed2 = ledcRead(pwmChannel2);

    if (currentSpeed1 > 0) {
        ledcWrite(pwmChannel1, 0);
        ledcWrite(pwmChannel2, 1023);
    } else if (currentSpeed2 > 0) {
        ledcWrite(pwmChannel1, 1023);
        ledcWrite(pwmChannel2, 0);
    }

    delay(20);
    ledcWrite(pwmChannel1, 0);
    ledcWrite(pwmChannel2, 0);
}

void driveForward(int speed) {
    setMotorSpeed(frontLeftPwmChannel1, frontLeftPwmChannel2, true, speed);
    setMotorSpeed(frontRightPwmChannel1, frontRightPwmChannel2, true, speed);
    setMotorSpeed(backLeftPwmChannel1, backLeftPwmChannel2, true, speed);
    setMotorSpeed(backRightPwmChannel1, backRightPwmChannel2, true, speed);
}

void driveBackward(int speed) {
    setMotorSpeed(frontLeftPwmChannel1, frontLeftPwmChannel2, false, speed);
    setMotorSpeed(frontRightPwmChannel1, frontRightPwmChannel2, false, speed);
    setMotorSpeed(backLeftPwmChannel1, backLeftPwmChannel2, false, speed);
    setMotorSpeed(backRightPwmChannel1, backRightPwmChannel2, false, speed);
}

void driveLeft(int speed) {
    int adjustedSpeed = speed * 1.1;
    setMotorSpeed(frontLeftPwmChannel1, frontLeftPwmChannel2, false, speed);
    setMotorSpeed(frontRightPwmChannel1, frontRightPwmChannel2, true, adjustedSpeed);
    setMotorSpeed(backLeftPwmChannel1, backLeftPwmChannel2, true, adjustedSpeed);
    setMotorSpeed(backRightPwmChannel1, backRightPwmChannel2, false, speed);
}

void driveRight(int speed) {
    int adjustedSpeed = speed * 1.1;
    setMotorSpeed(frontLeftPwmChannel1, frontLeftPwmChannel2, true, adjustedSpeed);
    setMotorSpeed(frontRightPwmChannel1, frontRightPwmChannel2, false, speed);
    setMotorSpeed(backLeftPwmChannel1, backLeftPwmChannel2, false, speed);
    setMotorSpeed(backRightPwmChannel1, backRightPwmChannel2, true, adjustedSpeed);
}

void rotate180() {
    int speed = rotateSpeed;
    setMotorSpeed(frontLeftPwmChannel1, frontLeftPwmChannel2, true, speed);
    setMotorSpeed(frontRightPwmChannel1, frontRightPwmChannel2, false, speed);
    setMotorSpeed(backLeftPwmChannel1, backLeftPwmChannel2, true, speed);
    setMotorSpeed(backRightPwmChannel1, backRightPwmChannel2, false, speed);

    delay(rotateTime);

    setMotorSpeed(frontLeftPwmChannel1, frontLeftPwmChannel2, true, 0);
    setMotorSpeed(frontRightPwmChannel1, frontRightPwmChannel2, false, 0);
    setMotorSpeed(backLeftPwmChannel1, backLeftPwmChannel2, true, 0);
    setMotorSpeed(backRightPwmChannel1, backRightPwmChannel2, false, 0);
}

void stopRobot() {
    dynamicBrakeMotor(frontLeftPwmChannel1, frontLeftPwmChannel2);
    dynamicBrakeMotor(frontRightPwmChannel1, frontRightPwmChannel2);
    dynamicBrakeMotor(backLeftPwmChannel1, backLeftPwmChannel2);
    dynamicBrakeMotor(backRightPwmChannel1, backRightPwmChannel2);
}

void testDriveForwardBackward() {
    Serial.println("Testing forward and backward driving...");
    driveForward(500);
    delay(1000);
    stopRobot();
    delay(500);

    driveBackward(500);
    delay(1000);
    stopRobot();
    delay(500);
}

void testDriveLeftRight() {
    Serial.println("Testing left and right driving...");
    driveLeft(500);
    delay(1000);
    stopRobot();
    delay(500);

    driveRight(500);
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

void setAllMotorsToZero() {
    ledcWrite(backRightPwmChannel1, 0);
    ledcWrite(backRightPwmChannel2, 0);
    ledcWrite(backLeftPwmChannel1, 0);
    ledcWrite(backLeftPwmChannel2, 0);
    ledcWrite(frontRightPwmChannel1, 0);
    ledcWrite(frontRightPwmChannel2, 0);
    ledcWrite(frontLeftPwmChannel1, 0);
    ledcWrite(frontLeftPwmChannel2, 0);
}