#ifndef MENU_H
#define MENU_H



#include "../main.h"



class Operation
{
public:
    Operation();

    void setOperation( void (*fnPtr) () );
    void setOperation( Operation dOperation );

private:
    int dQueue;
    void (*fnPtr) ();
};



class OperationTracker
{
public:
    OperationTracker();
    void addOperation( Operation dOperation );
    //void onOperation( int opNum );
    Operation * tracker;

private:
    int trackerSize;
};









class movement
{
    public:
        movement();

        //dataType is set by the following four methods
        void setMovement(int dOperation, int dValue);
        void setMovement(int dOperation, float dValue);
        void setMovement(int dOperation, double dValue);
        void setMovement(int dOperation);

        void setMovement(movement otherMove);

        void setState(bool state);

        int getOperation();
        TypeEnum getDataType();
        int getIntValue();
        float getFloatValue();
        double getDoubleValue();
        //no get void type
        bool getState();

    private:
        int operation;
        TypeEnum dataType;
        int intValue;
        float floatValue;
        double doubleValue;
        //no voidValue
        bool movementState;
};




class MovementTracker
{
public:
    MovementTracker();
    void addMovement(movement dMove);
    //insertMovement?
    movement * tracker;

private:
    int trackerSize;
};






class option
{
    public:
        option();

        //setters
        //dataType is set automatically by the following 2 methods
        void setOption(int dLine, const char *dName);
        void setOption(int dLine, movement dOptionMovement);
        void setOption(option dOption);
        void setState(bool state);

        //getters
        TypeEnum getDataType();
        int getLine();
        const char * getName();
        movement getMovement();
        bool getState();

        void display();

    private:
        TypeEnum dataType;
        int line;
        const char * name;
        movement optionMovement;
        bool optionState;
};

class Menu
{
    public:
        Menu();
        void addOption(const char * dLine);
        void addOption(movement dMovement);

        int UserInterface();
        void drawCursor(int pixHeight);

        option * selection;

    private:
        int selectionSize;
};









extern OperationTracker opTracker;









#endif // MENU_H
