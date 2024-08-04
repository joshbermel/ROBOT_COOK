#include "servos.h"
#include "config.h" // Only if config.h is necessary for servo functions

// Initialize servo pins, and write to them to go to and 90 degree angle. 
void initializeServoPins() {
    pinMode(servo1Pin, OUTPUT);
    pinMode(servo2Pin, OUTPUT);
    pinMode(servo3Pin, OUTPUT);

    analogWriteFrequency(50);
}

void setServoAngle(int pin, int angle) {
    const int minPulseWidth = 500;
    const int maxPulseWidth = 2500; 
    const int pwmMax = 255;
    
    int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);

    int pwmValue = map(pulseWidth, 0, 20000, 0, pwmMax);

    analogWrite(pin, pwmValue);
}

// Keeps track of the servo angle that we are currently at.
int getServoAngle(ServoControl &servoControl) {
    return servoControl.currentAngle;
}

// Placeholder for picking up an item using 2 servos
void pickupItem(ServoControl &servoControl, ServoControl &servoControl2) {
    //this function will pick up an item by setting the servo angle
}

// Placeholder for dropping an item using 2 servos.
void dropItem(ServoControl &servoContrl, ServoControl &servoControl2) {
    // this function will drop an item by setting servo angles
}

void test4Servos() {
    setServoAngle(servo1Pin, 20);
    setServoAngle(servo2Pin, 33);
    setServoAngle(servo3Pin, 0);
    delay(1000);
    setServoAngle(servo3Pin, 130);
    delay(1000);
}