#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include "applicationhandler.h"
#include <QStack>
#include <QElapsedTimer>
#include "gripperbotstructures.h"

using namespace GripperStructures;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    QPushButton* theButton;
//    QPushButton* topButton;
     QPushButton* m_button;
    QPushButton* platformOne;
    QVector<qint64> thepid;
    QVector<QPushButton*> buttonArray;
    QVector<PlatformStruct*> platformArray;
    void hideIt();
private:
     QElapsedTimer humanTimer;
    Ui::MainWindow *ui;
    ApplicationHandler handler;
    int availableBlocks = 6;
    void closeEvent(QCloseEvent *event) override;
    void checkReadyToSolveOrComplete();
    QString returnTime(QElapsedTimer);
    int humanMoves = 0;
private slots:
    void handleClick();
    void platformClick();
    void challengePlatformClick();
    void buttonArrayClicked();
    void dropItLikeItsHot();
    void randomise();
    void resetBlocks();
     void startExecution();
     void PlayAgainstRobotToggle();
   // void resetBlocks();
public slots:
     void emergencyStopProgram();
};

#endif // MAINWINDOW_H
