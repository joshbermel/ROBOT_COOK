#include "servos.h"
#include "config.h" // Only if config.h is necessary for servo functions

// Initialize servo pins, and write to them to go to and 90 degree angle. 
void initializeServoPins() {
    pinMode(servoBigClawPin, OUTPUT);
    pinMode(servoSmallClawPin, OUTPUT);
    pinMode(servoClawPin, OUTPUT);

    analogWriteFrequency(50);

    // setServoAngle(servo2Pin, 0);
    // setServoAngle(servo3Pin, 0);

    raiseClaw();
    openClaw();

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
    setServoAngle(servoBigClawPin, 20);
    setServoAngle(servoSmallClawPin, 33);
    setServoAngle(servoClawPin, 0);
    delay(1000);
    setServoAngle(servoClawPin, 130);
    delay(1000);
}

void raiseClaw(){
    setServoAngle(servoBigClawPin, raiseServoBigClawAngle);
    setServoAngle(servoSmallClawPin, raiseServoSmallClawAngle);
}

void lowerClaw(){
    setServoAngle(servoBigClawPin, lowerServoBigClawAngle);
    setServoAngle(servoSmallClawPin, lowerServoSmallClawAngle);
}

void openClaw(){
    setServoAngle(servoClawPin, openClawAngle);
}

void grabBottomBun(){
    setServoAngle(servoClawPin, grabBottomBunAngle);
}

void grabPatty(){
    setServoAngle(servoClawPin, grabPattyAngle);
}

void grabTopBun(){
    setServoAngle(servoClawPin, grabTopBunAngle);
}