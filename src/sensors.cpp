#include "sensors.h"
#include "config.h"

// initializing sensor pins to be analog inputs
void initializeSensorPins() {
    pinMode(reflectanceSensorLeftPin, INPUT);
    pinMode(reflectanceSensorRightPin, INPUT);
}

// Reading the analog input from a reflectance sensor pin
bool readReflectanceSensor(int SensorPin) {
    // return analogRead(pin1);
    return (analogRead(SensorPin) > reflectanceThreshold);
}

// Testing function to read and Serial print the readings from left and right reflectance sensor pins. 
void testBothReflectanceSensor(int leftSensorPin, int rightSensorPin) {
    // return analogRead(pin1);
    Serial.println("Left Pin Reading:");
    Serial.println(readReflectanceSensor(leftSensorPin));

    Serial.println("Right Pin Reading:");
    Serial.println(readReflectanceSensor(rightSensorPin));
    delay(50);
}

// Testng function to real and Serial print the reading from a single reflectance sensor pin. 
void testSingleReflectanceSensor(int sensorPin) {
    // return analogRead(pin1);
    Serial.println(readReflectanceSensor(sensorPin));
    delay(50);
}

// Determine the direction the robot must move given two reflectance sensor pins. 
// NOTE: If the relfectance sensors are too far from the competition surface, both will read maximum value and the output will be CENTERED
Direction determineDirection(int leftSensorPin, int rightSensorPin) {
    int leftSensorReading = readReflectanceSensor(leftSensorPin);
    int rightSensorReading = readReflectanceSensor(rightSensorPin);
    if (leftSensorReading && rightSensorReading) {
        return CENTERED;
    } else if (leftSensorReading && !rightSensorReading) {
        return LEFT;
    } else if (!leftSensorReading && rightSensorReading) {
        return RIGHT;
    } else {
        return NOT_ON_LINE;
    }
}

// Testing function for determine direction. Serial prints the corresponding direction that the robot should move. 
void testDetermineDirection(int leftSensorPin, int rightSensorPin) {
    int leftSensorReading = readReflectanceSensor(leftSensorPin);
    int rightSensorReading = readReflectanceSensor(rightSensorPin);
    if (leftSensorReading && rightSensorReading) {
        Serial.println("Centered");
    } else if (leftSensorReading && !rightSensorReading) {
        Serial.println("Left");
    } else if (!leftSensorReading && rightSensorReading) {
        Serial.println("Right");
    } else {
        Serial.println("Not on Line");
    }
}

// Boolean to determine if the reflective sensors are centered on a black line.
bool isOnLine(int leftSensorPin, int rightSensorPin) {
    return (readReflectanceSensor(leftSensorPin) && readReflectanceSensor(rightSensorPin));
}

// Testing function for isOnLine(). Serial prints the outputs that indicate if the sensors are centered on the line.
void testIsOnLine(int leftSensorPin, int rightSensorPin) {
    if (readReflectanceSensor(leftSensorPin) && readReflectanceSensor(rightSensorPin)) {
        Serial.println("centered");
    }
    else {
        Serial.println("not centered");
    }
}