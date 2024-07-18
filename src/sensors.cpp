#include "sensors.h"
#include "config.h"

// initializing sensor pins to be analog inputs
void initializeSensorPins() {
    pinMode(reflectanceSensorLeftPin, INPUT);
    pinMode(reflectanceSensorRightPin, INPUT);
}

// Reading the analog input from a reflectance sensor pin
int readReflectanceSensor(int SensorPin) {
    // return analogRead(pin1);
    return analogRead(SensorPin);
}

// Testing function to read and Serial print the readings from left and right reflectance sensor pins. 
void testBothReflectanceSensor(int leftSensorPin, int rightSensorPin) {
    // return analogRead(pin1);
    Serial.println("Left Pin Reading:");
    Serial.println(analogRead(leftSensorPin));

    Serial.println("Right Pin Reading:");
    Serial.println(analogRead(rightSensorPin));
}

// Testng function to real and Serial print the reading from a single reflectance sensor pin. 
void testSingleReflectanceSensor(int sensorPin) {
    // return analogRead(pin1);
    Serial.println("Sensor pin Reading:");
    Serial.println(analogRead(sensorPin));
}

// Determine the direction the robot must move given two reflectance sensor pins. 
// NOTE: If the relfectance sensors are too far from the competition surface, both will read maximum value and the output will be CENTERED
Direction determineDirection(int leftSensorPin, int rightSensorPin) {
    int leftSensorReading = analogRead(leftSensorReading);
    int rightSensorReading = analogRead(rightSensorPin);
    if (leftSensorReading <= reflectanceThreshold && rightSensorReading <= reflectanceThreshold) {
        return NOT_ON_LINE;
    } else if (abs(leftSensorReading - rightSensorReading) < reflectanceDifferenceThreshold && leftSensorReading > reflectanceThreshold && rightSensorReading > reflectanceThreshold) {
        return CENTERED;
    } else if (leftSensorReading > reflectanceThreshold && rightSensorReading <= reflectanceThreshold) {
        return LEFT;
    } else if (rightSensorReading > reflectanceThreshold && leftSensorReading <= reflectanceThreshold) {
        return RIGHT;
    } else {
        return NOT_ON_LINE;
    }
}

// Testing function for determine direction. Serial prints the corresponding direction that the robot should move. 
void testDetermineDirection(int leftSensorPin, int rightSensorPin) {
    int leftSensorReading = analogRead(leftSensorReading);
    int rightSensorReading = analogRead(rightSensorPin);
    if (leftSensorReading <= reflectanceThreshold && rightSensorReading <= reflectanceThreshold) {
        Serial.println("NOT_ON_LINE");
    } else if (abs(leftSensorReading - rightSensorReading) < reflectanceDifferenceThreshold && leftSensorReading > reflectanceThreshold && rightSensorReading > reflectanceThreshold) {
        Serial.println("CENTERED");
    } else if (leftSensorReading > reflectanceThreshold && rightSensorReading <= reflectanceThreshold) {
        Serial.println("LEFT");
    } else if (rightSensorReading > reflectanceThreshold && leftSensorReading <= reflectanceThreshold) {
        Serial.println("RIGHT");
    } else {
        Serial.println("NOT_ON_LINE");
    }
}

// Boolean to determine if the reflective sensors are centered on a black line.
bool isOnLine(int leftSensorPin, int rightSensorPin) {
    int leftSensorValue = readReflectanceSensor(leftSensorPin);
    int rightSensorValue = readReflectanceSensor(rightSensorPin);
    Direction dir = determineDirection(leftSensorValue, rightSensorValue);
    return dir == CENTERED;
}

// Testing function for isOnLine(). Serial prints the outputs that indicate if the sensors are centered on the line.
void testIsOnLine(int leftSensorPin, int rightSensorPin) {
    int leftSensorValue = readReflectanceSensor(leftSensorPin);
    int rightSensorValue = readReflectanceSensor(rightSensorPin);
    Direction dir = determineDirection(leftSensorValue, rightSensorValue);
    if (dir == CENTERED) {
        Serial.println("centered");
    }
    else {
        Serial.println("not centered");
    }
}