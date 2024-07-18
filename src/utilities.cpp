#include "utilities.h"
#include "config.h" // Only if config.h is necessary for servo functions
#include "sensors.h"
#include "drive.h"
#include "microswitch.h"
#include "servos.h"

void leftStop(int speed, int leftSensorPin, int rightSensorPin) {
    while (true) {
        int leftSensorValue = readReflectanceSensor(leftSensorPin);
        int rightSensorValue = readReflectanceSensor(rightSensorPin);
        Direction dir = determineDirection(leftSensorValue, rightSensorValue);

        if (dir == CENTERED) {
            setAllMotorsToZero();
            Serial.println("Robot is centered on the line.");
            break;
        } else if (dir == LEFT) {
            Serial.println("Robot needs to move left.");
            driveLeft(speed*0.3);
        } else if (dir == RIGHT) {
            Serial.println("Robot needs to move right.");
            driveRight(speed*0.3);
        } else {
            Serial.println("Robot is not on the line, moving left.");
            driveLeft(speed);
        }
        delay(50); // Short delay to prevent overwhelming the motor control
    }
}

void rightStop(int speed, int leftSensorPin, int rightSensorPin) {
    while (true) {
        int leftSensorValue = readReflectanceSensor(leftSensorPin);
        int rightSensorValue = readReflectanceSensor(rightSensorPin);
        Direction dir = determineDirection(leftSensorValue,rightSensorValue);

        if (dir == CENTERED) {
            setAllMotorsToZero();
            Serial.println("Robot is centered on the line.");
            break;
        } else if (dir == LEFT) {
             Serial.println("Robot needs to move left.");
            driveLeft(speed*0.3);
        } else if (dir == RIGHT) {
            Serial.println("Robot needs to move right.");
            driveRight(speed*0.3);
        } else {
            Serial.println("Robot is not on the line, moving right.");
            driveRight(speed);
        }
        delay(20); 
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

        delay(50); // Small delay to allow for sensor reading stabilization
    }
    // read the first time we get centered, increment the count, check if we are at count limit, if not, delay a small time (until we are off the line), check again for the next line. 

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

void skipLinesAndStop2(int leftSensorPin, int rightSensorPin, int linesToSkip, int moveSpeed, Direction moveDirection) {
    int linesSkipped = 0;
    bool onLine = false;

    while (linesSkipped < linesToSkip) {
        if (!isOnLine(leftSensorPin, rightSensorPin)) {
            if (moveDirection == LEFT) {
                driveLeft(moveSpeed);
            } else {
                driveRight(moveSpeed);
            }
            onLine = false;  // Update onLine flag when not on line
        } else {
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
            delay(200);  // Allow time to move off the current line
        }
        delay(50);  // Small delay to allow for sensor reading stabilization
    }

    // Stop on the final line detected
    if (moveDirection == LEFT) {
        leftStop(moveSpeed, leftSensorPin, rightSensorPin);
    } else {
        rightStop(moveSpeed, leftSensorPin, rightSensorPin);
    }
    delay(50);

    stopRobot();  // Ensure the robot stops
    Serial.println("Final line reached and stopped.");
}

void driveToWall(int speed, int microSwitchPin) {
    while (true) {
        if (isMicroswitchPressed(microSwitchPin)) {
            stopRobot();
            break;
        }
        else {
            driveForward(speed);
        }
    delay(20);
    }
}