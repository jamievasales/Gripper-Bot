#include "applicationhandler.h"
#include <QMessageBox>
#include <QString>
using namespace GripperStructures;
ApplicationHandler::ApplicationHandler()
{

}

void ApplicationHandler::RandomiseBoard() {

}

int ApplicationHandler::returnButtonX(int row) {
        return 50 + (190*row); //Column
}

int ApplicationHandler::returnButtonY(int col) {
    return  277 - (40*col); //Height
}

void ApplicationHandler::setAvailable(QPushButton * theButton) {
    theButton->blockSignals(false);
    theButton->setGeometry(QRect(QPoint(115 + (65 * (theButton->text().toInt())-1), 405),QSize(51, 41)));
}

void ApplicationHandler::setHeld(QPushButton * theButton, QLabel* holdingLabel) {
    theButton->blockSignals(true);
    theButton->setGeometry(QRect(QPoint(415, 30),QSize(51, 41)));
    holdingLabel->setVisible(true);
    holding = theButton->text().toInt()-1;
    popMode=false;
}

bool ApplicationHandler::platformMode() {
    return popMode;
}

void ApplicationHandler::setHolding(QPushButton * theButton) {
    theButton->blockSignals(true);
    theButton->setGeometry(QRect(QPoint(415, 30),QSize(51, 41)));
}

bool ApplicationHandler::beatTheBot() {
    return VersingRobot;
}

bool ApplicationHandler::checkValidity(PlatformStruct* plat) {
    if(holding < plat->platformStack.top() || plat->platformStack.size()==0)
        return true;
    else
        return false;

}

void ApplicationHandler::invalidPlacement(PlatformStruct * plat) {
    QMessageBox msgBox;
    msgBox.setText("Warning:");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setWindowTitle("Invalid placement: " + QString::number(holding + 1) + " is not less than " + QString::number(plat->platformStack.top()));
    msgBox.setInformativeText("Please place " + QString::number(holding + 1) + " on a larger block or drop the block");
    msgBox.exec();
}

void ApplicationHandler::alreadySolved(int thePlatform) {
    QMessageBox msgBox;
    msgBox.setText("Warning:");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setWindowTitle("Invalid Placement: Already Solved");
    msgBox.setInformativeText("The puzzle is already solved on platform " + QString::number(thePlatform));
    msgBox.exec();
}

