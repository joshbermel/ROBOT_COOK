#include <Arduino.h>
#include "drive.h"
#include "sensors.h"
#include "servos.h"
#include "microswitch.h"
#include "utilities.h"
#include "config.h"

int driveSpeed = 150;

bool started = false;

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

// List of functions that need to be tested, in Order:


skipLinesAndStop(reflectanceSensorLeftPin,reflectanceSensorRightPin, 0, driveSpeed, LEFT);
skipLinesAndStop(reflectanceSensorLeftPin,reflectanceSensorRightPin, 0, driveSpeed, RIGHT);
skipLinesAndStop(reflectanceSensorLeftPin,reflectanceSensorRightPin, 1, driveSpeed, LEFT);
skipLinesAndStop(reflectanceSensorLeftPin,reflectanceSensorRightPin, 1, driveSpeed, RIGHT);

skipLinesAndStop2(reflectanceSensorLeftPin,reflectanceSensorRightPin, 0, driveSpeed, LEFT);
skipLinesAndStop2(reflectanceSensorLeftPin,reflectanceSensorRightPin, 0, driveSpeed, RIGHT);
skipLinesAndStop2(reflectanceSensorLeftPin,reflectanceSensorRightPin, 1, driveSpeed, LEFT);
skipLinesAndStop2(reflectanceSensorLeftPin,reflectanceSensorRightPin, 1, driveSpeed, RIGHT);

driveForward(driveSpeed);
delay(2000);
stopRobot2();

rotate180();
delay(1000);
rotate180();
delay(1000);

}