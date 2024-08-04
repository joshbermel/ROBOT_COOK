#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <ESP32Servo.h>

struct ServoControl {
    Servo servo;
    int currentAngle;
};

extern ServoControl servo1Control;
extern ServoControl servo2Control;
extern ServoControl servo3Control;

void initializeServoPins();
void setServoAngle(ServoControl &servoControl, int angle);
int getServoAngle(ServoControl &servoControl);
void pickupItem(ServoControl &servoControl, ServoControl &servoControl2);
void dropItem(ServoControl &servoControl, ServoControl &servoControl2);
void test4Servos();
void setServoAngle(int pin, int angle);

#endif // SERVOS_H