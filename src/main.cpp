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
// setMotorSpeed(backRightMotorPin1, backRightMotorPin2, true, 255);
// delay(1000);
// setAllMotorsToZero();
// delay(1000);

// setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, 255);
// delay(1000);
// setAllMotorsToZero();
// delay(1000);

// setMotorSpeed(backRightMotorPin1, backRightMotorPin2, true, 255);
// delay(1000);
// setAllMotorsToZero();
// delay(1000);

// 
//frontright is actually front left
//setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, true, 255);
// delay(1000);
// setAllMotorsToZero();
// delay(1000);


// change front right to back left
// setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, true, 255);
// delay(1000);
// setAllMotorsToZero();
// delay(1000);


testDetermineDirection(reflectanceSensorLeftPin, reflectanceSensorRightPin);
}