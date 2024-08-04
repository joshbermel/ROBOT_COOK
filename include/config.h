#ifndef CONFIG_H
#define CONFIG_H

// PIN CONFIGURATIONS

// Motor pins
const int backLeftMotorPin1 = 12;
const int backLeftMotorPin2 = 13;
const int frontRightMotorPin1 = 27;
const int frontRightMotorPin2 = 14;
const int backRightMotorPin1 = 33;
const int backRightMotorPin2 = 32;
const int frontLeftMotorPin1 = 20;
const int frontLeftMotorPin2 = 21;

// Servo motor pins
const int servo1Pin = 26;
const int servo2Pin = 25;
const int servo3Pin = 5;

// Reflectance sensor pins
const int frontReflectanceSensor = 34;
const int backReflectanceSensor = 38;

// Rotation Parameters
extern int rotateTime; // in millis
extern int rotateSpeed;

// Drive Speed Parameter
extern int driveSpeed;

// PWM frequency and resolution
const int pwmFrequency = 10000;
const int pwmResolution = 10;

// Reflectance comparator thresholds
// high reflectance is for being centered on the black tape 
// higher threshold means both sensors must be high
extern int reflectanceThreshold;
extern int reflectanceDifferenceThreshold;

// Detection speed parameter for sensing tape
extern int detectSpeed;

// Station Delay Parameter
extern int stationDelay;

// delay between lowering and closing the claw at each station
extern int servoDropDelay;

// Calibrated Motor Speeds Parameters
extern float FLSpeedCalibrated;
extern float FRSpeedCalibrated;
extern float BLSpeedCalibrated;
extern float BRSpeedCalibrated;

// Servo Angle parameters
extern int raiseClawServo2Angle;
extern int raiseClawServo3Angle;
extern int lowerClawServo2Angle;
extern int lowerClawServo3Angle;
extern int grabBottomBunAngle;
extern int grabPattyAngle;
extern int grabTopBunAngle;
extern int openClawAngle;


#endif // CONFIG_H