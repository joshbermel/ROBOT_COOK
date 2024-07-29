#ifndef CONFIG_H
#define CONFIG_H

// Motor pins
const int backLeftMotorPin1 = 33;
const int backLeftMotorPin2 = 32;
const int frontRightMotorPin1 = 21;
const int frontRightMotorPin2 = 20;
const int backRightMotorPin1 = 13;
const int backRightMotorPin2 = 12;
const int frontLeftMotorPin1 = 14;
const int frontLeftMotorPin2 = 27;


// Rotate time and speed
const int rotateTime = 500;
const int rotateSpeed = 100;

// Drive Speed
extern int driveSpeed;

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

const int frontReflectanceSensor = 34;
const int backReflectanceSensor = 38;

// Reflectance comparator thresholds
// high reflectance is for being centered on the black tape 
// higher threshold means both sensors must be high
const int reflectanceThreshold = 2800;
const int reflectanceDifferenceThreshold = 400;

// Calibrated Motor Speeds from Testing. Placeholder Values until testing is complete
extern float FLSpeedCalibrated;
extern float FRSpeedCalibrated;
extern float BLSpeedCalibrated;
extern float BRSpeedCalibrated;


#endif // CONFIG_H