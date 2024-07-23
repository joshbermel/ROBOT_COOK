#include "utilities.h"
#include "config.h" // Only if config.h is necessary for servo functions
#include "sensors.h"
#include "drive.h"
#include "microswitch.h"
#include "servos.h"

int driveSpeed = 150;
int tuningSpeed = 40;

// Drives the robot left at a given speed until it is centered on the nearest black line. 
void leftStop(int speed, int leftSensorPin, int rightSensorPin) {
    while (true) {
        Direction dir = determineDirection(leftSensorPin, rightSensorPin);
        if (dir == CENTERED) {
            driveRight(speed);
            delay(20);
            setAllMotorsToZero();
            Serial.println("Robot is centered on the line.");
            break;
        } else if (dir == LEFT) {
            Serial.println("Robot needs to move left.");
            driveLeft(tuningSpeed);
        } else if (dir == RIGHT) {
            Serial.println("Robot needs to move right.");
            driveRight(tuningSpeed);
        } 
        else {
            Serial.println("Robot is not on the line, moving left.");
            driveLeft(speed);
        }
    }
}

// Drives the robot right at a given speed until it is centered on the nearest black line. 
void rightStop(int speed, int leftSensorPin, int rightSensorPin) {
    while (true) {
        Direction dir = determineDirection(leftSensorPin, rightSensorPin);
        if (dir == CENTERED) {
            driveLeft(speed);
            delay(20);
            setAllMotorsToZero();
            Serial.println("Robot is centered on the line.");
            break;
        } else if (dir == LEFT) {
            Serial.println("Robot needs to move left.");
            driveLeft(tuningSpeed);
        } else if (dir == RIGHT) {
            Serial.println("Robot needs to move right.");
            driveRight(tuningSpeed);
        } 
        else {
            Serial.println("Robot is not on the line, moving right.");
            driveRight(speed);
        }
        delay(5);
    }
}

// Function for robot to drive backwards, turn around, and drive forward until we reach the other counter. 
// HAS BEEN MODIFIED TO NOT INCLUDE MICROSWITCH INPUT. CAN BE CHANGED IF WE WANT.
void flipCounters(int speed, int leftSensorPin, int rightSensorPin, int microSwitchPin) {
    // turning around 
    driveBackward(speed);
    delay(600);
    driveForward(255);
    delay(50);
    setAllMotorsToZero();
    rotate180(rotateSpeed, rotateTime);
    rotate180(-1*rotateSpeed, 50);
    setAllMotorsToZero();

    // while (true) {
    //     if (isMicroswitchPressed(microSwitchPin)) {
    //     setAllMotorsToZero();
    //     break;
    //     }
    //     else {
    //         driveForward(speed);
    //     }
    //     delay(10);
    // }

    driveForward(speed);
    delay(1200);
    driveBackward(255);
    delay(50);
    setAllMotorsToZero();
}

// Drives the robot either left or right and skips over a given number of lines, and centers on the nearest line afterwards.
// Ensure that you put a delay after this call. It can be any non zero value (i think)
void skipLinesAndStop2(int leftSensorPin, int rightSensorPin, int linesToSkip, int moveSpeed, Direction moveDirection) {
    int linesSkipped = 0;
    bool onLine = false;

    while (linesSkipped < linesToSkip) {
        while (!isOnLine(leftSensorPin, rightSensorPin)) {
            if (moveDirection == LEFT) {
                driveLeft(moveSpeed);
            } else {
                driveRight(moveSpeed);
            }
            onLine = false;  // Update onLine flag when not on line
        }
        if (!onLine) {
                linesSkipped++;
                onLine = true;  // Update onLine flag when on line
                Serial.print("Line detected. Lines skipped: ");
                Serial.println(linesSkipped);
            }

            if (moveDirection == LEFT) {
                driveLeft(moveSpeed);
            } else {
                driveRight(moveSpeed);
            }
            delay(500);  // Allow time to move off the current line
    }

    // Stop on the final line detected
    if (moveDirection == LEFT) {
        leftStop(moveSpeed, leftSensorPin, rightSensorPin);
    } else {
        rightStop(moveSpeed, leftSensorPin, rightSensorPin);
    }
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