/**
 * @file ToddlerMallerMallA4Code.cpp
 * @authors: Ethan Zhou, Oscar Ma, Rahbab Hasan Anan
 * @for: Ms Wun
 * @class: ICS3U1
 * @date: 2023-05-04
 * @brief: A text store where you can shop at Ethan's Balls, Oscar's Sticks, and Anan's Goals and Holes
*/

#include <iostream>
#include "Balls.h"
#include "Stickstore.h"


using namespace std;


int main(){
  int inMall = 0;
  int storeChoice = 0;
  while (inMall == 0){
    cout << "Welcome to the Toddler Maller Mall!" << endl;
    cout << "\nDirectory: " << endl;
    cout << "1) Ethans Ball Store" << endl;
    cout << "2) Oscars Stick Store" << endl;
    cout << "3) Rahbabs Hole Store" << endl;
    cout << "4) Exit The Mall" << endl;

    while (storeChoice == 0){
      cout << "Enter your choice: ";
      cin >> storeChoice;
      if (storeChoice < 1 || storeChoice > 4){
        storeChoice = 0;
        cout << "Invalid Choice, Try Again" << endl;
      }
      
    }
  }
}