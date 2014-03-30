


#include "driveHeaders.h"


//METHOD 0
//goes "straight" for specified time
void DriveForTime(float time)
{
    SetPowerStraight();

    //Sleep(time);

    float startTime = TimeNow();
    float dTime = 0.0;
    while( dTime < time )
    {
        //logDataStuffs();
        dTime = TimeNow() - startTime;
    }

    SetPowerStop();

    //return 'a';
}


//METHOD 1
//definitely turns left for specified time
void TurnLeftForTime(float time)
{
    SetPowerLeft();

    //rMotor.SetPercent(rightPower);
    //lMotor.SetPercent(leftPower);

    //Sleep(time);

    float startTime = TimeNow();
    float dTime = 0.0;
    while( dTime < time)
    {
        //logDataStuffs();
        dTime = TimeNow() - startTime;
    }

    //rMotor.Stop();
    //lMotor.Stop();

    SetPowerStop();
}

//METHOD 2
//definitely turns right for specified time
void TurnRightForTime(float time)
{
    SetPowerRight();

    //rMotor.SetPercent(-1 * rightPower);
    //lMotor.SetPercent(-1 * leftPower);

    //Sleep(time);

    float startTime = TimeNow();
    float dTime = 0.0;
    while( dTime < time)
    {
        //logDataStuffs();
        dTime = TimeNow() - startTime;
    }

    //rMotor.Stop();
    //lMotor.Stop();

    SetPowerStop();
}



//METHOD 3
//goes "straight" for specified time
void BackwardsForTime(float time)
{
    SetPowerBackwards();

    //rMotor.SetPercent(-1 * rightPower);
    //lMotor.SetPercent(leftPower);

    //Sleep(time);

    float startTime = TimeNow();
    float dTime = 0.0;
    while( dTime < time)
    {
        Sleep(1);

        //logDataStuffs();
        dTime = TimeNow() - startTime;
    }

    //rMotor.Stop();
    //lMotor.Stop();

    SetPowerStop();
}
