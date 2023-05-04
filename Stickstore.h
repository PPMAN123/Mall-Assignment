//Oscar Ma
//Store for
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void stickStore(){
  int hockeyCode = 1357;
  int baseballCode = 2468;
  int badmintonCode = 12345;
  int lacrosseCode = 67890;
  int cricketCode = 54321;

  int hockeyCount = 0;
  int baseballCount = 0;
  int badmintonCount = 0;
  int lacrosseCount = 0;
  int cricketCount = 0;

  double stickPayment = 0;

  double sumOfPrice = 0;
  double totalWTax = 0;

  char stickExit;
  char stickConfirm;
  int stickChoice;
  int stickSentinel = 1;
  
  cout << "***"<< endl;
  cout << "WELCOME TO OSCARS STICK STORE!"<< endl;
  cout << endl; 
  cout << "> Kids Hockey Stick     $99.99" << endl;
  cout << "> Kids Baseball Bat     $69.99" << endl;
  cout << "> Kids Badminton Racket $50.00" << endl;
  cout << "> Kids Lacrosse Stick   $54.99" << endl;
  cout << "> Kids Cricket Bat      $79.99" << endl;

  cout << "\nPlease scan the barcode on the paper catalogue to purchase an item" << endl;

  while (stickSentinel != 0){
    cout << "Scan to Purchase (type 0 to stop): "; 
    cin >> stickChoice;

    if (stickChoice == 0){
      cout << endl;
      cout << "\n*** YOUR CART*** " << endl;
      cout << "Hockey Sticks x " << hockeyCount << " @ $99.99 each" << endl;
      cout << "Baseball Bats x " << baseballCount << " @ $69.99 each" << endl;
      cout << "Badminton Rackets x " << badmintonCount << " @ $50.00 each" << endl;
      cout << "Lacrosse Sticks x " << lacrosseCount << " @ $54.99 each" << endl;
      cout << "Cricket Bats x " << cricketCount << " @ $79.99 each" << endl;

      cout << "Type C to confirm or anything else to restart: ";
      cin >> stickConfirm;

      if (stickConfirm == 'C' or stickConfirm == 'c'){
        stickSentinel = 0;
      } else{
        stickSentinel = 1;
      }
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
  cout << "\n*** RECEIPT*** " << endl;
  cout << "OSCARS STICK STORE" << endl;
  cout << "*********************************** " << endl;
  if (hockeyCount > 0){
    cout << "Child Hockey Stick 1357" << endl;
    cout << setw(3) << hockeyCount << " @ $99.99 " << setw(22)<< double(hockeyCount * 99.99) << endl;
  }
  if (baseballCount > 0){
    cout << "Child Baseball Bat 2468" << endl;
    cout << setw(3) << baseballCount << " @ $69.99 " << setw(22) << double(baseballCount * 69.99) << endl;
  }
  if (badmintonCount > 0){
    cout << "Child Badminton Racket 12345" << endl;
    cout << setw(3) << badmintonCount << " @ $50.00 " << setw(22) << double(badmintonCount * 50.00) << endl;
  }
  if (lacrosseCount > 0){
    cout << "Child Lacrosse Stick 67890" << endl;
    cout << setw(3) << lacrosseCount << " @ $54.99 " << setw(22) << double(lacrosseCount * 54.99) << endl;
  }
  if (cricketCount > 0){
    cout << "Child Cricket Bat 54321" << endl;
    cout << setw(3) << cricketCount << " @ $79.99 " << setw(22) << double(cricketCount * 79.99) << endl;
  }

  sumOfPrice = (hockeyCount * 99.99) + (baseballCount * 69.99) + (badmintonCount * 50.00) + (lacrosseCount * 54.99) + (cricketCount * 79.99); 

  cout << "Subtotal " << setw(26) << sumOfPrice << endl;
  cout << "Tax " << fixed << setprecision(2) << setw(31) <<  sumOfPrice * 0.13 << endl;

  totalWTax = sumOfPrice * 1.13;
  cout << fixed <<setprecision(2) << "Total " << setw(29) <<  totalWTax << endl;
  cout << "*********************************** " << endl;

  cout << endl; 

  while (stickPayment < totalWTax){
    cout << "Enter your payment: ";
    cin >> stickPayment;

    if (stickPayment < totalWTax){
      cout << "\nInsufficient Amount" << endl;
    }  
  }

  cout << "\nYour change is " << stickPayment - totalWTax << endl;

  cout << "THANKS FOR SHOPPING AT OSCARS STICK STORE" << endl;
  
  cout << "Enter any key to exit the store";
  cin >> stickExit;

  
  
}
