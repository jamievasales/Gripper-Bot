#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <vector>
#include <random>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <fstream>
#include <string>
#include <QVector>
#include <QPushButton>
#include "mover.h"
#include <QInputDialog>
#include <QApplication>
#include <QMessageBox>
#include <QProcess>
#include <QLCDNumber>
#include <QElapsedTimer>
#include "applicationhandler.h"
#include <thread>
using namespace std;
using namespace GripperStructures;
class Solver{
protected:

private:
  ApplicationHandler* handler;
  bool finished = false;
  Mover timeToMoveBlocks;
  int holding;
  QFile layoutFile;
  ifstream solutionFile;
  int tempInt = 0;
  string word;
  void grabBlock(int row, int column);
  void placeBlock(int row, int column);
  vector<string> solutionVector;
  QVector<QPushButton*> buttonArray;
  QVector<PlatformStruct*> platformArray;
  qint64 thePid;
  bool isDone();
public:
  Solver(QVector<QPushButton*> &,QVector<PlatformStruct*>&,ApplicationHandler&);
    void createSolution();
  void createTextFile();
    void readSolution();
  void StartExecution(QLCDNumber*,QLCDNumber*);
  int getMovesNum();
  qint64 getPid();
  int goalPlatform=0;
};

Solver::Solver(QVector<QPushButton*> & ButtonArray,QVector<PlatformStruct*>& PlatformArray,ApplicationHandler &theHandler) {
    cout<<"test1";
    QDateTime cd = QDateTime::currentDateTime();
    qsrand(cd.toTime_t());
    buttonArray = ButtonArray;
    platformArray = PlatformArray;
    QInputDialog getGoal;
    handler = &theHandler;
    getGoal.setWindowTitle("Goal Platform");
    getGoal.setLabelText("Input Goal Platform 1-4");
    getGoal.setInputMode(QInputDialog::IntInput);
    getGoal.setIntRange(1,4);
    goalPlatform = QInputDialog::getInt(0, "Solve Platform",
                                        "Input Goal Platform 1-4, 5 for random",0,
                                        1,5,1);
    if(goalPlatform == 0) {
        goalPlatform = -1;
    }
    if(goalPlatform == 5)
        goalPlatform = (qrand() % 4) + 1;
    cout<<endl<<endl<<"The goal platform is "<<goalPlatform<<endl;
    handler->goalPlatform = goalPlatform;
}

int Solver::getMovesNum() {
    cout<<endl<<endl<<"We are upto "<<handler->movesNeeded<<" moves at ";
    if(solutionVector.empty())
        return 0;
    return solutionVector.size();
}

bool Solver::isDone() {
    return handler->completed;
}

void Solver::grabBlock(int row, int column) {
    if(handler->beatTheBot() == false) {
holding = platformArray[column]->platformStack.top();
handler->setHolding(buttonArray[holding]);
QApplication::processEvents();
platformArray[column]->platformStack.pop_back();
QThread::sleep(1.5);
    }
//timeToMoveBlocks.resetArm();
timeToMoveBlocks.PickUp(row,column);
}

void Solver::placeBlock(int row, int column) {
    if(handler->beatTheBot() == false) {
    cout<<endl<<row<<" "<<column;
    //cout<<endl<<row<< " wtf " << column<<endl;
  buttonArray[holding]->setGeometry(QRect(QPoint(handler->returnButtonX(column),handler->returnButtonY(row)),QSize(51, 41)));
  QApplication::processEvents();
   platformArray[column]->platformStack.push_back(holding);
    }
    timeToMoveBlocks.Place(row,column);

}

//While there are moves available pick up and place blocks
void Solver::StartExecution(QLCDNumber* theLCD, QLCDNumber* timer) {
    int counter = 0;
    cout<<endl<<solutionVector.size()<<"Solution vector size";
    timeToMoveBlocks.drop();
   // thread startCounting (&Solver::updateTime,this,timer);
  for(int x=0;x<solutionVector.size();x++) {
    //Minus 49 from the value as we're given the ascii value of the char
      grabBlock(((int)solutionVector[x][0])-49,((int)solutionVector[x][2])-49);
      placeBlock(((int)solutionVector[x][4])-49,((int)solutionVector[x][6])-49);
      counter++;
      theLCD->display(counter);
        QApplication::processEvents();
        QThread::sleep(1.5);
  }
  timeToMoveBlocks.resetArm();
  cout<<endl<<endl<<"Done"<<endl;
}

void Solver::createTextFile() {
    QFile theFile("layoutFile.inp");
    QTextStream stream(&theFile);
    cout << buttonArray.size();
    cout<<"test";
  theFile.open(QIODevice::WriteOnly | QIODevice::Text);
  string cellString[6];
  for (int banana=0;banana<3;banana++)
  stream << QString::fromStdString("%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
 stream << QString::fromStdString("%\n");
    for (int x=0;x<6;x++) {
        cout<<x<<endl;
      stream << QString::fromStdString("initCellHasBlock(");
             stream << QString::number(((277 - buttonArray[x]->y())/40)+1);
             stream <<  QString::fromStdString(",");
             stream << QString::number((buttonArray[x]->x() - 50)/190 + 1);
             stream << QString::fromStdString(",");
             stream << QString::number(x+1);
             stream << QString::fromStdString(").");
             stream << endl;
    }
    stream << QString::fromStdString("goalPlatform(");
    stream << QString::number(goalPlatform) << ").";
  theFile.close();
  cout<<"test";
}

void Solver::createSolution() {
  cout<< endl << "Creating Solution" << endl;
  //We really don't want to throw this as a background task as it may not complete in time
  QProcess myProcess;
  myProcess.setProgram("clingo");
  if(handler->movesNeeded<18)
  myProcess.setArguments(QStringList() << "blocks_ASP_prog.lp" << "layoutFile.inp" << "--time-limit=25"<<"-c"<<"n="+QString::number(handler->movesNeeded));
  else
       myProcess.setArguments(QStringList() << "blocks_ASP_prog.lp" << "layoutFile.inp" <<"-c"<<"n="+QString::number(handler->movesNeeded));
  myProcess.setStandardOutputFile("solution.txt");
  qint64 pid;
  /*Very important as this process separates itself from QT and needs to be completed
  before continuing on to reading the solution from clingo */
  //robotTimer.start();
  myProcess.startDetached(&thePid);
}

void Solver::readSolution() {
    cout<<"in here"<<endl;
  solutionFile.open("solution.txt");
  cout<<"here too"<<endl;
  string subString = "moveCellCell";
  vector<string> tempVec;
  if(!solutionFile) {
    cout<<endl<<"The solution file is corrupt or invalid"<<endl;
    exit(2);
  }
  while(solutionFile) {
    solutionFile >> word;
    if(word.find(subString)==0) {
      tempVec.push_back(word);
      solutionVector.push_back("");
    }
  }
    cout<<"I'm not in an infinite loop at least..."<<endl;
  for(int x=0;x<tempVec.size();x++) {
    int tempPos;
    string stringNum = "";
    stringNum.push_back(tempVec[x][13]);
    if(tempVec[x][14]!=',') {
      stringNum.push_back(tempVec[x][14]);
      // //pop the extra character for ease of reading later
      tempVec[x].erase(tempVec[x].begin(), tempVec[x].begin() + 16);
    }
    else
      tempVec[x].erase(tempVec[x].begin(), tempVec[x].begin() + 15);
    tempVec[x].erase(tempVec[x].begin() + (tempVec[x].size() -1));
    tempPos = atoi(stringNum.c_str());
    solutionVector[tempPos] = tempVec[x];
  }
  solutionFile.close();
}

qint64 Solver::getPid() {
    return thePid;
}
