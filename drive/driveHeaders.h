#ifndef DRIVEHEADERS_H
#define DRIVEHEADERS_H


#include "../main.h"


void tracker();

void SetPowerStraight();
void SetPowerLeft();
void SetPowerRight();
void SetPowerBackwards();
void SetPowerStop();




void DriveForTime();

void TurnLeftForTime(float time);

void TurnRightForTime(float time);

void BackwardsForTime(float time);

void Pause(float time);








#endif // DRIVEHEADERS_H
