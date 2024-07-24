#include "sensors.h"
#include "config.h"

// initializing sensor pins to be analog inputs
void initializeSensorPins() {
    pinMode(frontReflectanceSensor, INPUT);
    pinMode(backReflectanceSensor, INPUT);
}

// Reading the analog input from a reflectance sensor pin
bool readReflectanceSensor(int SensorPin) {
    // return analogRead(pin1);
    return (analogRead(SensorPin) > reflectanceThreshold);
}

// Testing function to read and Serial print the readings from left and right reflectance sensor pins. 
void testBothReflectanceSensor() {
    // return analogRead(pin1);
    Serial.println("Front Pin Reading:");
    Serial.println(readReflectanceSensor(frontReflectanceSensor));

    Serial.println("Back Pin Reading:");
    Serial.println(readReflectanceSensor(backReflectanceSensor));
    delay(30);
}

// Testng function to real and Serial print the reading from a single reflectance sensor pin. 
void testSingleReflectanceSensor(int sensorPin) {
    // return analogRead(pin1);
    Serial.println(readReflectanceSensor(sensorPin));
    delay(30);
}

// Determine the direction the robot must move given two reflectance sensor pins. 
// NOTE: If the relfectance sensors are too far from the competition surface, both will read maximum value and the output will be CENTERED
Direction determineDirection() {
    int frontSensorReading = readReflectanceSensor(frontReflectanceSensor);
    int backSensorReading = readReflectanceSensor(backReflectanceSensor);
    if (frontSensorReading && backSensorReading) {
        return CENTERED;
    } else if (frontSensorReading && !backSensorReading) {
        return FORWARD;
    } else if (!frontSensorReading && backSensorReading) {
        return BACKWARD;
    } else {
        return NOT_ON_LINE;
    }
}


// Testing function for determine direction. Serial prints the corresponding direction that the robot should move. 
void testDetermineDirection() {
    int frontSensorReading = readReflectanceSensor(frontReflectanceSensor);
    int backSensorReading = readReflectanceSensor(backReflectanceSensor);
    if (frontSensorReading && backSensorReading) {
        Serial.println("Centered");
    } else if (frontSensorReading && !backSensorReading) {
        Serial.println("Forward");
    } else if (!frontSensorReading && backSensorReading) {
        Serial.println("Backward");
    } else {
        Serial.println("Not on Line");
    }
    delay(30);
}

// Boolean to determine if the reflective sensors are centered on a black line.
bool isOnLine() {
    return (readReflectanceSensor(frontReflectanceSensor) && readReflectanceSensor(backReflectanceSensor));
}

// Testing function for isOnLine(). Serial prints the outputs that indicate if the sensors are centered on the line.
void testIsOnLine() {
    if (readReflectanceSensor(frontReflectanceSensor) && readReflectanceSensor(backReflectanceSensor)) {
        Serial.println("centered");
    }
    else {
        Serial.println("not centered");
    }
}