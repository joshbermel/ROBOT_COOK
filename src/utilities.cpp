#include "utilities.h"
#include "config.h" // Only if config.h is necessary for servo functions
#include "sensors.h"
#include "drive.h"
#include "microswitch.h"
#include "servos.h"

int tuningSpeed = 40;

// Function for robot to drive backwards, turn around, and drive forward until we reach the other counter. 
// HAS BEEN MODIFIED TO NOT INCLUDE MICROSWITCH INPUT. CAN BE CHANGED IF WE WANT.
void flipCounters() {
    // turning around 
    driveRight(50);
    delay(500);
    setAllMotorsToZero();
    delay(200);
    rotate180(115, 410);
    setAllMotorsToZero();
    delay(300);
    driveLeft(50);
    delay(380);
    setAllMotorsToZero();
}

// Drives the robot either left or right and skips over a given number of lines, and centers on the nearest line afterwards.
// Ensure that you put a delay after this call. It can be any non zero value (i think)
void skipLinesAndStop(int linesToSkip, int moveSpeed, Direction moveDirection, int changeTime) {
    int linesSkipped = 0;
    bool onLine = false;

    while (linesSkipped < linesToSkip) {
        while (!isOnLine()) {
            if (moveDirection == FORWARD) {
                driveForward(moveSpeed);
                delay(20);
            } else {
                driveBackward(moveSpeed);
                delay(20);
            }
            onLine = false;  // Update onLine flag when not on line
        }
        if (!onLine) {
                linesSkipped++;
                onLine = true;  // Update onLine flag when on line
            }

            if (moveDirection == FORWARD) {
                driveForward(moveSpeed);
            } else {
                driveBackward(moveSpeed);
            }
    }
    if (moveDirection == FORWARD) {
        frontStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor, changeTime);
    } else {
        backStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor, changeTime);
    }
    
}

// Drives the robot forwards until a microswitch is pressed. Then stops the robot.
// This is if we are using a microswitch.
void driveToWall(int speed, int microSwitchPin) {
    while (true) {
        if (isMicroswitchPressed(microSwitchPin)) {
            stopRobot2();
            break;
        }
        else {
            driveForward(speed);
        }
        delay(20);
    }
}

// drives towards wall without using microswitches. Just uses timing
void driveToWall2() {
    driveLeft(50);
    delay(450);
    setAllMotorsToZero();
}

void frontStop(int speed, int frontSensorPin, int rightSensorPin, int reverseTime) {
    driveForward(speed);
    delay(300);
    while (true) {
        Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
        if (dir != NOT_ON_LINE) {
            break;
        } 
    }
    delay(10);
    setAllMotorsToZero();
    delay(400);
    // setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, false, speed);
    // delay(20);
    reverseBackward(30);
    delay(reverseTime);
    setAllMotorsToZero();    
}

void backStop(int speed, int frontSensorPin, int backSensorPin, int forwardTime) {
    driveBackward(speed);
    delay(300);
    while (true) {
        Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
        if (dir != NOT_ON_LINE) {
            break;
        }
    }
    delay(10);
    setAllMotorsToZero();
    delay(400);
    // setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, true, speed);
    // delay(20);
    reverseForward(30);
    delay(forwardTime);
    setAllMotorsToZero();
}

void driveStoB(int changeTime) {
    driveToWall2();
    delay(400);
    skipLinesAndStop(1, 35, FORWARD, changeTime);
}

void driveBtoCB(int changeTime) {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, 35, FORWARD, changeTime);
}

void driveCBtoP(int changeTime) {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, 35, BACKWARD, changeTime);
    // delay(200);
    // driveLeft(20);
    // delay(100);
}

void drivePtoCT(int changeTime) {
    flipCounters();
    delay(400);
    skipLinesAndStop(1, 35, BACKWARD, changeTime);
}

void driveCTtoB(int changeTime) {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, 35, BACKWARD, changeTime);
}

void driveCBtoB(int changeTime) {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, 35, FORWARD, changeTime);
}

void runThroughCourse() {
    driveStoB(StoBreverseTime);
    delay(1000);

    driveBtoCB(BtoCBreverseTime);
    delay(1000);

    driveCBtoP(CBtoPforwardTime);
    delay(1000);

    drivePtoCT(PtoCTforwardTime);
    delay(1000);

    driveCTtoB(CTtoBforwardTime);
    delay(1000);

    driveBtoCB(BtoCBreverseTime);
    delay(1000);

    driveCBtoB(CBtoBreverseTime);
    delay(1000);
}

