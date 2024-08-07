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
int driveSpeed = 25;

// Reflectance comparator thresholds
// high reflectance is for being centered on the black tape 
// higher threshold means both sensors must be high
int reflectanceThreshold = 1500;
int reflectanceDifferenceThreshold = 400;

// Detection speed parameter for sensing tape
int detectSpeed = 30;

// Station Delay Parameter
int stationDelay = 200;

// delay between lowering and closing the claw at each station
int servoDropDelay = 600;

// Calibrated Motor Speeds Parameters
float FLSpeedCalibrated = 1.1;
float FRSpeedCalibrated = 1.1;
float BLSpeedCalibrated = 1.02;
float BRSpeedCalibrated = 1.2;

// Servo Angle parameters

// for big claw (one closest to chassis), higher angle bring the claw closer inside to the chassis
int raiseServoBigClawAngle = 40;
// for smaller claw (connecting chassis crane and claw), smaller angle brings it more vertical
int raiseServoSmallClawAngle = 27;
int lowerServoBigClawAngle = 0;
int lowerServoSmallClawAngle = 5;
int dropbunServoBigClawAngle = 25;
int dropbunServoSmallClawAngle = 15;
int droppattyServoBigClawAngle = 35;
int droppattyServoSmallClawAngle = 25;
int grabBottomBunAngle = 102;
int grabPattyAngle = 123;
int grabTopBunAngle = 102;
int openClawAngle = 0;
