#include <Arduino.h>
#include "drive.h"
#include "sensors.h"
#include "servos.h"
#include "microswitch.h"
#include "utilities.h"
#include "config.h"

bool started = false;

int driveSpeed = 150;

// Wheel Calibrations Depending on Motor Strength.
float FLSpeedCalibrated = 1.1;
float FRSpeedCalibrated = 1.2;
float BLSpeedCalibrated = 1.02;
float BRSpeedCalibrated = 1.3;

// reverse time from buns to cutting board (placing bottom bun)
float StoBreverseTime = 260;
float BtoCBreverseTime = 300;
float CBtoPforwardTime = 310;
float PtoCTforwardTime = 250;
float CTtoBforwardTime = 400;
float CBtoBreverseTime = 260;

bool frontStopExecuted = false; // Flag to indicate if frontStop has been executed

// int wallSwitch = microswitch1Pin;

void setup() {
    Serial.begin(115200);
    initializeMotorPins();
    initializeSensorPins();
    initializeServoPins();
    initializeMicroSwitchPins();
    setAllMotorsToZero();
}
void loop() {

test4Servos();

}