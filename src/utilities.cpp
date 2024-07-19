#include "utilities.h"
#include "config.h" // Only if config.h is necessary for servo functions
#include "sensors.h"
#include "drive.h"
#include "microswitch.h"
#include "servos.h"

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
void flipCounters(int speed, int leftSensorPin, int rightSensorPin, int microSwitchPin) {
    // turning around 
    driveBackward(speed);
    delay(100);
    stopRobot();
    rotate180();

    while (true) {
        if (isMicroswitchPressed(microSwitchPin)) {
        stopRobot();
        break;
        }
        else {
            driveForward(speed);
        }
        delay(10);
    }
}

// Drives the robot either left or right and skips over a given number of lines, and centers on the nearest line afterwards.
void skipLinesAndStop(int leftSensorPin, int rightSensorPin, int linesToSkip, int moveSpeed, Direction moveDirection) {
    int linesSkipped = 0;
    bool onLine = false;

    while (linesSkipped < linesToSkip) {
        if (isOnLine(leftSensorPin, rightSensorPin)) {
            if (!onLine) {
                linesSkipped++;
                onLine = true;
                Serial.print("Line detected. Lines skipped: ");
                Serial.println(linesSkipped);
            }
        } else {
            onLine = false;
        }

        // Move left or right based on the direction parameter
        while (!isOnLine(leftSensorPin, rightSensorPin)) {
            if (moveDirection == LEFT) {
                driveLeft(moveSpeed);
            } else if (moveDirection == RIGHT) {
                driveRight(moveSpeed);
            }
        }
    }

    // Stop on the final line detected
    if (moveDirection == LEFT) {
        leftStop(moveSpeed, leftSensorPin, rightSensorPin);
    } else {
        rightStop(moveSpeed, leftSensorPin, rightSensorPin);
    }
    delay(50);

    stopRobot();
    Serial.println("Final line reached and stopped.");
}

// Drives the robot either left or right and skips over a given number of lines, and centers on the nearest line afterwards.
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