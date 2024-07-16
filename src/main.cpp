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

int wallSwitch = microswitch1Pin;


void setup() {
    Serial.begin(115200);
    initializeMotorPins();
    initializeSensorPins();
    initializeServoPins();
    initializeMicroSwitchPins();
}

void loop() {
    // // START
    // if (!started) {
    //     driveToWall(driveSpeed, microswitch1Pin);
    //     started = true;
    //     delay(1000); // Delay to stabilize after starting
    // }

    // // MOVING TO BUNS STATION (2)
    // skipLinesAndStop(reflectanceSensorLeftPin, reflectanceSensorRightPin, 1, driveSpeed, RIGHT);
    // pickupItem(servo1Control, servo2Control);
    // delay(500); // Delay to stabilize after picking up item

    // // MOVING TO CUTTING BOARD STATION (5)
    // flipCounters(driveSpeed, reflectanceSensorLeftPin, reflectanceSensorRightPin, wallSwitch);
    // skipLinesAndStop(reflectanceSensorLeftPin, reflectanceSensorRightPin, 0, driveSpeed, RIGHT);
    // dropItem(servo1Control, servo2Control);
    // delay(500); // Delay to stabilize after dropping item

    // // MOVING TO PATTIES STATION (1)
    // flipCounters(driveSpeed, reflectanceSensorLeftPin, reflectanceSensorRightPin, wallSwitch);
    // skipLinesAndStop(reflectanceSensorLeftPin, reflectanceSensorRightPin, 0, driveSpeed, LEFT);
    // pickupItem(servo1Control, servo2Control);
    // delay(500); // Delay to stabilize after picking up item

    // // MOVING TO COOKTOP STATION (6)
    // flipCounters(driveSpeed, reflectanceSensorLeftPin, reflectanceSensorRightPin, wallSwitch);
    // skipLinesAndStop(reflectanceSensorLeftPin, reflectanceSensorRightPin, 1, driveSpeed, RIGHT);
    // dropItem(servo1Control, servo2Control);
    // delay(500); // Delay to stabilize after dropping item

    // // MOVING TO BUNS STATION (2)
    // flipCounters(driveSpeed, reflectanceSensorLeftPin, reflectanceSensorRightPin, wallSwitch);
    // skipLinesAndStop(reflectanceSensorLeftPin, reflectanceSensorRightPin, 0, driveSpeed, LEFT);
    // pickupItem(servo1Control, servo2Control);
    // delay(500); // Delay to stabilize after picking up item

    // // MOVING TO CUTTING BOARD STATION (5)
    // flipCounters(driveSpeed, reflectanceSensorLeftPin, reflectanceSensorRightPin, wallSwitch);
    // skipLinesAndStop(reflectanceSensorLeftPin, reflectanceSensorRightPin, 0, driveSpeed, RIGHT);
    // dropItem(servo1Control, servo2Control);
    // delay(500); // Delay to stabilize after dropping item

    // // MOVING BACK TO THE BUNS STATION (2)
    // flipCounters(driveSpeed, reflectanceSensorLeftPin, reflectanceSensorRightPin, wallSwitch);
    // skipLinesAndStop(reflectanceSensorLeftPin, reflectanceSensorRightPin, 0, driveSpeed, RIGHT);
    // delay(500);

    testDriveForwardBackward();
    delay(3000);
    testDriveLeftRight();
    delay(3000);
    testRotate();
    delay(3000);
}