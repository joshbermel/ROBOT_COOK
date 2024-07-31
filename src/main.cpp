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
float FRSpeedCalibrated = 1.25;
// 142 rotations in 30s
float BLSpeedCalibrated = 1.02;
// 138 rotations in 30s
float BRSpeedCalibrated = 1.35;
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

backStop(35, frontReflectanceSensor, backReflectanceSensor, 150);
delay(3000);
// flipCounters();
// delay(2000);

}

//SERVO TESTING

// setServoAngle(servo1Control, 110);
//     delay(1000); // Wait for 1 second

//    setServoAngle(servo2Control, 110);
//     delay(1000); // Wait for 1 second

//     setServoAngle(servo3Control, 110);
//     delay(1000); // Wait for 1 second\

//     setServoAngle(servo4Control, 110);
//     delay(1000);

//     // Rotate servo1Control back to 0 degrees
//     setServoAngle(servo1Control, 0);
//     delay(1000); // Wait for 1 second

//      setServoAngle(servo2Control, 0);
//     delay(1000); // Wait for 1 second

//      setServoAngle(servo3Control, 0);
//     delay(1000); // Wait for 1 second

//      setServoAngle(servo4Control, 0);
//     delay(1000); // Wait for 1 second
;