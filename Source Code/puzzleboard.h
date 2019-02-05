#ifndef PUZZLEBOARD_H
#define PUZZLEBOARD_H

#endif // PUZZLEBOARD_H
#include "gripperbotstructures.h"

#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <random>
#include <iostream>
#include <QVector>
#include <QPushButton>
#include <QString>

using namespace std;
using namespace GripperStructures;
class PuzzleBoard{
 protected:
 int pegCount[4]= {0,0,0,0};
private:
  std::vector<int> tempvec; //A tempoorary vector of the unplaced numbers
  std::mt19937 rng; //Random number generator for C++ 11
  void fillInitialVector();//Private as we dont want to recreate the board
  void fixInvalid(int number); //Fixes a layout where we cannot place another number (e.g. placing 6 when all pgs are occupied)
  bool checkValidInital(int peg,int number); //Returns true or false
 public:
  QVector<QPushButton*> buttonArray;
  QVector<PlatformStruct*> platformArray;
std::vector<std::vector<int> > theBoard; //The final game board which is used
void boardAnalyser();
 void printBoard();
 bool isSolved();
 int blockNum(int);
 PuzzleBoard(QVector<QPushButton*>, QVector<PlatformStruct*>&);
 };

 PuzzleBoard::PuzzleBoard(QVector<QPushButton*> ButtonArray, QVector<PlatformStruct*>& PlatformArray) {
     buttonArray = ButtonArray;
     platformArray = PlatformArray;
   rng.seed(std::random_device()());
   fillInitialVector();
   printBoard();
 }

//Returns the number of blocks on a peg
 int PuzzleBoard::blockNum(int peg) {
   return theBoard[peg].size();
 }

//Checks the validity of a move
 bool PuzzleBoard::checkValidInital(int peg, int number) {
   // cout<<"The peg is: "<<peg<<endl<<"The current count is :"<<theBoard[peg].size()<<endl;
   // cout<<"The board num is :"<<theBoard[peg][theBoard[peg].size()-1]<<endl<<"the number is: "<<number<<endl;
   if(blockNum(peg)>0) {
   if(theBoard[peg][blockNum(peg)-1]>number) {
     // cout<<"Entered here"<<endl<<endl;
   return true;
 }
   else
   return false;
 }
 else {
    return true;
 }
}
/*
  Fixes invalid configurations by pushing an invalid number back to the available numbers
  and then erasing the now spot so it can be used. Pegs are selected at random.
*/
void PuzzleBoard::fixInvalid(int number) {
//   cout<<endl<<endl<<"Entered with: "<<tempvec[number]<<endl<<endl;
   bool done=false;
   bool someEmpty = false;
   std::vector<int> pegs = {0,1,2,3};

   // for(int x=0;x<4;x++) {
   //   if(theBoard[x].size()==0) {
   //     theBoard[x].push_back(tempvec[number]);
   //   tempvec.erase(tempvec.begin() + number);
   //   cout<<"anus"<<endl;
   //   done=true;
   //   break;
   // }
   // }

   //check each and every peg
   while(pegs.size()>0&&!done) {
     std::uniform_int_distribution<std::mt19937::result_type> choosePeg(0,pegs.size()-1);
     int tempRand =choosePeg(rng);
     if(theBoard[pegs[tempRand]].size()>0)
     if(theBoard[pegs[tempRand]][0]<tempvec[number]){
    //   cout<<endl<<endl<<"We just titty popped "<<theBoard[pegs[tempRand]][0]<<" for "<<tempvec[number]<<endl<<endl;
       tempvec.push_back(theBoard[pegs[tempRand]][0]);
       theBoard[pegs[tempRand]].erase(theBoard[pegs[tempRand]].begin());
       // theBoard[pegs[tempRand]].push_back(tempvec[number]);
       // tempvec.erase(tempvec.begin() + number);
       done=true;
       break;
     }
     pegs.erase(pegs.begin());

   }

  // cout<<endl<<endl<<"EXITED YEWWW"<<endl<<endl;
}

//Fills the tempvec with the amount of blocks
 void PuzzleBoard::fillInitialVector() {
   std::uniform_int_distribution<std::mt19937::result_type> choosePeg(0,3);
   for(int x=0;x<4;x++)
        theBoard.push_back(std::vector<int>());
        for(int x=1;x<7;x++) {
            tempvec.push_back(x);
      //std::cout << choosePeg(rng) << '\n';
        }
  //  for(int x=0;x<10;x++)
    //cout<<choosePeg(rng)<<endl;
    //All good up until this point
    sleep(0);

    //While all blocks aren't placed
    while(tempvec.size()>0) {
      //Use tempvec.size() as we may need to push_back from popped pegs to validate
      bool done;
      done = false;
      std::uniform_int_distribution<std::mt19937::result_type> chooseNum(0,tempvec.size()-1);
      int tempPeg= choosePeg(rng);
      int tempNum = chooseNum(rng);
      if(theBoard[tempPeg].size()==0) {
      theBoard[tempPeg].push_back(tempvec[tempNum]);
    tempvec.erase(tempvec.begin() + tempNum);
  }
  else {
    if(checkValidInital(tempPeg,tempvec[tempNum])) {
      theBoard[tempPeg].push_back(tempvec[tempNum]);
    tempvec.erase(tempvec.begin() + tempNum);
    }
    else {
      // cout<<endl<<endl<<"Didn't work, attempting to fix"<<endl<<endl;
    fixInvalid(tempNum);
    // cout<<endl<<endl<<"It got fixed"<<endl<<endl;
  }
  }
    //cout<<tempNum<<endl; //All good for size
    }

 }

//Prints the game board
 void PuzzleBoard::printBoard() {
     ApplicationHandler handler;
   for(int x=5;x>-1;x--)
   {
     for(int y=0;y<4;y++) {
         if(theBoard[y].size()>x) {
       cout<<theBoard[y][x]<<"\t";
       if(theBoard[y][theBoard[y].size()-x-1]>0) {
       buttonArray[theBoard[y][x]-1]->blockSignals(true);
       buttonArray[theBoard[y][x]-1]->setGeometry(QRect(QPoint(handler.returnButtonX(y), handler.returnButtonY(x)),QSize(51, 41)));
       platformArray[y]->platformStack.push_back(theBoard[y][theBoard[y].size()-x-1]-1);
       }
         }
       else
       cout<<" \t";
     }
     cout<<endl;
   }
   for(int x=0;x<4;x++)
   cout<<"X\t";
   cout<<endl;
   cout<<endl;
 }

//Prints what blocks should be in what cell. Mostly used for simulation and validity
//of indexes used for clingo (e.g. 1,1 is 0,0 on the vector and may be confused)
 void PuzzleBoard::boardAnalyser() {
   //Shit below prooves sanity==true;
   cout<<"0, size:"<<theBoard[0].size()<<endl;
   for(int x=0;x<theBoard[0].size();x++)
   cout<<theBoard[0][x]<<"\t";
   cout<<endl<<endl;
   cout<<"1, size:"<<theBoard[1].size()<<endl;
   for(int x=0;x<theBoard[1].size();x++)
   cout<<theBoard[1][x]<<"\t";
   cout<<endl<<endl;
   cout<<"2, size:"<<theBoard[2].size()<<endl;
   for(int x=0;x<theBoard[2].size();x++)
   cout<<theBoard[2][x]<<"\t";
   cout<<endl<<endl;
   cout<<"3, size:"<<theBoard[3].size()<<endl;
   for(int x=0;x<theBoard[3].size();x++)
   cout<<theBoard[3][x]<<"\t";
   cout<<endl<<endl;
 }
