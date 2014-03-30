

#include "menuSetup.h"




//dynamic menus?











void moveMenuSetup()
{
    //pageChoice IS A GLOBAL
    //no need to pass it in as a parameter

    //WILL THIS WORK???
    //moveMenu = new Menu;



    movement tempMoves[12];


    for (int i = 0; i < 12; i++)
    {
        int tempCurrentMove = i + (12 * pageChoice);

        tempMoves[i].setMovement(mTracker.tracker[tempCurrentMove]);

        moveMenu.addOption(tempMoves[i]);
    }

    //this next line is left to main.cpp
    //moveChoice = moveMenu.UserInterface();

}




void opSubMenusSetup()
{
    //opSubTimeMenu = new Menu;
    opSubTimeMenu.setSubOpMenu(true);
    //opSubEncMenu = new Menu;
    opSubEncMenu.setSubOpMenu(true);
    //opSubLineMenu = new Menu;
    opSubLineMenu.setSubOpMenu(true);

}










