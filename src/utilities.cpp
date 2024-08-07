#include "utilities.h"
#include "config.h" // Only if config.h is necessary for servo functions
#include "sensors.h"
#include "drive.h"
#include "servos.h"

int tuningSpeed = 40;

// Function for robot to drive backwards, turn around, and drive forward until we reach the other counter. 
// HAS BEEN MODIFIED TO NOT INCLUDE MICROSWITCH INPUT. CAN BE CHANGED IF WE WANT.
void flipCounters() {
    // turning around 
    driveRight(90);
    delay(500);
    rotate180(110, 500);
    driveLeft(90);
    delay(450);
    setAllMotorsToZero();
}

// Drives the robot either left or right and skips over a given number of lines, and centers on the nearest line afterwards.
// Ensure that you put a delay after this call. It can be any non zero value (i think)
void skipLinesAndStop(int linesToSkip, int moveSpeed, Direction moveDirection, Direction touchingSide) {
    int linesSkipped = 0;
    bool onLine = false;

    if (touchingSide == LEFT) {
        while (linesSkipped < linesToSkip) {
            while (!isOnLine()) {
                if (moveDirection == FORWARD) {
                    driveForwardLeft(moveSpeed);
                    delay(20);
                } else {
                    driveBackwardLeft(moveSpeed);
                    delay(20);
                }
                onLine = false;  // Update onLine flag when not on line
            }
            if (!onLine) {
                    linesSkipped++;
                    onLine = true;  // Update onLine flag when on line
                }

                if (moveDirection == FORWARD) {
                    driveForwardLeft(moveSpeed);
                } else {
                    driveBackwardLeft(moveSpeed);
                }
        }
        if (moveDirection == FORWARD) {
            frontStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor, LEFT);
        } else {
            backStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor, LEFT);
        }
    }
    else if (touchingSide == RIGHT) {
        while (linesSkipped < linesToSkip) {
            while (!isOnLine()) {
                if (moveDirection == FORWARD) {
                    driveForwardRight(moveSpeed);
                    delay(20);
                } else {
                    driveBackwardRight(moveSpeed);
                    delay(20);
                }
                onLine = false;  // Update onLine flag when not on line
            }
            if (!onLine) {
                    linesSkipped++;
                    onLine = true;  // Update onLine flag when on line
                }

                if (moveDirection == FORWARD) {
                    driveForwardRight(moveSpeed);
                } else {
                    driveBackwardRight(moveSpeed);
                }
        }
        if (moveDirection == FORWARD) {
            frontStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor, RIGHT);
        } else {
            backStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor, RIGHT);
        }
    }

    
}

// drives towards wall without using microswitches. Just uses timing
void driveToWall() {
    driveLeft(90);

    unsigned long driveLeftStartTime = millis();

    bool driveLeftComplete = false;

    while (!driveLeftComplete){
        unsigned long currentmillis = millis();

        if (!driveLeftComplete && currentmillis - driveLeftStartTime >= 750){
            driveLeftComplete = true;
            setAllMotorsToZero();
        }
    }
    setAllMotorsToZero();
}

void frontStop(int speed, int frontSensorPin, int rightSensorPin, Direction touchingSide) {
    if (touchingSide == LEFT) {
        driveForwardLeft(speed);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            } 
        }
        delay(100);

        driveBackwardLeft(26);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            } 
        }
        // this delay is used to stabilize the motors
        setAllMotorsToZero();
    }
    else if (touchingSide = RIGHT) {
        driveForwardRight(speed);
        // this delay is used to ignore the initial noise from the motors
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            } 
        }
        delay(100);

        driveBackwardRight(26);
        while (true) {
           Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            }  
        }
        // this delay is used to stabilize the motors
        setAllMotorsToZero();  
    }
}

void backStop(int speed, int frontSensorPin, int backSensorPin, Direction touchingSide) {
    if (touchingSide == LEFT) {
        driveBackwardLeft(speed);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            }
        }
        delay(100);

        driveForwardLeft(26);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            }
        }

        // this delay is used to stabilize the motors
        setAllMotorsToZero();
    }
    else if (touchingSide == RIGHT) {
        driveBackwardRight(speed);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            }
        }
        delay(100);
        setAllMotorsToZero();

        driveForwardRight(26);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            }
        }

        // this delay is used to stabilize the motors
        setAllMotorsToZero();
    }   
}

void driveStoB() {
    driveToWall();
    delay(600);
    skipLinesAndStop(2, detectSpeed, FORWARD, LEFT);
    pushToWall();
}

void driveBtoCB() {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, detectSpeed, FORWARD, LEFT);
    pushToWall();

}

void driveCBtoP() {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, detectSpeed, BACKWARD, LEFT);
    pushToWall(); 
}

void drivePtoCT() {
    flipCounters();
    delay(400);
    skipLinesAndStop(2, detectSpeed, BACKWARD, LEFT);
    pushToWall();
}

void driveCTtoB() {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, detectSpeed, BACKWARD, LEFT);
    pushToWall();
}

void driveCBtoB() {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, detectSpeed, FORWARD, LEFT);
    pushToWall();
}

void runThroughCourse() {
    driveStoB();
    delay(stationDelay);

    driveBtoCB();
    delay(stationDelay);

    driveCBtoP();
    delay(stationDelay);

    drivePtoCT();
    delay(stationDelay);

    driveCTtoB();
    delay(stationDelay);

    driveBtoCB();
    delay(stationDelay);

    driveCBtoB();
    delay(stationDelay);
}

void pushToWall() {
    driveLeft(80);
    delay(400);


    setAllMotorsToZero();
}

