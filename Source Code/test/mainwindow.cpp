#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QVector>
#include <QtWidgets>
#include <QMessageBox>
#include <cstdlib>
#include "puzzleboard.h"
#include "solver.h"
#include <QMovie>
#include <string>
#include <thread>
#include <future>
#include <chrono>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gif->setVisible(false);
//    theButton = ui->pushButton;
//    topButton = ui->topButton;
//    topButton->setEnabled(false);
    //connect(theButton,SIGNAL(pressed()),this,SLOT(handleClick()));
    // m_button = new QPushButton("My Button", this);

     //16 for y 190 for x
     // m_button->setGeometry(QRect(QPoint(240, 216),QSize(51, 38)));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(dropItLikeItsHot()));
    connect(ui->emergencyStop,SIGNAL(clicked()),this,SLOT(emergencyStopProgram()));
    connect(ui->randomiseBlocks,SIGNAL(clicked()),this,SLOT(randomise()));
    connect(ui->resetButton,SIGNAL(clicked()),this,SLOT(resetBlocks()));
    connect(ui->startSolution,SIGNAL(clicked()),this,SLOT(startExecution()));
   // connect(ui->checkBox,SIGNAL(clicked()),this,SLOT(PlayAgainstRobotToggle()));
    ui->pushButton->setVisible(false);
    ui->startSolution->setVisible(false);
    ui->timer->setVisible(false);
    ui->lcdNumber->setVisible(false);
    ui->label_3->setVisible(false);
    ui->humanLCD->setVisible(false);
    ui->humanTimer->setVisible(false);
    ui->label_4->setVisible(false);
    ui->solvePlatform->setVisible(false);
    ui->movesNeeded->setVisible(false);
    ui->robotTime->setVisible(false);
for(int x = 0;x<4;x++) {
    platformArray.push_back(new PlatformStruct);
    platformArray[x]->thePlatform = new QPushButton(this);
    platformArray[x]->thePlatform->setGeometry(QRect(QPoint(10+(190*x),317),QSize(131, 31)));
    platformArray[x]->thePlatform->setText("Platform " + QString::number(x+1));
    platformArray[x]->platformNumber = x;
    connect(platformArray[x]->thePlatform,SIGNAL(clicked()),this,SLOT(platformClick()));
}
    
    for(int x = 0; x<6;x++) {
        buttonArray.push_back(new QPushButton(this));
        buttonArray[x]->setText(QString::number(x+1));
        handler.setAvailable(buttonArray[x]);
        connect(buttonArray[x],SIGNAL(clicked()),this,SLOT(buttonArrayClicked()));
         }
    ui->label_2->setVisible(false);
  //  qDebug ("%d %d",theButton->x(),theButton->y());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideIt()
{
    this->hide();
}

void MainWindow::handleClick() {
//    theButton->setText("1");
//    theButton->setDisabled(true);
//    topButton->setEnabled(true);
}

void MainWindow::buttonArrayClicked() {
    QPushButton* itsTheButton = qobject_cast<QPushButton*>(sender());
//    int toIncrement = itsTheButton->text().toInt();
//    toIncrement++;
    if(handler.holding == -1) {
    handler.setHeld(itsTheButton,ui->label_2);
    if(!handler.beatTheBot()||availableBlocks>0)
            ui->pushButton->setVisible(true);
    }
//  itsTheButton->setText(QString::number(toIncrement));
//       qDebug() << itsTheButton->text().toInt();
    //QProcess::startDetached(QApplication::applicationFilePath());
    //exit(12);
}

void MainWindow::platformClick() {
    QPushButton* itsTheButton = qobject_cast<QPushButton*>(sender());
    int x = itsTheButton->text().right(1).toInt()-1;
    PlatformStruct* plat = platformArray[x];
    int platform = plat->platformNumber;
    std::cout<<std::endl<<"Holding "<<handler.holding;
if(handler.platformMode() == false && handler.holding > -1) {
    std::cout<<std::endl<<"Ready to add"<<std::endl;
    if(handler.checkValidity(plat)) {
        plat->platformStack.push_back(handler.holding);
       buttonArray[plat->platformStack.top()]->setGeometry(QRect(QPoint(handler.returnButtonX(platform),handler.returnButtonY(plat->platformStack.size()-1)),QSize(51, 41)));
        handler.holding = -1;
        handler.popMode = true;
        ui->label_2->setVisible(false);
        ui->pushButton->setVisible(false);
        availableBlocks--;
        std::cout<<std::endl<<"Added"<<std::endl;
    }
    else {
        handler.invalidPlacement(plat);
    }
}
else if(plat->platformStack.size()>0){
    //make top block a stack
handler.setAvailable(buttonArray[plat->platformStack.top()]);
plat->platformStack.pop();
availableBlocks++;
}
std::cout<<std::endl<<plat->platformStack.size()<<"   "<<plat->platformStack.top()<<std::endl;

checkReadyToSolveOrComplete();
}

void MainWindow::challengePlatformClick() {
    QPushButton* itsTheButton = qobject_cast<QPushButton*>(sender());
    int x = itsTheButton->text().right(1).toInt()-1;
    PlatformStruct* plat = platformArray[x];
    int platform = plat->platformNumber;
    std::cout<<std::endl<<"Holding "<<handler.holding;
if(handler.holding > -1) {
    std::cout<<std::endl<<"Ready to add "<<handler.holding<<std::endl;
    if(handler.checkValidity(plat)) {
        plat->platformStack.push_back(handler.holding);

       buttonArray[handler.holding]->setGeometry(QRect(QPoint(handler.returnButtonX(platform),handler.returnButtonY(plat->platformStack.size()-1)),QSize(51, 41)));
        handler.holding = -1;
        handler.popMode = true;
        ui->label_2->setVisible(false);
        ui->pushButton->setVisible(false);
        std::cout<<std::endl<<"Added"<<std::endl;
        humanMoves++;
        ui->humanLCD->display(humanMoves);
    }
    else {
        handler.invalidPlacement(plat);
    }
}
else if(plat->platformStack.size()>0&& handler.holding == -1){
    //make top block a stack
    handler.holding = platformArray[platform]->platformStack.top();
     std::cout<<std::endl<<"I am currently holding "<<handler.holding<<std::endl;
handler.setHolding(buttonArray[plat->platformStack.top()]);
plat->platformStack.pop();
}
std::cout<<std::endl<<plat->platformStack.size()<<"   "<<plat->platformStack.top()<<std::endl;

checkReadyToSolveOrComplete();
}

void MainWindow::dropItLikeItsHot() {
    handler.setAvailable(buttonArray[handler.holding]);
    handler.holding = -1;
    handler.popMode = true;
    ui->label_2->setVisible(false);
    ui->pushButton->setVisible(false);
}

void MainWindow::randomise() {
resetBlocks();
    PuzzleBoard thePuzzle(buttonArray,platformArray);
    availableBlocks = 0;
    checkReadyToSolveOrComplete();
}

void MainWindow::resetBlocks() {
std::cout<<"Works";
for(int x = 0;x<4;x++) {
    platformArray[x]->platformStack.erase( platformArray[x]->platformStack.begin(), platformArray[x]->platformStack.end());
}
for(int x = 0; x<6;x++) {
    handler.setAvailable(buttonArray[x]);
    connect(buttonArray[x],SIGNAL(clicked()),this,SLOT(buttonArrayClicked()));
     }
handler.holding = -1;
handler.popMode = true;
ui->label_2->setVisible(false);
ui->pushButton->setVisible(false);
availableBlocks = 6;
checkReadyToSolveOrComplete();
}

void MainWindow::checkReadyToSolveOrComplete() {
    if(handler.beatTheBot()) {
        if(platformArray[handler.goalPlatform - 1]->platformStack.size()==6) {
    //Assign in application handler later and add to solver while loop so it ends and resets
            handler.completed = true;
            for(int x = 0;x<4;x++) {
                platformArray[x]->thePlatform->blockSignals(true);
            }
        }
    }
    else {
    if(availableBlocks==0) {
        ui->label->setVisible(false);
        ui->startSolution->setVisible(true);
    }
    else {
        ui->label->setVisible(true);
        ui->startSolution->setVisible(false);
    }
    }
}

void MainWindow::startExecution() {
    std::shared_ptr<Solver> theSolver(new Solver(buttonArray,platformArray,handler));

if(theSolver.get()->goalPlatform > 0) {
    if(platformArray[theSolver.get()->goalPlatform -1]->platformStack.size()!=6) {
    theSolver.get()->createTextFile();
    ui->solvePlatform->setVisible(true);
    ui->solvePlatform->setText("Solve Platform: " + QString::number(handler.goalPlatform));
    ui->checkBox->setVisible(false);
    //Avoids issues arising from setting on change
    if(ui->checkBox->checkState() == 2)
    handler.VersingRobot = true;
    else
        handler.VersingRobot = false;

    //set the goal platform for future reference
    handler.goalPlatform = theSolver.get()->goalPlatform;
    if(handler.beatTheBot()) {
        ui->humanLCD->setVisible(true);
        ui->humanTimer->setVisible(true);
        ui->label_4->setVisible(true);
        humanTimer.start();
        for(int x = 0;x<4;x++) {
            //swap the old signal for the new signal
            platformArray[x]->thePlatform->disconnect();
            connect(platformArray[x]->thePlatform,SIGNAL(clicked()),this,SLOT(challengePlatformClick()));
        }
    }
    else
    for(int x = 0;x<4;x++) {
        platformArray[x]->thePlatform->blockSignals(true);
    }
    ui->resetButton->setVisible(false);
    ui->startSolution->setVisible(false);
    ui->randomiseBlocks->setVisible(false);
    ui->checkBox->setDisabled(true);
//    platformArray[3]->platformStack.pop_back();
//    std::cout<<std::endl<<std::endl<<"Block on top "<<platformArray[3]->platformStack.top();
    QElapsedTimer robotTimer;
    ui->lcdNumber->setVisible(true);
    ui->label_3->setVisible(true);
    //push_front to guarantee that te clingo pid is at position 0
    robotTimer.start();
    theSolver.get()->createSolution();
    thepid.push_front(theSolver.get()->getPid());
    QMovie* clingoLoading = new QMovie("6.gif");
    ui->gif->setMovie(clingoLoading);
    ui->gif->setVisible(true);
    clingoLoading->start();
    ui->timer->setVisible(true);
    while(theSolver.get()->getMovesNum()==0) {
        std::cout<<returnTime(robotTimer).toStdString()<<std::endl;
      while(kill(thepid[0], 0)>-1) {
          //Keeps it all active whilst our detached process works away
           ui->timer->display(returnTime(robotTimer));
           if(!handler.completed) {
               ui->humanTimer->display(returnTime(humanTimer));
           }
          QCoreApplication::processEvents();
      }
            theSolver.get()->readSolution();
            if(theSolver.get()->getMovesNum()>0) {
                std::cout<<"DONEEEEE";
            ui->robotTime->setVisible(true);
            ui->robotTime->setText("The robot took: "+returnTime(robotTimer));
            }
            else {
                handler.movesNeeded++;
                theSolver.get()->createSolution();
                thepid.push_front(theSolver.get()->getPid());
            }
    }
      ui->gif->setVisible(false);
      ui->movesNeeded->setVisible(true);
      ui->movesNeeded->setText("Moves needed for solution: " + QString::number(theSolver.get()->getMovesNum()));
      ui->lcdNumber->setPalette(Qt::red);
     // std::thread t(&Solver::StartExecution,theSolver,ui->lcdNumber,ui->timer);
      std::future<void> fut = std::async(std::launch::async,&Solver::StartExecution,theSolver,ui->lcdNumber,ui->timer);
      //theSovler.StartExecution(ui->lcdNumber,ui->timer);
     std::cout<<std::endl<<thepid[0]<<std::endl;
    std::cout<<std::endl<<"Here"<<std::endl;
    std::cout<<std::endl<<"The file should have been created"<<std::endl;
    std::future_status status = fut.wait_for(chrono::seconds(1));
   // t.detach();
     std::chrono::milliseconds span (10);
    while(fut.wait_for(span)==std::future_status::timeout) {
        if(!handler.completed&&handler.beatTheBot()) {
            ui->humanTimer->display(returnTime(humanTimer));
        }
        //Freezes the time when the AI finishes - not needed as label is used
//        else
         ui->timer->display(returnTime(robotTimer));
        QCoreApplication::processEvents();
    }
    fut.get();
   // t.join();
    }
    else
        handler.alreadySolved(theSolver.get()->goalPlatform);
}
}

void MainWindow::closeEvent(QCloseEvent* event) {
    for(int x=0;x<thepid.size();x++)
    std::cout<<std::endl<<thepid[x]<<std::endl;
    //Kills clingo to avoid a zombie
    for(int x=0;x<thepid.size();x++)
    kill(thepid[x],SIGTERM);
    //Properly ends roslaunch and all dependencies
    string s = "pkill -f roslaunch;";
    system(s.c_str());
    exit(0);
}

void MainWindow::emergencyStopProgram() {
    for(int x=0;x<thepid.size();x++)
    std::cout<<std::endl<<thepid[x]<<std::endl;
    //Kills clingo to avoid a zombie
    for(int x=0;x<thepid.size();x++)
    kill(thepid[x],SIGTERM);
    //Properly ends roslaunch and all dependencies
    string s = "pkill -f roslaunch;";
    system(s.c_str());
    exit(0);
}

void MainWindow::PlayAgainstRobotToggle() {
    handler.VersingRobot ^= 1;
    std::cout<<handler.VersingRobot<<std::endl;
}

QString MainWindow::returnTime(QElapsedTimer RoboCop) {
    int msInt = (RoboCop.elapsed() % 1000)/10;
    QString ms;
    if(msInt < 10)
        ms = "0" + QString::number(msInt);
    else
         ms = QString::number(msInt);
    int secondsInt = ((RoboCop.elapsed() - msInt) % 60000) /1000;
    QString seconds;
    if(secondsInt < 10)
        seconds = "0" + QString::number(secondsInt);
    else
         seconds = QString::number(secondsInt);
    int minutesInt = (RoboCop.elapsed() - msInt) / 60000;
    QString minutes;
    if(minutesInt < 10)
        minutes = "0" + QString::number(minutesInt);
    else
         minutes = QString::number(minutesInt);
    QString fullTimer = (minutes + ":" + seconds + ":" + ms);
    return fullTimer;
}
