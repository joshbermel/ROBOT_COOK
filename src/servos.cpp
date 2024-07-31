#include "servos.h"
#include "config.h" // Only if config.h is necessary for servo functions

ServoControl servo1Control;
ServoControl servo2Control;
ServoControl servo3Control;
ServoControl servo4Control;

// Initialize servo pins, and write to them to go to and 90 degree angle. 
void initializeServoPins() {
    servo1Control.servo.attach(servo1Pin);
    servo2Control.servo.attach(servo2Pin);
    servo3Control.servo.attach(servo3Pin);
    servo4Control.servo.attach(servo4Pin);
    servo1Control.currentAngle = 90;
    servo2Control.currentAngle = 90;
    servo3Control.currentAngle = 90;
    servo4Control.currentAngle = 90;
    servo1Control.servo.write(servo1Control.currentAngle);
    servo2Control.servo.write(servo2Control.currentAngle);
    servo3Control.servo.write(servo3Control.currentAngle);
    servo4Control.servo.write(servo4Control.currentAngle);
}

// Sets a servo to a given angle argument.
void setServoAngle(ServoControl &servoControl, int angle) {
    servoControl.servo.write(angle);
    servoControl.currentAngle = angle;
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
    
    // Set all servos to 110 degrees
    setServoAngle(servo1Control, 110);
    delay(1000);

    setServoAngle(servo2Control, 110);
    delay(1000);

    setServoAngle(servo3Control, 110);
    delay(1000);

    setServoAngle(servo4Control, 110);
    delay(1000);

    // Rotate all servos back to 0 degrees
    setServoAngle(servo1Control, 0);
    delay(1000);

     setServoAngle(servo2Control, 0);
    delay(1000);

     setServoAngle(servo3Control, 0);
    delay(1000);

     setServoAngle(servo4Control, 0);
    delay(1000);
}