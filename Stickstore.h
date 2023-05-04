//Oscar Ma
//Stick Store
//Ms. Wun
//2023-05-04

//include header files
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//function for the store
void stickStore(){

  //barcodes for the items
  int hockeyCode = 1357;
  int baseballCode = 2468;
  int badmintonCode = 12345;
  int lacrosseCode = 67890;
  int cricketCode = 54321;

  //variables to count for the items 
  int hockeyCount = 0;
  int baseballCount = 0;
  int badmintonCount = 0;
  int lacrosseCount = 0;
  int cricketCount = 0;

  //variable for the payment
  double stickPayment = 0;

  //variables for subtotal and total
  double sumOfPrice = 0;
  double totalWTax = 0;

  //variable to exit the store
  char stickExit;
  //variable to confirm receipt
  char stickConfirm;
  //variable for which stick to buy
  int stickChoice;
  //variable to stay in the loop
  int stickSentinel = 1;

  //output the store menu
  cout << "***"<< endl;
  cout << "WELCOME TO OSCARS STICK STORE!"<< endl;
  cout << endl; 
  cout << "> Kids Hockey Stick     $99.99" << endl;
  cout << "> Kids Baseball Bat     $69.99" << endl;
  cout << "> Kids Badminton Racket $49.99" << endl;
  cout << "> Kids Lacrosse Stick   $54.99" << endl;
  cout << "> Kids Cricket Bat      $79.99" << endl;
  
  cout << "\nPlease scan the barcode on the paper catalogue to purchase an item" << endl;

  //loop to get a valid user input for stick choice
  while (stickSentinel != 0){
    cout << "Scan to Purchase (type 0 to stop): "; 
    cin >> stickChoice;

    //output the items that the user bought if they enter 0
    if (stickChoice == 0){
      cout << endl;
      cout << "\n*** YOUR CART*** " << endl;
      cout << "Hockey Sticks x " << hockeyCount << " @ $99.99 each" << endl;
      cout << "Baseball Bats x " << baseballCount << " @ $69.99 each" << endl;
      cout << "Badminton Rackets x " << badmintonCount << " @ $49.99 each" << endl;
      cout << "Lacrosse Sticks x " << lacrosseCount << " @ $54.99 each" << endl;
      cout << "Cricket Bats x " << cricketCount << " @ $79.99 each" << endl;
  // ask the user if they want to continue
      cout << "Type C to confirm or anything else to restart: ";
      cin >> stickConfirm;
    //if the user enters c then exit the loop
      if (stickConfirm == 'C' or stickConfirm == 'c'){
        stickSentinel = 0;
      } else{
        //if they dont enter c then go back to ask the user for input
        stickSentinel = 1;
      }
      // if they enter a barcode number then add the item to the corresponding count
    } else if (stickChoice == hockeyCode){
      hockeyCount += 1;
    } else if (stickChoice == baseballCode){
      baseballCount += 1;
    } else if (stickChoice == badmintonCode){
      badmintonCount += 1;
    } else if (stickChoice == lacrosseCode){
      lacrosseCount += 1;
    } else if (stickChoice == cricketCode){
      cricketCount += 1;
    } else{
      cout << "This is an invalid barcode please enter something else" << endl;
    }
    
  }
  cout << endl;
  //output the receipt
  cout << "\n*** RECEIPT*** " << endl;
  cout << "OSCARS STICK STORE" << endl;
  cout << "*********************************** " << endl;
  //only display items the user bought
  if (hockeyCount > 0){
    cout << "Child Hockey Stick 1357" << endl;
    cout << setw(3) << hockeyCount << " @ $99.99 " << setw(22)<< fixed << setprecision(2) <<  double(hockeyCount * 99.99) << endl;
  }
  if (baseballCount > 0){
    cout << "Child Baseball Bat 2468" << endl;
    cout << setw(3) << baseballCount << " @ $69.99 " << setw(22) << fixed << setprecision(2) <<  double(baseballCount * 69.99) << endl;
  }
  if (badmintonCount > 0){
    cout << "Child Badminton Racket 12345" << endl;
    cout << setw(3) << badmintonCount << " @ $49.99 " << setw(22) << fixed << setprecision(2) <<  double(badmintonCount * 49.99) << endl;
  }
  if (lacrosseCount > 0){
    cout << "Child Lacrosse Stick 67890" << endl;
    cout << setw(3) << lacrosseCount << " @ $54.99 " << setw(22) << fixed << setprecision(2) <<  double(lacrosseCount * 54.99) << endl;
  }
  if (cricketCount > 0){
    cout << "Child Cricket Bat 54321" << endl;
    cout << setw(3) << cricketCount << " @ $79.99 " << setw(22) << fixed << setprecision(2) <<   double(cricketCount * 79.99) << endl;
  }
//calculate the subtotal
  sumOfPrice = (hockeyCount * 99.99) + (baseballCount * 69.99) + (badmintonCount * 49.99) + (lacrosseCount * 54.99) + (cricketCount * 79.99); 
//display the subtotal
  cout << "Subtotal " << setw(26) << fixed << setprecision(2) <<  sumOfPrice << endl;
//calculate the tax, and display
  cout << "Tax " << fixed << setprecision(2) << setw(31) <<  sumOfPrice * 0.13 << endl;
//calculate the total
  totalWTax = sumOfPrice * 1.13;
  cout << fixed <<setprecision(2) << "Total " << setw(29) <<  totalWTax << endl;
  cout << "*********************************** " << endl;

  cout << endl; 
//enter payment
  while (stickPayment < totalWTax){
    cout << "Enter your payment: ";
    cin >> stickPayment;
//check if they entered enough money
    if (stickPayment < totalWTax){
      cout << "\nInsufficient Amount" << endl;
    }  
  }
//output and calculate change
  cout << "\nYour change is " << stickPayment - totalWTax << endl;

  cout << "THANKS FOR SHOPPING AT OSCARS STICK STORE" << endl;
  //ask user to enter store
  cout << "Enter any key to exit the store: ";
  cin >> stickExit;
//clear screen
  int systemRet = system("clear");
  if (systemRet == -1) {
    cout << "There is an error with system" << endl;
  }
}
