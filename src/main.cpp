#include <Arduino.h>
#include "drive.h"
#include "sensors.h"
#include "servos.h"
#include "microswitch.h"
#include "utilities.h"
#include "config.h"

bool started = false;


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

}