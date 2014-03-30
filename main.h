#ifndef MAIN_H
#define MAIN_H

//these were in main.cpp, are they necessary?
#include <string.h>
#include <stdio.h>

#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHWONKA.h>
#include <FEHBattery.h>




typedef enum
{
    tString = 0,
    tInt,
    tFloat,
    tDouble,
    tVoid
} TypeEnum;

typedef enum
{
    STRAIGHT = 0,
    LEFT,
    RIGHT,
    BACKWARDS,
    STOP
} PMode;





//#include "MVC3.h"

//#include "menuSetup.h"

#include "drive/driveHeaders.h"

//operationTracker goes here
//#include "controller/1_OperationTracker.h"
//#include "controller/2_MovementTracker.h"
#include "controller/controller.h"

#include "menuSetup.h"

#include "other.h"









extern float optoThresh;
extern float bLineDifThresh;
extern float yLineDifThresh;
extern float leftOptoThresh;
extern float rightOptoThresh;
extern float midOptoThresh;








extern int leftPower;
extern int rightPower;

extern int tempLeftPower;
extern int tempRightPower;

extern int currentMove;






extern FEHMotor lMotor;
extern FEHMotor rMotor;

extern ButtonBoard buttons;
extern FEHEncoder  leftEncoder;
extern FEHEncoder  rightEncoder;

extern AnalogInputPin CDS;

extern AnalogInputPin optoLeft;
extern AnalogInputPin optoMid;
extern AnalogInputPin optoRight;

extern FEHWONKA TheRPS;
extern FEHServo lolServo;
extern FEHBattery lolBattery;








#endif // MAIN_H
