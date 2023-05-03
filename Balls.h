#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>

using namespace std;

static unordered_map<string, float> ballsCatalogue{
  {"Basketball (pairs)", 49.99},
  {"Volleyball (pairs)", 29.99},
  {"Tennis balls (pairs)", 26.99},
  {"Golf balls (pairs)", 24.99},
  {"Soccer ball (pairs)", 34.99}
};

static unordered_map<int, string> ballsBarcodes {
  {1234567, "Basketball (pairs)"},
  {1234567, "Volleyball (pairs)"},
  {1234567, "Tennis balls (pairs)"},
  {1234567, "Golf balls (pairs)"},
  {1234567, "Soccer ball (pairs)"}
};

static unordered_map<string, int> barcodeMap{
  {"Basketball (pairs)", 1234567},
  {"Volleyball (pairs)", 1234567},
  {"Tennis balls (pairs)", 1234567},
  {"Golf balls (pairs)", 1234567},
  {"Soccer ball (pairs)", 1234567}
};

static unordered_map<string, int> ballsBought {
  {"Basketball (pairs)", 0},
  {"Volleyball (pairs)", 0},
  {"Tennis balls (pairs)", 0},
  {"Golf balls (pairs)", 0},
  {"Soccer ball (pairs)", 0}
};

void printBallsCatalogue(){
  /*
    Loops through the catalogue variable and prints the name of object and price out
  */
  for (const auto&pair : ballsCatalogue){
    cout << ">";
    cout << setw(30) << left << pair.first;
    cout << right << "$" << pair.second << endl;
  }
}

void buyBall(int barcodeNumber){
  /*
    Adds one to the number of products bought
  */
  ballsBought[ballsBarcodes[barcodeNumber]] += 1;
}

bool containsProduct(int barcode){
  auto pointer = ballsBarcodes.find(barcode);
  return pointer == ballsBarcodes.end();
}

void printCart(){
  cout << "*** YOUR CART ***" << endl;
  for (const auto&pair : ballsCatalogue){
    if (ballsBought[pair.first] > 0){
      cout << setw(36) << left << pair.first << "  x  " << ballsBought[pair.first] << " @ $" << pair.second << " each" << endl;
    }
  }
}

void printReceipt(){
  cout << "*** RECEIPT ***\nBALLS" << endl;
  cout << "************************************" << endl;
  float subTotal = 0;
  for (const auto&pair : ballsCatalogue){
    if (ballsBought[pair.first] > 0){
      float productTotal = ballsBought[pair.first] * pair.second;
      cout << pair.first << "\t" << barcodeMap[pair.first] << endl;
      cout << setw(36) << left << "\t\t" << ballsBought[pair.first] << " @ " << pair.second;
      cout << right << setprecision(2) << productTotal << endl;
      subTotal += productTotal;
    }
  }
  cout << setw(36) << left << "Subtotal";
  cout << right << setprecision(2) << subTotal << endl;
  cout << setw(36) << left << "Tax (13%)";
  cout << right << setprecision(2) << subTotal*0.13 << endl;
  cout << setw(36) << left << "Total";
  cout << right << setprecision(2) << subTotal*1.13 << endl;

  float payment;
  do{
    cout << "Please enter payment amount: ";
    cin >> payment;
    if(payment < subTotal*1.13){
      cout << "ERROR: That is insufficient funds.\n" << endl;
    }
  } while (payment < subTotal*1.13);
}

void ballsStore(){
  cout << "Welcome to Ethan's Balls\n" << endl;
  printBallsCatalogue();
  
}