#include "mainwindow.h"
#include <QInputDialog>
#include "rootpasswordforinstall.h"
#include <sys/stat.h>
#include <pwd.h>
#include <unistd.h>
#include <QApplication>
#include <iostream>
#include "applicationhandler.h"
#include <thread>
#include <QVector>
#include <QMessageBox>
#include <QProcess>
#include <QElapsedTimer>
#include <QDesktopWidget>
#include <signal.h>
#include <unistd.h>
void roslaunch(QVector<qint64>& pid) {
    QProcess roslaunchProcess;
    roslaunchProcess.setProgram("bash");
    roslaunchProcess.setArguments(QStringList() << "-c" << "cd ~/catkin_ws; source ~/catkin_ws/devel/setup.bash; roslaunch arbotix_python phantomX_arm.launch > /dev/null 2>&1;");
    qint64 thePid;
    roslaunchProcess.setStandardOutputFile("roscheck.txt");
    roslaunchProcess.startDetached(&thePid);
    pid.push_back(thePid);
    std::cout<<"pid "<<pid[pid.size()-1]<<std::endl<<std::endl<<std::endl;
   // system("bash -c 'cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;roslaunch arbotix_python phantomX_arm.launch'");
}

void installDependencies(QVector<qint64>& pid) {
    QProcess roslaunchProcess;
    roslaunchProcess.setProgram("bash");
    roslaunchProcess.setArguments(QStringList() << "-c" <<"rm /etc/ros/rosdep/sources.list.d/20-default.list;wget https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -O - | sudo apt-key add -;sudo apt-get update;\
sudo apt-get install ros-kinetic-desktop-* -y;sudo rosdep init;echo 'source /opt/ros/kinetic/setup.bash' >> /home/$USER/.bashrc;source /home/$USER/.bashrc;sudo apt-get install python-rosinstall -y;mkdir -p /home/$USER/catkin_ws/src;\
mkdir -p /home/$USER/catkin_ws/src;cd /home/$USER/catkin_ws/;catkin_make;echo 'source /home/$USERcatkin_ws/devel/setup.bash' >> /home/$USER/.bashrc;cd /home/$USER/catkin_ws/src;git clone https://github.com/vanadiumlabs/arbotix_ros.git;cd /home/$USER/catkin_ws;\
catkin_make -DCMAKE_BUILD_TYPE=Release;source /home/$USER/catkin_ws/devel/setup.bash;cp Dependencies/default.yaml /home/$USER/catkin_ws/src/arbotix_ros/arbotix_python/config;cp Dependencies/lphantomX_arm.launch /home/$USER/catkin_ws/src/arbotix_ros/arbotix_python/launch;");
    qint64 thePid;
    roslaunchProcess.setStandardOutputFile("roscheck.txt");
    roslaunchProcess.startDetached(&thePid);
    pid.push_back(thePid);
     while(kill(thePid, 0)>-1) {
         QCoreApplication::processEvents();
     }
     system("rosdep update;roscore");
    std::cout<<"pid "<<thePid<<std::endl<<std::endl<<std::endl;
   // system("bash -c 'cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;roslaunch arbotix_python phantomX_arm.launch'");
    std::cout<<std::endl<<std::endl<<"done";
}

QElapsedTimer timer;
int seconds;
void timeDifference() {
    timer.start();
    while(1) {
        seconds = timer.elapsed() / 1000;
    }
}

int main(int argc, char *argv[])
{
    struct stat rosCheck;
    struct stat catkinCheck;
    QString homedir;

    if ((homedir = getenv("HOME")) == NULL) {
        homedir = getpwuid(getuid())->pw_dir;
    }
    homedir = homedir + "/catkin_ws";

    QApplication a(argc, argv);
    //
    rootPasswordForInstall window;
    MainWindow w;
//    if(w.theButton->clicked()) {
//        system("echo 'hello'");
//    }
    QDesktopWidget wid;

    int screenWidth = wid.screen()->width();
    int screenHeight = wid.screen()->height();
    w.setGeometry((screenWidth/2)-(w.width()/2),(screenHeight/2)-(w.height()/2),w.width(),w.height());
   // std::thread getTimeDifference(timeDifference);
    ApplicationHandler handler;
    handler.setAvailable(w.buttonArray[3]);
   // thePuzzle.printBoard();
    if(stat("/opt/ros/kinetic",&rosCheck)!=-1 && stat(homedir.toUtf8(),&catkinCheck)!=-1) {
        if(S_ISDIR(rosCheck.st_mode)||!S_ISDIR(catkinCheck.st_mode)) {
        w.show();
        //installDependencies(QInputDialog::getText(0,"Sudo Password","Please enter your pasword to install dependencies",QLineEdit::Password));
        }
    }
    else {
        if(getuid()) {
            QMessageBox msgBox;
            msgBox.setText("Error:");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Install Dependencies");
            msgBox.setInformativeText("Please open the README file and follow the steps \n to install all dependencies");
            msgBox.exec();
            w.emergencyStopProgram();
        }
        QCoreApplication::exit();
        //installDependencies(window.thepid);
    }

    std::thread launchRoslaunch (roslaunch,std::ref(w.thepid));

    return a.exec();
}
