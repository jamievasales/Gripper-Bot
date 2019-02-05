#ifndef APPLICATIONHANDLER_H
#define APPLICATIONHANDLER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <vector>
#include <QPushButton>
#include<QString>
#include <QLabel>
#include "gripperbotstructures.h"

using namespace GripperStructures;

class ApplicationHandler
{
private:
public:
    bool popMode = false;
    bool completed = false;
    bool VersingRobot = false;
    bool finishedSetup = false;
    ApplicationHandler();
    void RandomiseBoard();
    int returnButtonY(int row);
    int returnButtonX(int col);
    void setAvailable(QPushButton*);
    void setHolding(QPushButton*);
    int holding = -1;
    void setHeld(QPushButton*,QLabel*);
    bool platformMode();
    bool beatTheBot();
    bool checkValidity(PlatformStruct*);
    int goalPlatform=-1;
    void invalidPlacement(PlatformStruct*);
    int movesNeeded = 1;
    int timeAllowed = 3;
    void alreadySolved(int);
signals:

public slots:
};

#endif // APPLICATIONHANDLER_H
