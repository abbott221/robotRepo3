


#include "main.h"




//lMotor: -power is forward
FEHMotor lMotor(FEHMotor::Motor0);
FEHMotor rMotor(FEHMotor::Motor1);

ButtonBoard buttons( FEHIO::Bank3 );
FEHEncoder  leftEncoder( FEHIO::P0_0);
FEHEncoder  rightEncoder( FEHIO::P0_1);

AnalogInputPin CDS(FEHIO::P0_7);

AnalogInputPin optoLeft(FEHIO::P2_0);
AnalogInputPin optoMid(FEHIO::P2_2);
AnalogInputPin optoRight(FEHIO::P2_4);

FEHWONKA TheRPS;
FEHServo lolServo(FEHServo::Servo0);
FEHBattery lolBattery (FEHIO::BATTERY_VOLTAGE);

//======================================




int leftPower = 80;
int rightPower = 78;

int tempLeftPower = 80;
int tempRightPower = 78;

int servoMin = 556;
int servoMax = 2500;

//for the encoders
float lowThresh = 0.388;
float highThresh = 1.547;

//for line following
float optoThresh = 2.0;
float bLineDifThresh = 1.0;
float yLineDifThresh = .4;
float leftOptoThresh = 0.0;
float rightOptoThresh = 0.0;
float midOptoThresh = 0.0;

bool configLightStart = true;
bool configCourseTimer = true;
bool configDelay = true;
bool configRPS = true;

double displayRate = 0.2;

double courseStartTime = 0.0;
int numOfDisplays = 0;

PMode currentPowerMode = STOP;
int leftPowerMode = leftPower;
int rightPowerMode = rightPower;

float decisionLight = 0.0;

int currentMove = 0;






void MainMenuCall();
void ConfigureMenuCall();

//void driveProcess();


//===================================================



//robot chet;
//RPScleaner cleaner;
MovementTracker mTracker;

OperationTracker opTracker;


//===================================================

//THESE ARE GLOBALS

// static/final menus

int mainChoice = -1;
Menu mainMenu;

int pageChoice = -1;
Menu pageMenu;

int configureChoice = -1;
Menu configureMenu;

int operationChoice = -1;
Menu operationMenu;


// more static/final menus for operations
int opSubChoice = -1;
Menu opSubTimeMenu;
Menu opSubEncMenu;
Menu opSubLineMenu;


// dynamic menus

int moveChoice = -1;
Menu moveMenu;






int main(void)
{
    opSubMenusSetup();


    int arbitraryInt = 0;
    int arbitraryFloat = 0.0;
    int arbitraryDouble = 0.0;


    //jeffID, function call
    opTracker.addOperation( 0, &DriveForTime );
    opSubTimeMenu.addOption("  Time: Straight");

    opTracker.addOperation(1, &TurnLeftForTime);
    opSubTimeMenu.addOption("  Time: Left");
    opTracker.addOperation(2, &TurnRightForTime);
    opSubTimeMenu.addOption("  Time: Right");
    opTracker.addOperation(3, &BackwardsForTime);
    opSubTimeMenu.addOption("  Time: Backwards");



    opTracker.addOperation(21, &BlackLineFollow);
    opSubLineMenu.addOption("  Line: Black");




    mTracker.addMovement(0, 3.0);

//    mTracker.addMovement(8, 120);
//    mTracker.addMovement(50, 1.50);
//    mTracker.addMovement(6, 4.697);
//    //mTracker.addMovement(202, 0.0);
//    mTracker.addMovement(4, 21.2);
//    //mTracker.addMovement(203, 0.0);
//    mTracker.addMovement(5, 4.00);
//    //chet.moreMoves[5].setMovement(12, 2.00);
//    mTracker.addMovement(21, 5.0);
//    mTracker.addMovement(8, 45);
//    mTracker.addMovement(8, 120);

//    mTracker.addMovement(6, 4.0);
//    mTracker.addMovement(50, -2.549);
//    mTracker.addMovement(6, 4.00);
//    mTracker.addMovement(51, 20.559);
//    mTracker.addMovement(64, 88.80);
//    mTracker.addMovement(64, 88.80);
//    mTracker.addMovement(51, 46.0);
//    mTracker.addMovement(64, 84.00);
//    mTracker.addMovement(64, 84.00);
//    mTracker.addMovement(4, 8.00);
//    mTracker.addMovement(5, 5.00);

//    mTracker.addMovement(6, 6.0);
//    mTracker.addMovement(64, 133.0);
//    mTracker.addMovement(64, 133.0);

//    mTracker.addMovement(8, 45);
//    mTracker.addMovement(8, 120);
//    mTracker.addMovement(7, 3.50);
//    mTracker.addMovement(5, 4.0);
//    mTracker.addMovement(50, -1.299);
//    mTracker.addMovement(5, 11.0);
//    mTracker.addMovement(64, 103.0);
//    mTracker.addMovement(64, 103.00);
//    mTracker.addMovement(4, 21.50);
//    mTracker.addMovement(6, 4.00);






    mainMenuSetup();

    pageMenuSetup();

    operationMenuSetup();





    for (int i = 0; i < 12; i++)
    {
        pageMenu.selection[i].setState(true);
    }









    while (true)
    {
        MainMenuCall();
    }

    return 0;
}



void MainMenuCall()
{


    mainChoice = mainMenu.UserInterface();




    //int typeChoice;
    //int moveChoice;

    int tempNum;
    int incrs[] = {25, 10, 1};





    //option 0: in case your finger slips
    if (mainChoice == 0)
    {
        //
    }



    //Option 1: Run
    else if (mainChoice == 1)
    {
        //driveProcess();
        theLoop();
    }



    //Option 2: Adjust (Set) Movement
    else if (mainChoice == 2)
    {

        //PAGEANDMOVEINTERFACE REPLACEMENT
        pageChoice = pageMenu.UserInterface();
        //(move selection)
        moveMenuSetup();
        moveChoice = moveMenu.UserInterface();
        moveChoice = moveChoice + (12 * pageChoice);



        //USER INTERFACE: MOVEMENT TYPE SELECTION
        operationChoice = operationMenu.UserInterface();

        //MOVE THIS TO OPSUBMENUSETUP LATER
        if (operationChoice == 0)
        {
            //frequently used ones
            //opSubChoice =
        }
        else if (operationChoice == 1)
        {
            opSubChoice = opSubTimeMenu.UserInterface();
        }
        else if (operationChoice == 2)
        {
            opSubChoice = opSubEncMenu.UserInterface();
        }
        else if (operationChoice == 3)
        {
            opSubChoice = opSubLineMenu.UserInterface();
        }











        //opSubMenusSetup();









        //Set the time of the adjusted move
        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );

        TypeEnum checkMe = findDataTypeOfJeffID(opSubChoice);











        //integer valued move
        if (checkMe == tInt)
        {
            int tempIntValue = mTracker.tracker[moveChoice].getIntValue();

            int incrs[] = {5, 3, 1};

            tempIntValue = SetInteger(tempIntValue, incrs, 3);

            //mTracker.tracker[moveChoice]
            //chet.moreMoves[moveChoice]
            mTracker.tracker[moveChoice].setMovement(opSubChoice, tempIntValue);
        }

        //double valued move
        else if (checkMe == tFloat)
        {
            float tempFloatValue = mTracker.tracker[opSubChoice].getFloatValue();

            float incrs[] = {1.0, 0.1, 0.01};

            tempFloatValue = SetFloat(tempFloatValue, incrs, 3);

            mTracker.tracker[moveChoice].setMovement(opSubChoice, tempFloatValue);
        }

        //double valued move
        else if (checkMe == tDouble)
        {
            double tempDoubleValue = mTracker.tracker[moveChoice].getDoubleValue();

            double incrs[] = {1.0, 0.1, 0.01};

            tempDoubleValue = SetDouble(tempDoubleValue, incrs, 3);

            mTracker.tracker[moveChoice].setMovement(opSubChoice, tempDoubleValue);
        }
        else if (checkMe == tVoid)
        {
            mTracker.tracker[moveChoice].setMovement(opSubChoice);
        }
    }



    //Option 3: Display movements
    else if (mainChoice == 3)
    {

        pageChoice = pageMenu.UserInterface();
        //(move selection)
        moveMenuSetup();
        moveChoice = moveMenu.UserInterface();
        moveChoice = moveChoice + (12 * pageChoice);
    }



    //Option 4: Insert movement
    else if (mainChoice == 4)
    {
        LCD.WriteLine("Enter num of move (0-142)");


        tempNum = SetInteger(0, incrs, 3);

        bool tempState;
        for (int i = 142; i >= tempNum; i--)
        {
            tempState = mTracker.tracker[i].getState();
            if (mTracker.tracker[i].getDataType() == tDouble)
            {
                mTracker.tracker[i+1].setMovement(mTracker.tracker[i].getOperation(), mTracker.tracker[i].getDoubleValue());
            }
            else
            {
                mTracker.tracker[i+1].setMovement(mTracker.tracker[i].getOperation(), mTracker.tracker[i].getIntValue());
            }
            mTracker.tracker[i+1].setState(tempState);
        }
        mTracker.tracker[tempNum].setMovement(0, 0.0);
        mTracker.tracker[tempNum].setState(false);
    }



    //Option 5: Turn on (Old Add) movement
    else if (mainChoice == 5)
    {
        //PAGEANDMOVEINTERFACE REPLACEMENT
        pageChoice = pageMenu.UserInterface();
        //(move selection)
        moveMenuSetup();
        moveChoice = moveMenu.UserInterface();
        moveChoice = moveChoice + (12 * pageChoice);





        mTracker.tracker[moveChoice].setState(true);
    }



    //Option 6: Turn off (Old Delete) Movement
    else if (mainChoice == 6)
    {
        //PAGEANDMOVEINTERFACE REPLACEMENT
        pageChoice = pageMenu.UserInterface();
        //(move selection)
        moveMenuSetup();
        moveChoice = moveMenu.UserInterface();
        moveChoice = moveChoice + (12 * pageChoice);






        mTracker.tracker[moveChoice].setState(false);
    }



    //Option 7: Add page
    else if (mainChoice == 7)
    {
        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );

        LCD.WriteLine("Select Page");

        //pageChoice = pageInterface();
        pageChoice = pageMenu.UserInterface();


        for (int i = 0; i < 12; i++)
        {
            mTracker.tracker[i + (12 * pageChoice)].setState(true);
        }

        pageMenu.selection[pageChoice].setState(true);
    }



    //Option 8: Delete Page
    else if (mainChoice == 8)
    {
        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );

        LCD.WriteLine("Select Page");

        //pageChoice = pageInterface();
        pageChoice = pageMenu.UserInterface();


        for (int i = 0; i < 12; i++)
        {
            mTracker.tracker[i + (12 * pageChoice)].setState(false);
        }

        pageMenu.selection[pageChoice].setState(false);
    }



    //Option 9: Calibrate/Configure
    else if (mainChoice == 9)
    {
        ConfigureMenuCall();
    }

}



void ConfigureMenuCall()
{
    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );

    //LCD.WriteLine("Cunfiguer Yor Stuf Heer");

    LCD.Write("Voltage: ");
    LCD.WriteLine(lolBattery.Voltage());

    configureMenu.addOption("  Calibrate Power");

    configureMenu.addOption("  Calibrate Servo");

    configureMenu.addOption("  Start with Light");
    configureMenu.selection[2].setState(configLightStart);

    configureMenu.addOption("  Course Timer");
    configureMenu.selection[3].setState(configCourseTimer);

    configureMenu.addOption("  2 sec delay");
    configureMenu.selection[4].setState(configDelay);

    configureMenu.addOption("  Use RPS");
    configureMenu.selection[5].setState(configRPS);

    configureMenu.addOption("  Read mid-opto value");

    configureMenu.addOption("  Read CDS values");

    configureMenu.addOption("  Read RPS values");

    //configureSelect[9].setOption(11, "  Data Spew Modulus");
    configureMenu.addOption("  Time between displays");





    configureChoice = configureMenu.UserInterface();



    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );

    //calibrate motor
    if (configureChoice == 0)
    {
        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );

        LCD.WriteLine("Setting Left Motor");

        int tempPower = leftPower;
        int incrs[] = {5, 3, 1};
        tempPower = SetInteger(tempPower, incrs, 3);

        leftPower = tempPower;

        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );
        LCD.WriteLine("Setting Right Motor");


        tempPower = rightPower;
        //int incrs[] = {5, 3, 1};
        tempPower = SetInteger(tempPower, incrs, 3);

        rightPower = tempPower;
    }
    //calibrate servo
    else if (configureChoice == 1)
    {
        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );

        LCD.WriteLine("Commence the calibration?");

        lolServo.Calibrate();

        //INPUT THE NUMBERS


        LCD.WriteLine("Setting Min");

        int tempTicks = 0;
        int incrs[] = {500, 100, 10, 1};
        tempTicks = SetInteger(tempTicks, incrs, 4);

        servoMin = tempTicks;

        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );
        LCD.WriteLine("Setting Max");


        tempTicks = 0;
        //int incrs[] = {5, 3, 1};
        tempTicks = SetInteger(tempTicks, incrs, 4);

        servoMax = tempTicks;



    }

    else if (configureChoice == 2)
    {
        if (configLightStart == true)
        {
            configLightStart = false;
        }
        else
        {
            configLightStart = true;
        }
    }
    else if (configureChoice == 3)
    {
        if (configCourseTimer == true)
        {
            configCourseTimer = false;
        }
        else
        {
            configCourseTimer = true;
        }
    }
    else if (configureChoice == 4)
    {
        if (configDelay == true)
        {
            configDelay = false;
        }
        else
        {
            configDelay = true;
        }
    }
    else if (configureChoice == 5)
    {
        if (configRPS == true)
        {
            configRPS = false;
        }
        else
        {
            configRPS = true;
        }
    }

    //mid-opto values
    else if (configureChoice == 6)
    {
        while( buttons.MiddlePressed() )
        {
            //this menu is entered by pressing the middle button
        }
        while( !buttons.MiddlePressed() )
        {
            LCD.Write(optoLeft.Value());
            LCD.Write(" ");
            LCD.Write(optoMid.Value());
            LCD.Write(" ");
            LCD.WriteLine(optoRight.Value());

            Sleep(0.10);
        }
        while( buttons.MiddlePressed() )
        {
            //nothing
        }
    }

    //CDS values
    else if (configureChoice == 7)
    {
        while( buttons.MiddlePressed() )
        {
            //this menu is entered by pressing the middle button
        }
        while( !buttons.MiddlePressed() )
        {
            LCD.WriteLine(CDS.Value());
            Sleep(.10);
        }
        while( buttons.MiddlePressed() )
        {
            //nothing
        }
    }

    //RPS values
    else if (configureChoice == 8)
    {
        while( buttons.MiddlePressed() )
        {
            //this menu is entered by pressing the middle button
        }
        TheRPS.InitializeMenu();
        TheRPS.Enable();
        while( !buttons.MiddlePressed() )
        {
            LCD.Write(TheRPS.Heading());
            LCD.Write(" ");
            LCD.Write(TheRPS.X());
            LCD.Write(" ");
            LCD.WriteLine(TheRPS.Y());
            Sleep(.10);
        }
        TheRPS.Disable();
        while( buttons.MiddlePressed() )
        {
            //nothing
        }
    }
    else if (configureChoice == 9)
    {
        LCD.WriteLine("Setting display rate");

        double tempRate = displayRate;
        double incrs[] = {1.0, 0.1, 0.01};
        tempRate = SetDouble(tempRate, incrs, 3);

        //dataSpew = tempSpew;
        displayRate = tempRate;
    }
}










