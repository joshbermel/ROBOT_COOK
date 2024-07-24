#include "drive.h"
#include "config.h"


// Initialize each motor pin as an output
void initializeMotorPins() {
    pinMode(backRightMotorPin1, OUTPUT);
    pinMode(backRightMotorPin2, OUTPUT);
    pinMode(backLeftMotorPin1, OUTPUT);
    pinMode(backLeftMotorPin2, OUTPUT);
    pinMode(frontRightMotorPin1, OUTPUT);
    pinMode(frontRightMotorPin2, OUTPUT);
    pinMode(frontLeftMotorPin1, OUTPUT);
    pinMode(frontLeftMotorPin2, OUTPUT);

    // setting the analog write frequency to 100 Hz
    analogWriteFrequency(500);
}

// Set a wheel to a given speed. A "true" direction means forwards. Controls via both motor pins attached to each wheel.
void setMotorSpeed(int motorPin1, int motorPin2, bool direction, float speed) {
    if (direction) {
        analogWrite(motorPin1, round(speed));
        // delay(1);
        analogWrite(motorPin2, 0);
        // delay(1);
    } else {
        analogWrite(motorPin1, 0);
        // delay(1);
        analogWrite(motorPin2, round(speed));
        // delay(1);
    }
}

   
// Sets all wheels to spin forwards at a given speed
void driveForward(int speed) {
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, true, speed * FLSpeedCalibrated );
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, true, speed * FRSpeedCalibrated);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, speed * BLSpeedCalibrated);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, true, speed * BRSpeedCalibrated);
}

// Sets all wheels to spin backwards at a given speed
void driveBackward(int speed) {
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, false, speed * FLSpeedCalibrated);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, false, speed * FRSpeedCalibrated);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, false, speed * BLSpeedCalibrated);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, false, speed * BRSpeedCalibrated);
}

// Turns the front right and back left wheels forwards, and front left and back right wheels backwards. Direct left linear motion.
// Setting wheels to the adjust speed allows purposeful drift (helpful for keeping robot pressed against the wall)
void driveLeft(int speed) {
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, false, speed * FLSpeedCalibrated);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, true, speed * FRSpeedCalibrated);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, speed * BLSpeedCalibrated);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, false, speed * BRSpeedCalibrated);
}

// Turns the front left and back right wheels forwards, and front right and back left wheels backwards. Direct right linear motion.
// Setting wheels to the adjust speed allows purposeful drift (helpful for keeping robot pressed against the wall)
void driveRight(int speed) {
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, true, speed * FLSpeedCalibrated);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, false, speed * FRSpeedCalibrated);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, false, speed * BLSpeedCalibrated);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, true, speed * BRSpeedCalibrated);
}

// Sets left side wheels forwards, and right side wheels backwards. Induces an on-the-spot 180 degree clockwise rotation.
// REQUIRES TUNING FOR FINAL ROBOT.
void rotate180(int rotateSpeed, int rotateTime) {
    bool direction = rotateSpeed > 0;
    Serial.println(direction ? "Rotating CW" : "Rotating CCW");

    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, direction, rotateSpeed * FLSpeedCalibrated);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, !direction, rotateSpeed * FRSpeedCalibrated);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, direction, rotateSpeed * BLSpeedCalibrated);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, !direction, rotateSpeed * BRSpeedCalibrated);

    delay(rotateTime);
    setAllMotorsToZero();
}

// Testing function to drive forwards, stop, drive backwards, stop. 
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

// Testing function to drive left, stop, drive right, stop. 
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

// Testing function to do a 180 degree clockwise rotation.
void testRotate() {
    Serial.println("Testing rotate 180...");
    rotate180(rotateSpeed, rotateTime);
    delay(1000);
    setAllMotorsToZero();
    delay(500);
}

// Sets all motors to zero speed, stopping the robot. Can be used as an alternative to stopRobot2() if dynamic braking is not required. 
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