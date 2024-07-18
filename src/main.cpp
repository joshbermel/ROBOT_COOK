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
    setAllMotorsToZero();
}

void loop() {
    // delay(2000);
    // testDriveForwardBackward();
    // delay(2000);
    // testDriveLeftRight();
    // delay(2000);
    // testRotate();

    //driveBackward(1000);
   // testDriveForwardBackward();
  //analogWrite(8, 256);
  //analogWrite(13, 0);
  

    // back left
analogWrite(32,500);
  // back right
//    ledcWrite(2,500);
//   ledcWrite(3,0);

}