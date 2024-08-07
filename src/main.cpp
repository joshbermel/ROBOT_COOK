#include <Arduino.h>
#include "drive.h"
#include "sensors.h"
#include "servos.h"
#include "utilities.h"
#include "config.h"
#include "movement.h"


void setup() {
    Serial.begin(115200);
    initializeMotorPins();
    initializeSensorPins();
    initializeServoPins();
    setAllMotorsToZero();
}
void loop() {

delay(3000);
burger2();
delay(100000);

// dropClaw();
// delay(1000);
// raiseClaw();
// delay(1000);

}