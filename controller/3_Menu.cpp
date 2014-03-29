#include "controller.h"


//************************************************
//*                                              *
//*           BEGIN OPTION CLASS                 *
//*                                              *
//************************************************

//"CONSTRUCTOR" METHODS HERE

option::option()
{
    dataType = tString;
    line = 0;
    name = "";
    optionMovement;
    optionState = false;
}





//"SETTER" METHODS HERE

void option::setOption(int dLine, const char * dName)
{
    dataType = tString;
    line = dLine;
    name = dName;
}

void option::setOption(int dLine, movement dOptionMove)
{
    dataType = dOptionMove.getDataType();
    line = dLine;
    optionMovement.setMovement(dOptionMove);
}

void option::setOption(option dOption)
{
    dataType = dOption.getDataType();
    line = dOption.getLine();
    name = dOption.getName();
    optionMovement = dOption.getMovement();
    optionState = dOption.getState();
}

void option::setState(bool dState)
{
    if (dState == true)
    {
        optionState = true;
    }
    else
    {
        optionState = false;
    }
}





//"GETTER" METHODS HERE

TypeEnum option::getDataType()
{
    return dataType;
}

int option::getLine()
{
    return line;
}

const char * option::getName()
{
    return name;
}

movement option::getMovement()
{
    return optionMovement;
}

bool option::getState()
{
    return optionState;
}





//OTHER METHODS HERE

void option::display()
{
    TypeEnum tempDataType = optionMovement.getDataType();


    if (dataType == tString)
    {
        LCD.WriteLine(name);
    }
    else if (tempDataType == tInt)
    {
        LCD.Write("  Type: ");
        LCD.Write(optionMovement.getOperation());
        LCD.Write("  Int: ");
        LCD.WriteLine(optionMovement.getIntValue());
    }
    else if (tempDataType == tFloat)
    {
        LCD.Write("  Type: ");
        LCD.Write(optionMovement.getOperation());
        LCD.Write("  Flo: ");
        LCD.WriteLine(optionMovement.getFloatValue());
    }
    else if (tempDataType == tDouble)
    {
        LCD.Write("  Type: ");
        LCD.Write(optionMovement.getOperation());
        LCD.Write("  Dou: ");
        LCD.WriteLine(optionMovement.getDoubleValue());
    }
    else if (tempDataType == tVoid)
    {
        LCD.Write("  Type: ");
        LCD.Write(optionMovement.getOperation());
        LCD.Write("  Void");
    }

}


//************************************************
//*                                              *
//*            BEGIN MENU CLASS                  *
//*                                              *
//************************************************



Menu::Menu()
{
    selectionSize = 0;
    selection;
}


//an attempt at dynamic allocation
void Menu::addOption(const char *dLine)
{
    //a temporary holder of the data
    option tempSelection[selectionSize + 1];


    for (int i = 0; i < selectionSize; i++)
    {
        tempSelection[i].setOption(selection[i]);
    }

    //add the new option
    tempSelection[selectionSize].setOption( (selectionSize+1), dLine);
    selectionSize += 1;


    //resize selection
    selection = new option[selectionSize];

    //copy the data back into selection
    for (int i = 0; i < selectionSize; i++)
    {
        selection[i].setOption(tempSelection[i]);
    }
}

void Menu::addOption(movement dMovement)
{
    //a temporary holder of the data
    option tempSelection[selectionSize + 1];


    for (int i = 0; i < selectionSize; i++)
    {
        tempSelection[i].setOption(selection[i]);
    }

    //add the new option
    tempSelection[selectionSize].setOption( (selectionSize+1), dMovement);
    selectionSize += 1;


    //resize selection
    selection = new option[selectionSize];

    //copy the data back into selection
    for (int i = 0; i < selectionSize; i++)
    {
        selection[i].setOption(tempSelection[i]);
    }
}



//a grossly implemented attempt at a GUI
int Menu::UserInterface()
{
    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );

    ButtonBoard buttons( FEHIO::Bank3 );


    int height[selectionSize];

    LCD.SetFontColor( FEHLCD::White );

    for (int i = 0; i < selectionSize; i++)
    {
        selection[i].display();
        height[i] = 6 + ( (selection[i].getLine() - 1) * 17);

        if (selection[i].getState() == true)
        {
            //DISPLAY THE LITTLE DOT
            LCD.SetFontColor(FEHLCD::Green);
            //x,y,width,height
            LCD.FillRectangle(12, (height[i]+2),5,5);
            LCD.SetFontColor( FEHLCD::White );
        }
    }



    int minHeight = 0;
    int maxHeight = selectionSize - 1;

    int current = 0;
    int previous = 0;


    LCD.SetFontColor( FEHLCD::Red );
    drawCursor(height[current]);


    bool noSelection = true;

    while( noSelection )
    {
        previous = current;

        if( buttons.LeftPressed() )
        {
            while( buttons.LeftPressed() )
            {
                //nothing
            }
            //Do Stuff here

            if (current == minHeight)
            {
                current = maxHeight;
            }
            else
            {
                current--;
            }
        }
        else if( buttons.RightPressed() )
        {
            while( buttons.RightPressed() )
            {
                //nothing
            }
            //Do Stuff here

            if (current == maxHeight)
            {
                current = minHeight;
            }
            else
            {
                current++;
            }
        }
        else if( buttons.MiddlePressed() )
        {
            while( buttons.MiddlePressed() )
            {
                //nothing
            }

            //Exit the loop
            noSelection = false;
        }

        if (current != previous)
        {
            //cover up previous cursor
            LCD.SetFontColor( FEHLCD::Black );
            drawCursor(height[previous]);

            //draw new cursor
            LCD.SetFontColor( FEHLCD::Red );
            drawCursor(height[current]);
        }

        Sleep(.10);
    }

    LCD.SetFontColor( FEHLCD::White );
    return current;
}

//draw the cursor
void Menu::drawCursor(int pixHeight)
{
    LCD.DrawRectangle(1,(pixHeight - 5), 310, 17);
}








