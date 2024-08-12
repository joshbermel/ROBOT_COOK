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
int stationDelay = 0 ;

// delay between lowering and closing the claw at each station
int servoDropDelay = 500;

// Calibrated Motor Speeds Parameters
float FLSpeedCalibrated = 1.1;
float FRSpeedCalibrated = 1.1;
float BLSpeedCalibrated = 1.02;
float BRSpeedCalibrated = 1.2;

// Servo Angle parameters

// for big claw (one closest to chassis), higher angle bring the claw closer inside to the chassis
int raiseServoBigClawAngle = 45;
// for smaller claw (connecting chassis crane and claw), smaller angle brings it more vertical
int raiseServoSmallClawAngle = 120;
int lowerServoBigClawAngle = 28;
int lowerServoSmallClawAngle = 135;
int dropbunServoBigClawAngle = 30;
int dropbunServoSmallClawAngle = 20;
// we should drop both buns and patty at the drop patty angles
int droppattyServoBigClawAngle = 30;
int droppattyServoSmallClawAngle = 130;
int grabBottomBunAngle = 150;
int grabPattyAngle = 165;
int grabTopBunAngle = 150;
int openClawAngle = 0;
