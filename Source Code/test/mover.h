#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include<QThread>
#include<QApplication>
#include "gripperbotstructures.h"
using namespace std;

class Mover {
protected:

private:
  void pickUpFirstBlock(string);
  void pickUpSecondBlock(string);
  void pickUpThirdBlock(string);
  void pickUpFourthBlock(string);
  void pickUpFifthBlock(string);
  void pickUpSixthBlock(string);
  vector<string> col;
public:
  Mover();
    void drop();
  void PickUp(int row, int column);
  void Place(int row, int column);
  void resetArm();
};

void Mover::PickUp(int row, int column) {
  switch(row) {
    case 0:
    pickUpFirstBlock(col[column]);
    break;
    case 1:
    pickUpSecondBlock(col[column]);
    break;
    case 2:
    pickUpThirdBlock(col[column]);
    break;
    case 3:
    pickUpFourthBlock(col[column]);
    break;
    case 4:
    pickUpFifthBlock(col[column]);
    break;
    case 5:
    pickUpSixthBlock(col[column]);
    break;
  }
}

void Mover::Place(int row, int column) {
  switch(row) {
    case 0:
    pickUpFirstBlock(col[column]);
    break;
    case 1:
    pickUpSecondBlock(col[column]);
    break;
    case 2:
    pickUpThirdBlock(col[column]);
    break;
    case 3:
    pickUpFourthBlock(col[column]);
    break;
    case 4:
    pickUpFifthBlock(col[column]);
    break;
    case 5:
    pickUpSixthBlock(col[column]);
    break;
  }
  drop();
}

Mover::Mover() {
  col.push_back("0.73");
  col.push_back("0.30");
  col.push_back("-0.30");
  col.push_back("-0.73");
}

void Mover::resetArm() {
  QThread::sleep(1.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -1.350& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_lift_joint/command std_msgs/Float64 -- 0.0& > /dev/null'"); // more is down
  QThread::sleep(1.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 0.00& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_pan_joint/command std_msgs/Float64 -- -0.00& > /dev/null'"); //less is right
  QThread::sleep(3.5);
  cout<<"slept"<<endl;
  QApplication::processEvents();

  //system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /gripper_joint/command std_msgs/Float64 -- 0.00& > /dev/null'");

}

void Mover::pickUpSixthBlock(string col) {
  resetArm();
  system(("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_pan_joint/command std_msgs/Float64 -- "+ col + "& > /dev/null'").c_str()); //less is right
  QThread::sleep(1.5);
  QApplication::processEvents();

  //dont change
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 0.34& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -1.35& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 0.981& > /dev/null '"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_lift_joint/command std_msgs/Float64 -- 0.68 > /dev/null'"); // more is down
  QThread::sleep(3.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -0.158 > /dev/null '"); //less is up
  QApplication::processEvents();
  //sleep(1.5);
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /gripper_joint/command std_msgs/Float64 -- 0.75 > /dev/null'");
  QApplication::processEvents();
}

void Mover::pickUpFifthBlock(string col) {
  resetArm();
  system(("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_pan_joint/command std_msgs/Float64 -- "+ col + "& > /dev/null '").c_str()); //less is right
  QThread::sleep(1.5);
  QApplication::processEvents();

  //dont change
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 0.34& > /dev/null '"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -1.35& > /dev/null '"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 1.104& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_lift_joint/command std_msgs/Float64 -- 0.846 > /dev/null'"); // more is down
  QThread::sleep(1.5);
  QApplication::processEvents();

  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -0.478 > /dev/null'"); //less is up
  QApplication::processEvents();
  //sleep(1.5);
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /gripper_joint/command std_msgs/Float64 -- 0.75 > /dev/null'");
  QApplication::processEvents();
}

void Mover::pickUpFourthBlock(string col) {
  resetArm();
  system(("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_pan_joint/command std_msgs/Float64 -- "+ col + "& > /dev/null'").c_str()); //less is right
  QThread::sleep(1.5);
  QApplication::processEvents();
  //dont change
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 0.34& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -1.35& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 1.12& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_lift_joint/command std_msgs/Float64 -- 1.02 > /dev/null'"); // more is down
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -0.620 > /dev/null'"); //less is up
  QApplication::processEvents();
  //sleep(1.5);
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /gripper_joint/command std_msgs/Float64 -- 0.75 > /dev/null'");
  QApplication::processEvents();
}

void Mover::pickUpThirdBlock(string col) {
  resetArm();
  system(("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_pan_joint/command std_msgs/Float64 -- "+ col + "& > /dev/null'").c_str()); //less is right
  QThread::sleep(1.5);
  QApplication::processEvents();
  //dont change
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 0.34& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -1.35& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 1.07& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_lift_joint/command std_msgs/Float64 -- 1.23 > /dev/null'"); // more is down
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -0.77 > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /gripper_joint/command std_msgs/Float64 -- 0.75 > /dev/null'");
  QApplication::processEvents();
}

void Mover::pickUpSecondBlock(string col) {
  resetArm();
  system(("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_pan_joint/command std_msgs/Float64 -- "+ col + "& > /dev/null'").c_str()); //less is right
  QThread::sleep(1.5);
  QApplication::processEvents();
  //dont change
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 0.34& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -1.35& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 0.855& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_lift_joint/command std_msgs/Float64 -- 1.52 > /dev/null'"); // more is down
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -0.82 > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /gripper_joint/command std_msgs/Float64 -- 0.75 > /dev/null'");
  QApplication::processEvents();
}

void Mover::pickUpFirstBlock(string col) {
  resetArm();
  system(("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_pan_joint/command std_msgs/Float64 -- "+ col + "& > /dev/null'").c_str()); //less is right
  QThread::sleep(1.5);
  QApplication::processEvents();
  //dont change
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 0.34& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -1.35& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_elbow_flex_joint/command std_msgs/Float64 -- 0.34& > /dev/null'"); //less is up
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_shoulder_lift_joint/command std_msgs/Float64 -- 2.0 > /dev/null'"); // more is down
  QThread::sleep(1.5);
  QApplication::processEvents();
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /arm_wrist_flex_joint/command std_msgs/Float64 -- -0.65 > /dev/null'"); //less is up
  QApplication::processEvents();
  //sleep(1.5);
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /gripper_joint/command std_msgs/Float64 -- 0.75 > /dev/null'");
  QApplication::processEvents();
}

void Mover::drop() {
  system("bash -c ' cd /home/jamie/catkin_ws;source ~/catkin_ws/devel/setup.bash;rostopic pub -1 /gripper_joint/command std_msgs/Float64 -- 0.00& > /dev/null'");
  cout<<"Gripper open has ran";
}
