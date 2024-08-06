#include "drive.h"
#include "config.h"
#include "sensors.h"
#include "utilities.h"
#include "servos.h"

int reverbServoDelay = 100;

void rotate1802() {
    bool direction = rotateSpeed > 0;

    setMotorSpeed(backRightMotorPin1, backRightMotorPin2, !direction, rotateSpeed * BRSpeedCalibrated);
    setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, direction, rotateSpeed * FLSpeedCalibrated);
    setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, !direction, rotateSpeed * FRSpeedCalibrated);
    setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, direction, rotateSpeed * BLSpeedCalibrated);

}

// flips counter and either raises or lowers the claw. 
// clawDirection == 1 raises the claw, 2 lowers the claw
void flipCounters2(int clawDirection) {
    unsigned long rightDriveStartTime = millis();
    unsigned long leftDriveStartTime;
    unsigned long rotateStartTime;

    bool rightDriveComplete = false;
    bool rotateComplete = false;
    bool leftDriveComplete = false;

    bool clawRaised = false;
    bool clawLowered = false;

    driveRight(90);

    while (!leftDriveComplete) {
        unsigned long currentMillis = millis();

        // check if driveright has occured for long enough
        if (!rightDriveComplete && currentMillis - rightDriveStartTime >= 500) {
            setAllMotorsToZero();
            rightDriveComplete = true;
            rotateStartTime = millis();
            rotate1802();
        }

        // Check if rotation is complete
        if (rightDriveComplete && !rotateComplete && currentMillis - rotateStartTime >= 500) {
            setAllMotorsToZero(); 
            rotateComplete = true;
            leftDriveStartTime = millis();

            driveLeft(90);
        }

        // Check if left drive is complete
        if (rotateComplete && !leftDriveComplete && currentMillis - leftDriveStartTime >= 550) {
            setAllMotorsToZero();
            leftDriveComplete = true;
        }

        if (clawDirection == 1 && !clawRaised) {
            raiseClaw(); 
            clawRaised = true;
            clawLowered = false;
        } else if (clawDirection == 2 && !clawLowered) {
            lowerClaw();
            clawLowered = true;
            clawRaised = false;
        }

    }
}

void moveStoB() {
    delay(1000);
    driveToWall();
    
    unsigned long delayStartTime = millis();

    bool delayComplete = false;

    while (!delayComplete){
        unsigned long currentmillis = millis();

        if (!delayComplete && currentmillis - delayStartTime >= 1000){
            delayComplete = true;
            break;
        }
    }
    skipLinesAndStop(2, detectSpeed, FORWARD, LEFT);
    pushToWall();
    // precautionary delay for stability
    delay(1000);
    lowerClaw();
    delay(servoDropDelay);
    grabBottomBun();
    delay(reverbServoDelay* 2);
    openClaw();
    delay(reverbServoDelay);
    grabBottomBun();
    delay(servoDropDelay);

}

void moveBtoCB() {
    flipCounters2(1);
    delay(400);
    skipLinesAndStop(0, detectSpeed * 1.1, FORWARD, LEFT);
    pushToWall();
    // precautionary delay for stability
    delay(servoDropDelay);
    lowerClaw();
    delay(servoDropDelay);
    openClaw();
}

void moveCBtoP() {
    flipCounters2(1);
    delay(400);
    skipLinesAndStop(0, detectSpeed, BACKWARD, LEFT);
    pushToWall();
    // precautionary delay for stability
    delay(servoDropDelay);
    lowerClaw();
    delay(servoDropDelay);
    grabPatty();
    delay(reverbServoDelay * 2);
    openClaw();
    delay(reverbServoDelay);
    grabPatty();
    delay(servoDropDelay);
}

void movePtoCT() {
    driveForwardLeft(50);
    delay(200);
    flipCounters2(1);
    delay(400);
    skipLinesAndStop(2, detectSpeed * 0.7, BACKWARD, LEFT);
    pushToWall();
    // precautionary delay for stability
    delay(servoDropDelay);
    lowerClaw();
    delay(servoDropDelay);
    openClaw();
}

void moveCTtoB() {
    flipCounters2(1);
    delay(400);
    skipLinesAndStop(0, detectSpeed, BACKWARD, LEFT);
    pushToWall();
    // precautionary delay for stability
    delay(servoDropDelay);
    lowerClaw();
    delay(servoDropDelay);
    grabTopBun();
    delay(reverbServoDelay * 3);
    openClaw();
    delay(reverbServoDelay);
    grabTopBun();
    delay(servoDropDelay);
}

void moveCBtoB() {
    flipCounters2(1);
    delay(400);
    skipLinesAndStop(0, detectSpeed, FORWARD, LEFT);
    pushToWall();
    // precautionary delay for stability
    delay(servoDropDelay);
    lowerClaw();
    delay(servoDropDelay);
    grabBottomBun();
    delay(servoDropDelay);
}

void burger(){
    bool started = false;
    int runTimes = 0;
    while (!started){
        started = true;
        moveStoB();
        delay(stationDelay);

        moveBtoCB();
        delay(stationDelay);

        moveCBtoP();
        delay(stationDelay);

        movePtoCT();
        delay(stationDelay);

        moveCTtoB();
        delay(stationDelay);

        moveBtoCB();
        delay(stationDelay);
    }
    
    while (runTimes < 4){
        runTimes++;

        moveCBtoB();
        delay(stationDelay);

        moveBtoCB();
        delay(stationDelay);

        moveCBtoP();
        delay(stationDelay);

        movePtoCT();
        delay(stationDelay);

        moveCTtoB();
        delay(stationDelay);

        moveBtoCB();
        delay(stationDelay);
    }
}

void testflipCounters2() {
    unsigned long rightDriveStartTime = millis();
    unsigned long leftDriveStartTime;
    unsigned long rotateStartTime;

    bool rightDriveComplete = false;
    bool rotateComplete = false;
    bool leftDriveComplete = false;

    bool clawRaised = false;
    bool clawLowered = false;

    driveRight(90);

    while (!leftDriveComplete) {
        unsigned long currentMillis = millis();

        // check if driveright has occured for long enough
        if (!rightDriveComplete && currentMillis - rightDriveStartTime >= 500) {
            setAllMotorsToZero();
            rightDriveComplete = true;
            rotateStartTime = millis();
            rotate1802();
        }

        // Check if rotation is complete
        if (rightDriveComplete && !rotateComplete && currentMillis - rotateStartTime >= 500) {
            setAllMotorsToZero(); 
            rotateComplete = true;
            leftDriveStartTime = millis();

            driveLeft(90);
        }

        // Check if left drive is complete
        if (rotateComplete && !leftDriveComplete && currentMillis - leftDriveStartTime >= 450) {
            setAllMotorsToZero();
            leftDriveComplete = true;
        }
    }
}


