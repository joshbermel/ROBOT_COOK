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
    analogWriteFrequency(100);
}

// Set a wheel to a given speed. A "true" direction means forwards. Controls via both motor pins attached to each wheel.
void setMotorSpeed(int motorPin1, int motorPin2, bool direction, int speed) {
    if (direction) {
        analogWrite(motorPin1, speed);
        delay(5);
        analogWrite(motorPin2, 0);
        delay(5);
    } else {
        analogWrite(motorPin1, 0);
        delay(5);
        analogWrite(motorPin2, speed);
        delay(5);
    }
}


// Garbage Function. See dynamicBrakeMotor2() for improved and functional version
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

// Dynamically brakes each motor by applying maximum speed in opposite direction of current motion. 
void dynamicBrakeMotor2(int motorPin1A, int motorPin1B, int motorPin2A, int motorPin2B, int motorPin3A, int motorPin3B, int motorPin4A, int motorPin4B) {
     
    int currentSpeed1A = analogRead(motorPin1A);
    int currentSpeed1B = analogRead(motorPin1B);
    int currentSpeed2A = analogRead(motorPin2A);
    int currentSpeed2B = analogRead(motorPin2B);
    int currentSpeed3A = analogRead(motorPin3A);
    int currentSpeed3B = analogRead(motorPin3B);
    int currentSpeed4A = analogRead(motorPin4A);
    int currentSpeed4B = analogRead(motorPin4B);

    if (currentSpeed1A > 0) {
        analogWrite(motorPin1A, 0);
        delay(5);
        analogWrite(motorPin1B, 255);
        delay(5);
    } else {
        analogWrite(motorPin1A, 255);
        delay(5);
        analogWrite(motorPin1B, 0);
        delay(5);
    }

    if (currentSpeed2A > 0) {
        analogWrite(motorPin2A, 0);
        delay(5);
        analogWrite(motorPin2B, 255);
        delay(5);
    } else {
        analogWrite(motorPin2A, 255);
        delay(5);
        analogWrite(motorPin2B, 0);
        delay(5);
    }

    if (currentSpeed3A > 0) {
        analogWrite(motorPin3A, 0);
        delay(5);
        analogWrite(motorPin3B, 255);
        delay(5);
    } else {
        analogWrite(motorPin3A, 255);
        delay(5);
        analogWrite(motorPin3B, 0);
        delay(5);
    }

    if (currentSpeed4A > 0) {
        analogWrite(motorPin4A, 0);
        delay(5);
        analogWrite(motorPin4B, 255);
        delay(5);
    } else {
        analogWrite(motorPin4A, 255);
        delay(5);
        analogWrite(motorPin4B, 0);
        delay(5);
    }

    delay(50);
    setAllMotorsToZero();
    delay(5);
}
    
// Sets all wheels to spin forwards at a given speed
void driveForward(int speed) {
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, true, speed);
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, true, speed);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, speed);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, true, speed);
}

// Sets all wheels to spin backwards at a given speed
void driveBackward(int speed) {
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, false, speed);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, false, speed);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, false, speed);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, false, speed);
}

// Turns the front right and back left wheels forwards, and front left and back right wheels backwards. Direct left linear motion.
// Setting wheels to the adjust speed allows purposeful drift (helpful for keeping robot pressed against the wall)
void driveLeft(int speed) {
    int adjustedSpeed = speed * 1.5;
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, false, speed);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, true, speed);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, speed);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, false, speed);
}

// Turns the front left and back right wheels forwards, and front right and back left wheels backwards. Direct right linear motion.
// Setting wheels to the adjust speed allows purposeful drift (helpful for keeping robot pressed against the wall)
void driveRight(int speed) {
    int adjustedSpeed = speed * 1.5;
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, true, speed);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, false, speed);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, false, speed);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, true, speed);
}

// Sets left side wheels forwards, and right side wheels backwards. Induces an on-the-spot 180 degree clockwise rotation.
// Fine tune the rotate speed and rotate time for final robot. 
void rotate180() {
    int rotateSpeed = 150;
    int rotateTime = 1100;
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, true, rotateSpeed);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, false, rotateSpeed);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, rotateSpeed);
    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, false, rotateSpeed);

    delay(rotateTime);

    // setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, true, 0);
    // setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, false, 0);
    // setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, 0);
    // setMotorSpeed(backRightMotorPin1, backRightMotorPin2, false, 0);

    setAllMotorsToZero();
}

// Garbage function, see stopRobot2()
void stopRobot() {
    dynamicBrakeMotor(frontLeftMotorPin1, frontLeftMotorPin2);
    dynamicBrakeMotor(frontRightMotorPin1, frontRightMotorPin2);
    dynamicBrakeMotor(backLeftMotorPin1, backLeftMotorPin2);
    dynamicBrakeMotor(backRightMotorPin1, backRightMotorPin2);
}

// Stops the entire robot by applying dynamic braking. Use this function instead of calling dynamicBrakeMotor2() each time.
void stopRobot2() {
    dynamicBrakeMotor2(frontLeftMotorPin1, frontLeftMotorPin2, frontRightMotorPin1, frontRightMotorPin2, backLeftMotorPin1, backLeftMotorPin2, backRightMotorPin1, backRightMotorPin1);
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
    rotate180();
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