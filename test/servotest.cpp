#include <Arduino.h>
#include "servos.h"
#include "config.h" // Only if config.h is necessary for this test

void setup() {
    Serial.begin(115200);
    initializeServoPins();
    Serial.println("Servo Test Setup complete.");
}

void loop() {
    testSetServoAngle(servo1Control, 0);
    delay(1000);
    testSetServoAngle(servo1Control, 90);
    delay(1000);
    testSetServoAngle(servo1Control, 180);
    delay(1000);

    testSetServoAngle(servo2Control, 0);
    delay(1000);
    testSetServoAngle(servo2Control, 90);
    delay(1000);
    testSetServoAngle(servo2Control, 180);
    delay(1000);

    while (true);
}

void testSetServoAngle(ServoControl &servoControl, int angle) {
    setServoAngle(servoControl, angle);
    int currentAngle = getServoAngle(servoControl);
    Serial.print("Set servo to angle ");
    Serial.print(angle);
    Serial.print(". Current angle: ");
    Serial.println(currentAngle);
}