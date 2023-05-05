#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void holesStore(){

  setprecision(2);

  //variables for item barcodes
  int soccerGoal = 2345;
  int miniGolf = 2354;
  int basketBallHoop = 3452;
  int HockeyGoal = 4523;
  int rugbyGoal = 5234;

  //variables for item count
  int soccerCount = 0;
  int miniGolfCount = 0;
  int hoopCount = 0;
  int HockeyCount = 0;
  int rugbyCount = 0;

  //payment/cost variables
  double storePayment = 0, sumOfPrice = 0, totalWTax = 0;

  //store features variables
  char storeExit, storeConfirm;
  int storeChoice, storeSentinel = 1;
  
  cout << "***"<< endl;
  cout << "WELCOME IN TO ANAN'S GOALS AND HOLES!"<< endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << "Catalogue for Anan's Goals and Holes Store:"<< endl;
  cout << "> Kids Soccer goal post               $45.69" << endl;
  cout << "> Kids Portable Mini golf course     $655.75" << endl;
  cout << "> Kids Basketball hoop               $899.99" << endl;
  cout << "> Kids Hockey goal post              $329.99" << endl;
  cout << "> Kids Rugby goal Post               $121.95" << endl;
  
  cout << "Please scan the barcode on the paper catalogue to purchase an item" << endl;

  cout << endl;
  cout << endl;

  //while loop to stop purchasing phase
  while (storeSentinel != 0){
    cout << "Scan to Purchase (type 0 to stop): "; 
    cin >> storeChoice;

    //if statement that prints out cart if user inputted 0 in previous area
    if (storeChoice == 0){
      cout << endl;
      cout << "\n*** YOUR CART *** " << endl;
      cout << "Kids soccer goal post | Quantity : " << soccerCount << "x" << " | Price: @ $45.69 each" << endl;
      cout << "Kids portable mini golf course | Quantity : " << miniGolfCount << "x" << " | price @ $655.75 each" << endl;
      cout << "Kids Basketball hoop | Quantity : " << hoopCount << "x" << " | price @ $899.99 each" << endl;
      cout << "Kids Hockey goal post | Quantity : " << HockeyCount << "x" << " | price @ $329.99 each" << endl;
      cout << "Kids Rugby goal post | Quantity : " << rugbyCount << "x" << " | price @ $121.95 each" << endl;

      cout << "Type C to confirm or anything else to restart: ";
      cin >> storeConfirm;

      if (storeConfirm == 'C' or storeConfirm == 'c'){
        storeSentinel = 0;
      } else {
        storeSentinel = 1;
      }
    } else if (storeChoice == soccerGoal){
      soccerCount += 1;
    } else if (storeChoice == miniGolf){
      miniGolfCount += 1;
    } else if (storeChoice == basketBallHoop){
      hoopCount += 1;
    } else if (storeChoice == HockeyGoal){
      HockeyCount += 1;
    } else if (storeChoice == rugbyGoal){
      rugbyCount += 1;
    } else{
      cout << "\nERROR: That is an invalid item barcode. Please try again" << endl << endl;
    }
    
  }
  //recipt that is printed if user inputted c in previous section
  cout << endl;
  cout << "\n*** RECEIPT*** " << endl;
  cout << "ANAN'S GOALS AND HOLES" << endl;
  cout << "*********************************** " << endl;
  if (soccerCount > 0){
    cout << setw(3) << soccerCount << "x" << " Kids Soccer goal post" << "   " << double(soccerCount * 45.69) << endl;
  }
  if (miniGolfCount > 0){
    cout << setw(3) << miniGolfCount << "x" << " Kids Portable Mini golf course" << "   " << double(miniGolfCount * 655.75) << endl;
  }
  if (hoopCount > 0){
    cout << setw(3) << hoopCount << "x" << " Kids Basketball hoop" << "   " << double(hoopCount * 899.99) << endl;
  }
  if (HockeyCount > 0){
    cout << setw(3) << HockeyCount << "x" << "Kids Hockey goal post" << "  " << double(HockeyCount * 329.99) << endl;
  }
  if (rugbyCount > 0){
    cout << setw(3) << rugbyCount << "x" << "Child Cricket Bat 54321" << "  " << double(rugbyCount * 121.95) << endl;
  }

  //math to calculate sum of the total items
  sumOfPrice = (soccerCount * 45.69) + (miniGolfCount * 655.75) + (hoopCount * 899.99) + (HockeyCount * 329.99) + (rugbyCount * 121.95); 

  cout << "Subtotal " << sumOfPrice << endl;
  cout << "Tax " << fixed << setprecision(2) <<  sumOfPrice * 0.13 << endl;

  //math to calculate sum of the total items with tax
  totalWTax = sumOfPrice * 1.13;
  cout << fixed <<setprecision(2) << "Total " << totalWTax << endl;
  cout << "*********************************** " << endl;

  cout << endl; 

  while (storePayment < totalWTax){
    cout << "Enter your payment: ";
    cin >> storePayment;

    if (storePayment < totalWTax){
      cout << "\nInsufficient Amount" << endl;
    }  
  }

  cout << "\nYour change is " << storePayment - totalWTax << endl;

  cout << "THANKS FOR SHOPPING AT ANANS GOALS AND HOLES" << endl;

  //section to exit store and return to mall directory
  cout << "Enter any key to exit the store";
  cin >> storeExit;

  //error-trapping-the-system-clear-in-case-it-fails
  int systemRet = system("clear");
  if (systemRet == -1){
    cout << "there is an error with system";
  } 
}