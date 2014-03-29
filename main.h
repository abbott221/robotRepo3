#ifndef MAIN_H
#define MAIN_H


#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>




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

#include "drive/driveHeaders.h"

//operationTracker goes here
//#include "controller/1_OperationTracker.h"
//#include "controller/2_MovementTracker.h"
#include "controller/controller.h"



#endif // MAIN_H
