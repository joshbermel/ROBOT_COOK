#include "servos.h"
#include "config.h" // Only if config.h is necessary for servo functions

ServoControl servo1Control;
ServoControl servo2Control;

void initializeServoPins() {
    servo1Control.servo.attach(servo1Pin);
    servo2Control.servo.attach(servo2Pin);
    servo1Control.currentAngle = 90;
    servo2Control.currentAngle = 90;
    servo1Control.servo.write(servo1Control.currentAngle);
    servo2Control.servo.write(servo2Control.currentAngle);
}

void setServoAngle(ServoControl &servoControl, int angle) {
    servoControl.servo.write(angle);
    servoControl.currentAngle = angle;
}

int getServoAngle(ServoControl &servoControl) {
    return servoControl.currentAngle;
}

void pickupItem(ServoControl &servoControl, ServoControl &servoControl2) {
    //this function will pick up an item by setting the servo angle
}

void dropItem(ServoControl &servoContrl, ServoControl &servoControl2) {
    // this function will drop an item by setting servo angles
}