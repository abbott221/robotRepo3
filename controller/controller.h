#ifndef MENU_H
#define MENU_H



#include "../main.h"



class Operation
{
public:
    Operation();

    void setOperation( void (*dVoidPtr) () );
    void setOperation( int callID, void (*dVoidPtr) () );

    void setOperation( void (*dIntPtr) (int value) );
    void setOperation( int callID, void (*dIntPtr) (int value) );
    void setOperation( void (*dFloatPtr) (float value) );
    void setOperation( int callID, void (*dFloatPtr) (float value) );
    void setOperation( void (*dDoublePtr) (double value) );
    void setOperation( int callID, void (*dDoublePtr) (double value) );

    void setOperation( Operation dOperation );
    void setOperation( int callID, Operation dOperation );

    void setJeffID(int jeff);

    TypeEnum getDataType();
    int getJeffID();

    //void (*) () getVoidType();



    //THESE ARE VARIABLES CALLED FUNCTION POINTERS
    void (*voidPtr) ();
    void (*intPtr) (int intValue);
    void (*floatPtr) (float floatValue);
    void (*doublePtr) (double doubleValue);

private:
    int jeffID;

    TypeEnum dataType;
};



class OperationTracker
{
public:
    OperationTracker();
    void addOperation( Operation dOperation );

    void addOperation( int callID, void (*fnPtr) () );

    void addOperation( int callID, void (*fnPtr) (int value) );
    void addOperation( int callID, void (*fnPtr) (float value) );
    void addOperation( int callID, void (*fnPtr) (double value) );


    int getTrackerSize();

    //int Operation::getOperation();

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
        int getDriveProcessTranslationID();

    private:
        int operation;

        int driveProcessTranslationID;

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

    //check these addMovement() methods work...
    int addMovement(int dOp, int value);
    int addMovement(int dOp, float value);
    int addMovement(int dOp, double value);
    int addMovement(int dOp); //void

    int getTrackerSize();
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

        //void setOption(const char *dName, int jeff);

        void setJeffID(int jeff);

        void setOption(int dLine, movement dOptionMovement);
        void setOption(option dOption);
        void setState(bool state);

        //getters
        int getJeffID();

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

        int optionJeffID;
};

class Menu
{
    public:
        Menu();
        void addOption(const char * dLine);
        void addOption(const char * dLine, int jeff);
        void addOption(movement dMovement);

        void setSubOpMenu(bool isSubOpMenu);

        int UserInterface();
        void drawCursor(int pixHeight);

        option * selection;

    private:
        int selectionSize;

        bool subOpMenu;
};








extern MovementTracker mTracker;

extern OperationTracker opTracker;


extern int mainChoice;
extern Menu mainMenu;

extern int pageChoice;
extern Menu pageMenu;

extern int configureChoice;
extern Menu configureMenu;

extern int operationChoice;
extern Menu operationMenu;


extern int opSubChoice;
extern Menu opSubTimeMenu;
extern Menu opSubEncMenu;
extern Menu opSubLineMenu;



extern int moveChoice;
extern Menu moveMenu;












#endif // MENU_H
