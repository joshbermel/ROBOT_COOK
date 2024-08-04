#include <Arduino.h>
#include "drive.h"
#include "sensors.h"
#include "servos.h"
#include "utilities.h"
#include "config.h"
#include "movement.h"


// Rotation Parameters
int rotateTime = 500;
int rotateSpeed = 110;

// Drive Speed Parameter
int driveSpeed = 50;

// Reflectance comparator thresholds
// high reflectance is for being centered on the black tape 
// higher threshold means both sensors must be high
int reflectanceThreshold = 2500;
int reflectanceDifferenceThreshold = 400;

// Detection speed parameter for sensing tape
int detectSpeed = 45;

// Station Delay Parameter
int stationDelay = 200;

// delay between lowering and closing the claw at each station
int servoDropDelay = 500;

// Calibrated Motor Speeds Parameters
float FLSpeedCalibrated = 1.1;
float FRSpeedCalibrated = 1.2;
float BLSpeedCalibrated = 1.02;
float BRSpeedCalibrated = 1.3;

// Servo Angle parameters
int raiseClawServo2Angle = 20;
int raiseClawServo3Angle = 33;
int lowerClawServo2Angle = 10;
int lowerClawServo3Angle = 23;
int grabBottomBunAngle = 70;
int grabPattyAngle = 70;
int grabTopBunAngle = 70;
int openClawAngle = 0;
