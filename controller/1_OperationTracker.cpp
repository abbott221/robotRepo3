


//#include "1_OperationTracker.h"
#include "controller.h"


//************************************************
//*                                              *
//*           BEGIN Operation CLASS              *
//*                                              *
//************************************************



Operation::Operation()
{
    dQueue = 0;
    fnPtr;
}


void Operation::setOperation( void (*dFnPtr) () )
{
    fnPtr = dFnPtr;
}


void Operation::setOperation( Operation dOperation )
{
    fnPtr = dOperation.fnPtr;
}




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
    tempOperation[trackerSize].setOperation( dOperation );
    trackerSize += 1;


    //resize selection
    tracker = new Operation[trackerSize];

    //copy the data back into selection
    for (int i = 0; i < trackerSize; i++)
    {
        tracker[i].setOperation(tempOperation[i]);
    }
}



