/**
 * @file ToddlerMallerMallA4Code.cpp
 * @authors: Ethan Zhou, Oscar Ma, Rahbab Hasan Anan
 * @for: Ms Wun
 * @class: ICS3U1
 * @date: 2023-05-04
 * @brief: A text store where you can shop at Ethan's Balls, Oscar's Sticks, and Anan's Goals and Holes
*/

#include <iostream>
#include <stdlib.h>
#include "Balls.h"
#include "Stickstore.h"
#include "GoalsAndHoles.h"

using namespace std;

void directoryOut(){
  cout << "\nWelcome to the Toddler Maller Mall!" << endl;
      cout << "\nDirectory: " << endl;
      cout << "1) Ethans Ball Store" << endl;
      cout << "2) Oscars Stick Store" << endl;
      cout << "3) Rahbabs Goals and Holes Store" << endl;
      cout << "4) Exit The Mall" << endl;
}

int main(){
  bool inMall = true;
  int storeChoice = 0;
  while (inMall){
    cout << "Welcome to the Toddler Maller Mall!" << endl;
    cout << "\nDirectory: " << endl;
    cout << "1) Ethans Ball Store" << endl;
    cout << "2) Oscars Stick Store" << endl;
    cout << "3) Rahbabs Goals and Holes Store" << endl;
    cout << "4) Exit The Mall" << endl;

    while (storeChoice == 0){
      cout << "Enter your choice: ";
      cin >> storeChoice;
      if (storeChoice < 1 || storeChoice > 4){
        storeChoice = 0;
        cout << "Invalid Choice, Try Again" << endl;
      }

    if (storeChoice == 1){
      ballsStore();
      directoryOut();
      storeChoice = 0;
      
    } else if (storeChoice == 2){
      stickStore();
      directoryOut();
      storeChoice = 0;
      
    } else if (storeChoice == 3){
      holesStore();
      directoryOut();
      storeChoice = 0;
      
    } else if (storeChoice == 4){
      cout << "You have exited the Mall" << endl;
      inMall = false;
    }
    }
  }
}