
#include "driveHeaders.h"




//METHOD  21
void BlackLineFollow(double time){
    lMotor.SetPercent(60);
    rMotor.SetPercent(-1 * 60);

    double startTime = TimeNow();
    double dTime = 0.0;

    while(dTime < time){
        if(myAbsolute(midOptoThresh-optoMid.Value())>= bLineDifThresh){
            lMotor.SetPercent(60);
            rMotor.SetPercent(-1 * 60);

        }
        else if (myAbsolute(rightOptoThresh-optoRight.Value())>= bLineDifThresh){
            lMotor.SetPercent(75);
            rMotor.SetPercent(-1 * 5);


    }
        else if(myAbsolute(leftOptoThresh-optoLeft.Value())>= bLineDifThresh){
            lMotor.SetPercent(5);
            rMotor.SetPercent(-1 * 75);

        }
        //logDataStuffs();
        dTime = TimeNow() - startTime;
    }
    rMotor.Stop();
    lMotor.Stop();

}







