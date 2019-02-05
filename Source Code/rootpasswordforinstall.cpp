#include "rootpasswordforinstall.h"
#include "ui_rootpasswordforinstall.h"
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <thread>
#include <future>
#include <chrono>
#include <initializer_list>
#include <signal.h>
#include <unistd.h>
rootPasswordForInstall::rootPasswordForInstall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rootPasswordForInstall)
{
    ui->setupUi(this);
    dependencyInstallOutput = ui->listWidget;
}

void rootPasswordForInstall::closeEvent(QCloseEvent* event) {
    for(int x=0;x<thepid.size();x++)
    std::cout<<std::endl<<thepid[x]<<std::endl;
    //Kills clingo to avoid a zombie
    for(int x=0;x<thepid.size();x++)
    kill(thepid[x],SIGTERM);
    //Properly ends roslaunch and all dependencies
    QString s = "pkill -f roslaunch;";
    system(s.toStdString().c_str());
    exit(0);
}

rootPasswordForInstall::~rootPasswordForInstall()
{
    delete ui;
}
