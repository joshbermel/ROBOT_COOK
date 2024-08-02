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
    driveRight(150);
    delay(700);
    setAllMotorsToZero();
    delay(200);
    rotate180(150, 500);
    setAllMotorsToZero();
    delay(300);
    driveLeft(170);
    delay(680);
    setAllMotorsToZero();
}

// Drives the robot either left or right and skips over a given number of lines, and centers on the nearest line afterwards.
// Ensure that you put a delay after this call. It can be any non zero value (i think)
void skipLinesAndStop(int linesToSkip, int moveSpeed, Direction moveDirection, int changeTime, Direction touchingSide) {
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
            frontStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor, changeTime, LEFT);
        } else {
            backStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor, changeTime, LEFT);
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
            frontStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor, changeTime, RIGHT);
        } else {
            backStop(moveSpeed, frontReflectanceSensor, backReflectanceSensor, changeTime, RIGHT);
        }
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
            driveForwardStraight(speed);
        }
        delay(20);
    }
}

// drives towards wall without using microswitches. Just uses timing
void driveToWall2() {
    driveLeft(150);
    delay(700);
    setAllMotorsToZero();
}

void frontStop(int speed, int frontSensorPin, int rightSensorPin, int reverseTime, Direction touchingSide) {
    if (touchingSide == LEFT) {
        driveForwardLeft(speed);
        delay(300);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            } 
        }
        delay(10);
        setAllMotorsToZero();

        driveBackwardLeft(25);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            } 
        }
        // this delay is used to stabilize the motors
        // delay(220);
        delay(100);
        setAllMotorsToZero();
    }
    else if (touchingSide = RIGHT) {
        driveForwardRight(speed);
        // this delay is used to ignore the initial noise from the motors
        delay(300);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            } 
        }
        delay(10);
        setAllMotorsToZero();

        driveBackwardRight(25);
        while (true) {
           Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            }  
        }
        // this delay is used to stabilize the motors
        // delay(220);
        delay(100);
        setAllMotorsToZero();  
    }
}

void backStop(int speed, int frontSensorPin, int backSensorPin, int forwardTime, Direction touchingSide) {
    if (touchingSide == LEFT) {
        driveBackwardLeft(speed);
        delay(300);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            }
        }
        delay(10);
        setAllMotorsToZero();

        driveForwardLeft(24);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            }
        }

        // this delay is used to stabilize the motors
        delay(100);
        setAllMotorsToZero();
    }
    else if (touchingSide == RIGHT) {
        driveBackwardRight(speed);
        delay(300);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            }
        }
        delay(10);
        setAllMotorsToZero();

        driveForwardRight(24);
        while (true) {
            Direction dir = determineDirection(frontReflectanceSensor, backReflectanceSensor);
            if (dir != NOT_ON_LINE) {
                break;
            }
        }

        // this delay is used to stabilize the motors
        delay(100);
        setAllMotorsToZero();
    }   
}

void driveStoB(int changeTime) {
    driveToWall2();
    delay(400);
    skipLinesAndStop(1, 35, FORWARD, changeTime, LEFT);
}

void driveBtoCB(int changeTime) {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, 35, FORWARD, changeTime, LEFT);
}

void driveCBtoP(int changeTime) {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, 35, BACKWARD, changeTime, LEFT);
    // delay(200);
    // driveLeft(20);
    // delay(100);
}

void drivePtoCT(int changeTime) {
    flipCounters();
    delay(400);
    skipLinesAndStop(1, 35, BACKWARD, changeTime, LEFT);
}

void driveCTtoB(int changeTime) {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, 35, BACKWARD, changeTime, LEFT);
}

void driveCBtoB(int changeTime) {
    flipCounters();
    delay(400);
    skipLinesAndStop(0, 35, FORWARD, changeTime, LEFT);
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

