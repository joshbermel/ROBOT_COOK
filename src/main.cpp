#include <Arduino.h>
#include "drive.h"
#include "sensors.h"
#include "servos.h"
#include "microswitch.h"
#include "utilities.h"
#include "config.h"

bool started = false;

int driveSpeed = 150;

float FLSpeedCalibrated = 1.1;
// 144 rotations in 30s
float FRSpeedCalibrated = 1.1;
// 142 rotations in 30s
float BLSpeedCalibrated = 1.02;
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
}
void loop() {

// frontStop(50, frontReflectanceSensor, backReflectanceSensor);
// delay(5000);

// frontStop(40, frontReflectanceSensor, backReflectanceSensor);
// delay(3000);

// driveBackward(50);
// delay(100);

frontStop(50, frontReflectanceSensor, backReflectanceSensor);
delay(1000);
flipCounters();
delay(1000);

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
;