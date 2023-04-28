#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>

using namespace std;

static unordered_map<string, float> ballsCatalogue{
  {"Basketball", 49.99},
  {"Volleyball", 29.99},
  {"Tennis balls (4x pack)", 26.99},
  {"Golf balls (12x pack)", 24.99},
  {"Soccer ball", 34.99}
};

static unordered_map<int, string> ballsBarcodes {
  {1234567, "Basketball"},
  {1234567, "Volleyball"},
  {1234567, "Tennis balls (4x pack)"},
  {1234567, "Golf balls (12x pack)"},
  {1234567, "Soccer ball"}
};

static unordered_map<string, int> ballsBought {
  {"Basketball", 0},
  {"Volleyball", 0},
  {"Tennis balls (4x pack)", 0},
  {"Golf balls (12x pack)", 0},
  {"Soccer ball", 0}
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