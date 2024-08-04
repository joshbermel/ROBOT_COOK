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

void test4Servos() {
    setServoAngle(servo1Pin, 20);
    setServoAngle(servo2Pin, 33);
    setServoAngle(servo3Pin, 0);
    delay(1000);
    setServoAngle(servo3Pin, 130);
    delay(1000);
}

void raiseClaw(){
    setServoAngle(servo2Pin, raiseClawServo2Angle);
    setServoAngle(servo3Pin, raiseClawServo3Angle);
}

void lowerClaw(){
    setServoAngle(servo2Pin, lowerClawServo2Angle);
    setServoAngle(servo3Pin, lowerClawServo3Angle);
}

void openClaw(){
    setServoAngle(servo1Pin, openClawAngle);
}

void grabBottomBun(){
    setServoAngle(servo1Pin, grabBottomBunAngle);
}

void grabPatty(){
    setServoAngle(servo1Pin, grabPattyAngle);
}

void grabTopBun(){
    setServoAngle(servo1Pin, grabTopBunAngle);
}