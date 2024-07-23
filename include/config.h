#ifndef CONFIG_H
#define CONFIG_H

// Motor pins
const int backLeftMotorPin1 = 32;
const int backLeftMotorPin2 = 33;
const int backRightMotorPin1 = 27;
const int backRightMotorPin2 = 14;
const int frontLeftMotorPin1 = 12;
const int frontLeftMotorPin2 = 13;
const int frontRightMotorPin1 = 20;
const int frontRightMotorPin2 = 21;

// Rotate time and speed
const int rotateTime = 500;
const int rotateSpeed = 100;

// PWM frequency and resolution
const int pwmFrequency = 10000;
const int pwmResolution = 10;

// Servo motor pins
const int servo1Pin = 26;
const int servo2Pin = 27;

// Microswitch sensor pins
const int microswitch1Pin = 32;
const int microswitch2Pin = 33;
const int microswitch3Pin = 14;

// Reflectance sensor pins
const int reflectanceSensorLeftPin = 38;
const int reflectanceSensorRightPin = 34;

// Reflectance comparator thresholds
// high reflectance is for being centered on the black tape 
// higher threshold means both sensors must be high
const int reflectanceThreshold = 2800;
const int reflectanceDifferenceThreshold = 400;

// driving and tuning speeds


#endif // CONFIG_H