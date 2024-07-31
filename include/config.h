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
const int servo2Pin = 25;
const int servo3Pin = 5;
const int servo4Pin = 15;

// Microswitch sensor pins
const int microswitch1Pin = 32;
const int microswitch2Pin = 33;
const int microswitch3Pin = 14;

const int frontReflectanceSensor = 34;
const int backReflectanceSensor = 38;

// Reflectance comparator thresholds
// high reflectance is for being centered on the black tape 
// higher threshold means both sensors must be high
const int reflectanceThreshold = 930;
const int reflectanceDifferenceThreshold = 400;

// Calibrated Motor Speeds from Testing. Placeholder Values until testing is complete
extern float FLSpeedCalibrated;
extern float FRSpeedCalibrated;
extern float BLSpeedCalibrated;
extern float BRSpeedCalibrated;

// This is only used once, at startup
// reverse time from start to buns (getting bottom bun)
extern float StoBreverseTime;

// reverse time from buns to cutting board (placing bottom bun)
extern float BtoCBreverseTime;

// forward time from cutting board to patties (getting burger)
extern float CBtoPforwardTime;

// forward time from patties to cooktop (cooking burger)
extern float PtoCTforwardTime;

// forward time from cooktop to buns (getting top bun )
extern float CTtoBforwardTime;

// reverse time from buns to cutting board (placing top bun)
extern float BtoCBreverseTime;

// reverse time from cutting board to buns (getting bottom bun)
extern float CBtoBreverseTime;



#endif // CONFIG_H