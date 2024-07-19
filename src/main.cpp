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
    
    // Attach interrupt to the left reflectance sensor pin    
}

void loop() {
skipLinesAndStop2(reflectanceSensorLeftPin, reflectanceSensorRightPin, 3, 100, LEFT);
delay(5000);
}