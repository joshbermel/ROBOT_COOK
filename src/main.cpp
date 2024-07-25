#include <Arduino.h>
#include "drive.h"
#include "sensors.h"
#include "servos.h"
#include "microswitch.h"
#include "utilities.h"
#include "config.h"

bool started = false;

int driveSpeed = 150;

float FLSpeedCalibrated = 1.3;
// 144 rotations in 30s
float FRSpeedCalibrated = 1.2;
// 142 rotations in 30s
float BLSpeedCalibrated = 1.5;
// 138 rotations in 30s
float BRSpeedCalibrated = 1.3;
// 142 rotations in 30s

bool frontStopExecuted = false; // Flag to indicate if frontStop has been executed



int wallSwitch = microswitch1Pin;

void setup() {
    Serial.begin(115200);
    initializeMotorPins();
    initializeSensorPins();
    initializeServoPins();
    initializeMicroSwitchPins();
    setAllMotorsToZero();
    
    // Attach interrupt to the left reflectance sensor pin    
}

void loop() {


setMotorSpeed(backRightMotorPin1, backRightMotorPin2, true, 50);
delay(1000);
setAllMotorsToZero();
delay(1000);
setMotorSpeed(backRightMotorPin1, backRightMotorPin2, false, 50);
delay(1000);
setAllMotorsToZero();
delay(1000);

// setMotorSpeed(backRightMotorPin1, backRightMotorPin2, true, 100);

}


// ONCE DONE ALL CALIBRATION AND PIN REARRANGEMENT, RUN THE FOLLOWING TEST:
// driveForward(driveSpeed);
// delay(600);
// driveBackward(255);
// delay(50);

// skipLinesAndStop2(reflectanceSensorLeftPin, reflectanceSensorRightPin, 0, driveSpeed, RIGHT);
// delay(10);

// flipCounters(driveSpeed, reflectanceSensorLeftPin, reflectanceSensorRightPin, microswitch1Pin);
// delay(10);
// skipLinesAndStop2(reflectanceSensorLeftPin, reflectanceSensorRightPin, 2, driveSpeed, LEFT);
// delay(10);


// setAllMotorsToZero();
