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
    rotate180(115, 430);
    setAllMotorsToZero();
    delay(300);
    driveLeft(50);
    delay(500);
    setAllMotorsToZero();
}

// Drives the robot either left or right and skips over a given number of lines, and centers on the nearest line afterwards.
// Ensure that you put a delay after this call. It can be any non zero value (i think)
void skipLinesAndStop2(int linesToSkip, int moveSpeed, Direction moveDirection) {
    int linesSkipped = 0;
    bool onLine = false;

    while (linesSkipped < linesToSkip) {
        while (!isOnLine()) {
            if (moveDirection == FORWARD) {
                driveForward(moveSpeed);
            } else {
                driveBackward(moveSpeed);
            }
            onLine = false;  // Update onLine flag when not on line
        }
        if (!onLine) {
                linesSkipped++;
                onLine = true;  // Update onLine flag when on line
                Serial.print("Line detected. Lines skipped: ");
                Serial.println(linesSkipped);
            }

            if (moveDirection == FORWARD) {
                driveForward(moveSpeed);
            } else {
                driveBackward(moveSpeed);
            }
    }

    // Stop on the final line detected
    if (moveDirection == FORWARD) {
        frontStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor);
    } else {
        backStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor);
    }
    delay(20);
    setAllMotorsToZero();
    Serial.println("Final line reached and stopped.");
}

// Drives the robot forwards until a microswitch is pressed. Then stops the robot
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

void frontStop(int speed, int frontSensorPin, int rightSensorPin) {
    driveForward(speed);
    while (true) {
        Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
        testBothReflectanceSensor();
        if (dir == FORWARD || dir == CENTERED) {
            break;
        // } else if (dir == FORWARD) {
        //     Serial.println("Robot needs to move left.");
        //     driveForward(tuningSpeed);
        // } else if (dir == BACKWARD) {
        //     Serial.println("Robot needs to move right.");
        //     driveBackward(tuningSpeed);
        
        // 
        } 
    }
    delay(5);
    setAllMotorsToZero();
}

void backStop(int speed, int frontSensorPin, int backSensorPin) {
    driveBackward(speed);
    while (true) {
        Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
        testBothReflectanceSensor();
        if (dir == CENTERED || dir == BACKWARD) {
            break;
        }
        // else if (dir == BACKWARD) {
        //     driveBackward(tuningSpeed);
        // } else if (dir == FORWARD) {
        //     driveForward(tuningSpeed);
        // } 
    }
    delay(5);
    setAllMotorsToZero();
}