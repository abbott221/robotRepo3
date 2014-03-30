


//#include "1_OperationTracker.h"
#include "controller.h"


//************************************************
//*                                              *
//*           BEGIN Operation CLASS              *
//*                                              *
//************************************************



Operation::Operation()
{
    jeffID = 0;

    voidPtr;
    intPtr;
    floatPtr;
    doublePtr;

    dataType = tVoid;
}

//old, add dQueue
void Operation::setOperation( void (*dFnPtr) () )
{
    voidPtr = dFnPtr;

    dataType = tVoid;
}



void Operation::setOperation( int callID, void (*dFnPtr) () )
{
    jeffID = callID;
    voidPtr = dFnPtr;

    dataType = tVoid;
}

//===============================

//old, add dQueue
void Operation::setOperation( void (*dFnPtr) (int value) )
{
    intPtr = dFnPtr;

    dataType = tInt;
}

void Operation::setOperation( int callID, void (*dFnPtr) (int value) )
{
    jeffID = callID;
    intPtr = dFnPtr;

    dataType = tInt;
}

//old, add dQueue
void Operation::setOperation( void (*dFnPtr) (float value) )
{
    floatPtr = dFnPtr;

    dataType = tFloat;
}



void Operation::setOperation( int callID, void (*dFnPtr) (float value) )
{
    jeffID = callID;
    floatPtr = dFnPtr;

    dataType = tFloat;
}

//old, add dQueue
void Operation::setOperation( void (*dFnPtr) (double value) )
{
    doublePtr = dFnPtr;

    dataType = tDouble;
}



void Operation::setOperation( int callID, void (*dFnPtr) (double value) )
{
    jeffID = callID;
    doublePtr = dFnPtr;

    dataType = tDouble;
}






//old, add dQueue
void Operation::setOperation( Operation dOperation )
{
    //fnPtr = dOperation.fnPtr;
//    if (dOperation.getDataType() == tVoid)
//    {
//        //voidPtr = void (dOperation.(*voidPtr)) ();
//        voidPtr = dOperation.voidPtr;
//    }

    voidPtr = dOperation.voidPtr;
    intPtr = dOperation.intPtr;
    floatPtr = dOperation.floatPtr;
    doublePtr = dOperation.doublePtr;


    //fnPtr = dOperation.getFnPtr();
}


void Operation::setOperation( int callID, Operation dOperation )
{
    jeffID = callID;
    voidPtr = dOperation.voidPtr;
    intPtr = dOperation.intPtr;
    floatPtr = dOperation.floatPtr;
    doublePtr = dOperation.doublePtr;
    //fnPtr = dOperation.getOperation();
}



void Operation::setJeffID(int jeff)
{
    jeffID = jeff;
}



TypeEnum Operation::getDataType()
{
    return dataType;
}



int Operation::getJeffID()
{
    return jeffID;
}



/*
int Operation::getOperation()
{
    return fnPtr;
}
/**/



//************************************************
//*                                              *
//*        BEGIN OperationTracker CLASS          *
//*                                              *
//************************************************


OperationTracker::OperationTracker()
{
    trackerSize = 0;
    tracker;
}


void OperationTracker::addOperation(Operation dOperation)
{
    //a temporary holder of the data
    Operation tempOperation[trackerSize + 1];


    for (int i = 0; i < trackerSize; i++)
    {
        tempOperation[i].setOperation(tracker[i]);
    }

    //add the new option
    tempOperation[trackerSize].setJeffID( dOperation.getJeffID() );
    tempOperation[trackerSize].setOperation( dOperation );
    //tempOperation[trackerSize].setOperation(jeffID, dOperation );
    //tempOperation[trackerSize].setJeffID( dOperation.getJeffID() );
    trackerSize += 1;


    //resize selection
    tracker = new Operation[trackerSize];

    //copy the data back into selection
    for (int i = 0; i < trackerSize; i++)
    {
        tracker[i].setOperation(tempOperation[i]);
    }
}



void OperationTracker::addOperation( int callID, void (*fnPtr) () )
{



    Operation dOperation;

    dOperation.setOperation(callID, fnPtr);

    this->addOperation(dOperation);



//    //a temporary holder of the data
//    Operation tempOperation[trackerSize + 1];


//    for (int i = 0; i < trackerSize; i++)
//    {
//        tempOperation[i].setOperation(tracker[i]);
//    }

//    //add the new option
//    tempOperation[trackerSize].setOperation( dOperation );
//    trackerSize += 1;


//    //resize selection
//    tracker = new Operation[trackerSize];

//    //copy the data back into selection
//    for (int i = 0; i < trackerSize; i++)
//    {
//        tracker[i].setOperation(tempOperation[i]);
//    }
}


void OperationTracker::addOperation( int callID, void (*fnPtr) (int value) )
{
    Operation dOperation;

    dOperation.setOperation(callID, fnPtr);

    this->addOperation(dOperation);
}

void OperationTracker::addOperation( int callID, void (*fnPtr) (float value) )
{
    Operation dOperation;

    dOperation.setOperation(callID, fnPtr);

    this->addOperation(dOperation);
}

void OperationTracker::addOperation( int callID, void (*fnPtr) (double value) )
{
    Operation dOperation;

    dOperation.setOperation(callID, fnPtr);

    this->addOperation(dOperation);
}

int OperationTracker::getTrackerSize()
{
    return trackerSize;
}





















