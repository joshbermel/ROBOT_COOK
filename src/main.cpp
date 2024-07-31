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
float FRSpeedCalibrated = 1.2;
float BLSpeedCalibrated = 1.02;
float BRSpeedCalibrated = 1.3;

float Sto2reverseTime = 150;

// reverse time from buns to cutting board (placing bottom bun)
float StoBreverseTime = 260;
float BtoCBreverseTime = 300;
float CBtoPforwardTime = 310;
float PtoCTforwardTime = 250;
float CTtoBforwardTime = 400;
float CBtoBreverseTime = 260;

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

delay(3000);
runThroughCourse();

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