




#include "driveHeaders.h"


/*
void tracker()
{
    Operation addMe;
    addMe.setOperation(&DriveForTime);

    opTracker.addOperation( addMe );
}
*/




void SetPowerStraight() {
    //
}
void SetPowerLeft() {
    //
}
void SetPowerRight() {
    //
}
void SetPowerBackwards() {
    //
}
void SetPowerStop() {
    //
}



void SetPowerStraight(int left, int right) {
    //
}
void SetPowerLeft(int left, int right) {
    //
}
void SetPowerRight(int left, int right) {
    //
}
void SetPowerBackwards(int left, int right) {
    //
}










void theLoop()
{
    double useDoubleValue = 0.0;
    float useFloatValue = 0.0;
    int useIntValue = 0;

    /*
     * THE METHOD "logDataStuffs()" HAS REMOVED THE NEED FOR THE COMPLETION VARIABLE
     *
     *
    for (int i = 0; i < numMoves; i++)
    {
        loopMoves[i].setCompletion(false);
    }
    */

    //currentMove

    for (currentMove = 0; currentMove < mTracker.getTrackerSize(); currentMove++)
    {

        useDoubleValue = mTracker.tracker[currentMove].getDoubleValue();
        useFloatValue = mTracker.tracker[currentMove].getFloatValue();
        useIntValue = mTracker.tracker[currentMove].getIntValue();

        /*
         * USE "logDataStuffs()" INSTEAD
         *
         *
        if (configRPS)
        {
            LCD.Write(TheRPS.Heading());
            LCD.Write(" ");
            LCD.Write(TheRPS.X());
            LCD.Write(" ");
            LCD.WriteLine(TheRPS.Y());
        }
        */

        if (mTracker.tracker[currentMove].getState() == true)
        {
            //milliCounter = 0;
            //initialMoveAngle = TheRPS.Heading();


            leftEncoder.ResetCounts();
            rightEncoder.ResetCounts();

            //this sleep timer was for diagnosis of the first move not being a proper distance?
            //Sleep(.25);


            tempLeftPower = leftPower;
            tempRightPower = rightPower;



            int processID;
            processID = mTracker.tracker[currentMove].getDriveProcessTranslationID();



            TypeEnum useDataType = opTracker.tracker[processID].getDataType();

            if (useDataType == tVoid)
            {
                opTracker.tracker[processID].voidPtr;
            }
            else if (useDataType == tInt)
            {
                opTracker.tracker[processID].intPtr(useIntValue);
            }
            else if (useDataType == tFloat)
            {
                opTracker.tracker[processID].floatPtr(useFloatValue);
            }
            else if (useDataType == tDouble)
            {
                opTracker.tracker[processID].doublePtr(useDoubleValue);
            }




            leftPower = tempLeftPower;
            rightPower = tempRightPower;


        }



    } //end for loop
}









