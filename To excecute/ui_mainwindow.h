/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *startSolution;
    QPushButton *randomiseBlocks;
    QPushButton *resetButton;
    QLabel *gif;
    QPushButton *emergencyStop;
    QLCDNumber *timer;
    QCheckBox *checkBox;
    QLCDNumber *humanLCD;
    QLabel *label_4;
    QLCDNumber *humanTimer;
    QLabel *solvePlatform;
    QLabel *movesNeeded;
    QLabel *robotTime;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(720, 520);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 350, 231, 17));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setCursor(QCursor(Qt::ArrowCursor));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 22, 141, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Sans Serif"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_2->setFont(font1);
        label_2->setCursor(QCursor(Qt::BlankCursor));
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(120, 0, 141, 51));
        QFont font2;
        font2.setPointSize(15);
        lcdNumber->setFont(font2);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 10, 71, 41));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_3->setWordWrap(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 440, 561, 25));
        startSolution = new QPushButton(centralWidget);
        startSolution->setObjectName(QStringLiteral("startSolution"));
        startSolution->setGeometry(QRect(230, 380, 281, 61));
        QFont font3;
        font3.setFamily(QStringLiteral("Monospace"));
        font3.setPointSize(20);
        startSolution->setFont(font3);
        randomiseBlocks = new QPushButton(centralWidget);
        randomiseBlocks->setObjectName(QStringLiteral("randomiseBlocks"));
        randomiseBlocks->setGeometry(QRect(520, 10, 89, 25));
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setGeometry(QRect(620, 10, 89, 25));
        gif = new QLabel(centralWidget);
        gif->setObjectName(QStringLiteral("gif"));
        gif->setGeometry(QRect(150, 380, 391, 51));
        emergencyStop = new QPushButton(centralWidget);
        emergencyStop->setObjectName(QStringLiteral("emergencyStop"));
        emergencyStop->setGeometry(QRect(0, 0, 121, 51));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(239, 41, 41, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 147, 147, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(247, 94, 94, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(119, 20, 20, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(159, 27, 27, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(247, 148, 148, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        emergencyStop->setPalette(palette);
        emergencyStop->setLayoutDirection(Qt::LeftToRight);
        timer = new QLCDNumber(centralWidget);
        timer->setObjectName(QStringLiteral("timer"));
        timer->setGeometry(QRect(520, 0, 191, 41));
        timer->setDigitCount(8);
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(120, 0, 141, 51));
        QFont font4;
        font4.setPointSize(13);
        checkBox->setFont(font4);
        checkBox->setLayoutDirection(Qt::RightToLeft);
        humanLCD = new QLCDNumber(centralWidget);
        humanLCD->setObjectName(QStringLiteral("humanLCD"));
        humanLCD->setGeometry(QRect(10, 430, 131, 51));
        humanLCD->setFont(font2);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 430, 81, 51));
        QFont font5;
        font5.setPointSize(14);
        label_4->setFont(font5);
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_4->setWordWrap(true);
        humanTimer = new QLCDNumber(centralWidget);
        humanTimer->setObjectName(QStringLiteral("humanTimer"));
        humanTimer->setGeometry(QRect(520, 430, 191, 51));
        humanTimer->setDigitCount(8);
        solvePlatform = new QLabel(centralWidget);
        solvePlatform->setObjectName(QStringLiteral("solvePlatform"));
        solvePlatform->setGeometry(QRect(150, 440, 361, 41));
        QFont font6;
        font6.setPointSize(17);
        solvePlatform->setFont(font6);
        solvePlatform->setAlignment(Qt::AlignCenter);
        movesNeeded = new QLabel(centralWidget);
        movesNeeded->setObjectName(QStringLiteral("movesNeeded"));
        movesNeeded->setGeometry(QRect(500, 40, 211, 17));
        robotTime = new QLabel(centralWidget);
        robotTime->setObjectName(QStringLiteral("robotTime"));
        robotTime->setGeometry(QRect(520, 410, 191, 17));
        MainWindow->setCentralWidget(centralWidget);
        checkBox->raise();
        pushButton->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        startSolution->raise();
        randomiseBlocks->raise();
        resetButton->raise();
        lcdNumber->raise();
        gif->raise();
        emergencyStop->raise();
        timer->raise();
        humanLCD->raise();
        label_4->raise();
        humanTimer->raise();
        movesNeeded->raise();
        robotTime->raise();
        solvePlatform->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(false);
        mainToolBar->setMovable(false);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Available Blocks", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Ready to place:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Arm Move:", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Drop Block", nullptr));
        startSolution->setText(QApplication::translate("MainWindow", "Start Solution", nullptr));
        randomiseBlocks->setText(QApplication::translate("MainWindow", "Randomise", nullptr));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        gif->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        emergencyStop->setText(QApplication::translate("MainWindow", "Emergency Stop", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "Beat the Bot?", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Human Moves:", nullptr));
        solvePlatform->setText(QApplication::translate("MainWindow", "Solve Platform: ", nullptr));
        movesNeeded->setText(QApplication::translate("MainWindow", "Moves Needed to Solve: ", nullptr));
        robotTime->setText(QApplication::translate("MainWindow", "The robot took:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
