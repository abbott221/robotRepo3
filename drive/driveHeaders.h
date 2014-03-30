#ifndef DRIVEHEADERS_H
#define DRIVEHEADERS_H


#include "../main.h"


//void tracker();

void SetPowerStraight();
void SetPowerLeft();
void SetPowerRight();
void SetPowerBackwards();
void SetPowerStop();




void DriveForTime(float time);

void TurnLeftForTime(float time);

void TurnRightForTime(float time);

void BackwardsForTime(float time);

void Pause(float time);











//METHOD 4
//goes "straight" for specified time
void EncForward(double distance);

//METHOD 5
void EncLeft(double distance);

//METHOD 6
void EncRight(double distance);

//METHOD 7
void EncBackward(double distance);




//METHOD 12
void ChangeOptoThreshold(double optoThresh);

//METHOD 9
void FollowBlackLine(double goThisLong);

//METHOD 10
void FollowLightLine(double goThisLong);

//METHOD 16
void unFollowBlackLine(double goThisLong);

//METHOD 17
void unFollowLightLine(double goThisLong);





//METHOD 8
void SetServoDegree(int degrees);

//METHOD 13
void DisplayLightValue();

//METHOD 14
void FlyOverLightValue(double time);



//METHOD 19
void LightDecisionTurn(double distance);

//METHOD 20
void GetOptoThresh();

//METHOD 21
void BlackLineFollow(double time);

//METHOD 22
void YellowLineFollow(double time);



//METHOD 30
void SetCustomAction(int action);


/*
//METHOD 31
void ChangeTolerance(double value);
/**/







//METHOD 50
void MoveToRealX(double givenX);

//METHOD 51
void MoveToRealY(double givenY);


//METHOD 52
void CheckRealX(double givenX);

//METHOD 53
void CheckRealY(double givenY);






//METHOD 60
void TurnLeftPast180();

//METHOD 61
void TurnRightPast0();

//METHOD 62
void TurnLeftToAngle(double angle);

//METHOD 63
void TurnRightToAngle(double angle);

//METHOD 64
void UnsafeTurnToAngle(double angle);





//METHOD 80
void RelativeTurnLeft(double angle);

//METHOD 81
void RelativeTurnRight(double angle);




void SlowEncLeft(double distance, int lowPower);
void SlowEncRight(double distance, int lowPower);













void theLoop();








#endif // DRIVEHEADERS_H
