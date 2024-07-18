#include <Arduino.h>
#include "drive.h"
#include "sensors.h"
#include "servos.h"
#include "microswitch.h"
#include "utilities.h"
#include "config.h"

int driveSpeed = 500;
int crawlSpeed = 200;

bool started = false;
int speed = 150;

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

// setMotorSpeed(frontRightMotorPin1, frontRightMotorPin2, true, speed);
//     setMotorSpeed(frontLeftMotorPin1, frontLeftMotorPin2, true, speed);
//     setMotorSpeed(backLeftMotorPin1, backLeftMotorPin2, true, speed);
//     setMotorSpeed(backRightMotorPin1, backRightMotorPin2, true, speed);



// testBothReflectanceSensor(reflectanceSensorLeftPin,reflectanceSensorRightPin);
// delay(20);
// leftStop(150,reflectanceSensorLeftPin, reflectanceSensorRightPin);

skipLinesAndStop(reflectanceSensorLeftPin,reflectanceSensorRightPin, 0, 100, LEFT);
}