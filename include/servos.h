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
void test4Servos();
void setServoAngle(int pin, int angle);
void raiseClaw();
void lowerClaw();
void openClaw();
void grabBottomBun();
void grabPatty();
void grabTopBun();


#endif // SERVOS_H