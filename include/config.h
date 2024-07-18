#ifndef CONFIG_H
#define CONFIG_H

// Motor pins
const int backRightMotorPin1 = 32;
const int backRightMotorPin2 = 33;
const int backLeftMotorPin1 = 27;
const int backLeftMotorPin2 = 14;
const int frontRightMotorPin1 = 20;
const int frontRightMotorPin2 = 21;
const int frontLeftMotorPin1 = 12;
const int frontLeftMotorPin2 = 13;

// PWM channels

// backwards
const int backRightPwmChannel1 = 0;
// forwards
const int backRightPwmChannel2 = 1;
const int backLeftPwmChannel1 = 2;
const int backLeftPwmChannel2 = 3;
const int frontRightPwmChannel1 = 4;
const int frontRightPwmChannel2 = 5;
const int frontLeftPwmChannel1 = 6;
const int frontLeftPwmChannel2 = 7;

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
const int reflectanceSensorLeftPin = 34;
const int reflectanceSensorRightPin = 35;

// Reflectance comparator thresholds
const int reflectanceThreshold = 400;
const int reflectanceDifferenceThreshold = 50;

#endif // CONFIG_H