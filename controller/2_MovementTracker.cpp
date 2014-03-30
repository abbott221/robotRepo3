


#include "controller.h"
//#include "2_MovementTracker.h"



//************************************************
//*                                              *
//*           BEGIN MOVEMENT CLASS               *
//*                                              *
//************************************************



movement::movement()
{
    operation = 0;
    dataType = tVoid;
    intValue = 0;
    floatValue = 0.0;
    doubleValue = 0.0;
    movementState = false;

    driveProcessTranslationID = 0;
}



//"SETTER" METHODS HERE

void movement::setMovement(int dOperation, int dValue)
{
    operation = dOperation;

    for (int i = 0; i < opTracker.getTrackerSize(); i++)
    {
        if ( dOperation == opTracker.tracker[i].getJeffID() )
        {
            driveProcessTranslationID = i;
        }
    }


    dataType = tInt;
    intValue = dValue;
    movementState = true;
}

void movement::setMovement(int dOperation, float dValue)
{
    operation = dOperation;

    for (int i = 0; i < opTracker.getTrackerSize(); i++)
    {
        if ( dOperation == opTracker.tracker[i].getJeffID() )
        {
            driveProcessTranslationID = i;
        }
    }

    dataType = tFloat;
    floatValue = dValue;
    movementState = true;
}

void movement::setMovement(int dOperation, double dValue)
{
    operation = dOperation;

    for (int i = 0; i < opTracker.getTrackerSize(); i++)
    {
        if ( dOperation == opTracker.tracker[i].getJeffID() )
        {
            driveProcessTranslationID = i;
        }
    }

    dataType = tDouble;
    doubleValue = dValue;
    movementState = true;
}

void movement::setMovement(int dOperation)
{
    operation = dOperation;

    for (int i = 0; i < opTracker.getTrackerSize(); i++)
    {
        if ( dOperation == opTracker.tracker[i].getJeffID() )
        {
            driveProcessTranslationID = i;
        }
    }

    dataType = tVoid;
    movementState = true;
}

void movement::setMovement(movement otherMove)
{
    //Operation dOperation;

    //dOperation.setOperation( otherMove.getOperation() );

    //WAIT. THIS IS TALKING ABOUT OPERATION AS IN JEFFID???

    this->setMovement( otherMove.getOperation() );

    //operation.setOperation( dOperation );

    driveProcessTranslationID = otherMove.driveProcessTranslationID;

    dataType = otherMove.getDataType();
    intValue = otherMove.getIntValue();
    floatValue = otherMove.getFloatValue();
    doubleValue = otherMove.getDoubleValue();
    //no voidValue
    movementState = otherMove.getState();
}

void movement::setState(bool dState)
{
    if (dState == true)
    {
        movementState = true;
    }
    else
    {
        movementState = false;
    }
}





//"GETTER" METHODS HERE

int movement::getOperation()
{
    return operation;
}

TypeEnum movement::getDataType()
{
    return dataType;
}

int movement::getIntValue()
{
    return intValue;
}

float movement::getFloatValue()
{
    return floatValue;
}

double movement::getDoubleValue()
{
    return doubleValue;
}

bool movement::getState()
{
    return movementState;
}

int movement::getDriveProcessTranslationID()
{
    return driveProcessTranslationID;
}




//************************************************
//*                                              *
//*       BEGIN MovementTracker CLASS            *
//*                                              *
//************************************************



MovementTracker::MovementTracker()
{
    trackerSize = 0;
    tracker;
}


void MovementTracker::addMovement(movement dMove)
{
    //a temporary holder of the data
    movement tempTracker[trackerSize + 1];


    for (int i = 0; i < trackerSize; i++)
    {
        tempTracker[i].setMovement(tracker[i]);
    }

    //add the new option
    tempTracker[trackerSize].setMovement( dMove );
    trackerSize += 1;


    //resize selection
    tracker = new movement[trackerSize];

    //copy the data back into selection
    for (int i = 0; i < trackerSize; i++)
    {
        tracker[i].setMovement(tempTracker[i]);
    }
}



int MovementTracker::addMovement(int dOp, int value)
{
    movement dMove;
    dMove.setMovement(dOp, value);

    this->addMovement(dMove);


//    //a temporary holder of the data
//    movement tempTracker[trackerSize + 1];


//    for (int i = 0; i < trackerSize; i++)
//    {
//        tempTracker[i].setMovement(tracker[i]);
//    }

//    //add the new option
//    tempTracker[trackerSize].setMovement( dMove );
//    trackerSize += 1;


//    //resize selection
//    tracker = new movement[trackerSize];

//    //copy the data back into selection
//    for (int i = 0; i < trackerSize; i++)
//    {
//        tracker[i].setMovement(tempTracker[i]);
//    }
}

int MovementTracker::addMovement(int dOp, float value)
{
    movement dMove;
    dMove.setMovement(dOp, value);

    this->addMovement(dMove);
}

int MovementTracker::addMovement(int dOp, double value)
{
    movement dMove;
    dMove.setMovement(dOp, value);

    this->addMovement(dMove);
}

int MovementTracker::addMovement(int dOp)
{
    movement dMove;
    dMove.setMovement(dOp);

    this->addMovement(dMove);
}

int MovementTracker::getTrackerSize()
{
    return trackerSize;
}























