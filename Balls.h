#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <cctype>
#include <cmath>

using namespace std;

void printBallsCatalogue(unordered_map<string, float> &ballsCatalogue){
  /**
    * @brief: Loops through the catalogue variable and prints the name of the item and its price
    * @params: ballsCatalogue - Takes in an unordered map of the catalogue with product names and prices by reference
  */

  cout << "Catalogue for Balls:" << endl;
  for (const auto &pair : ballsCatalogue){
    //Loops through the catalogue variable, using the new pair variable that holds the values of the unordered_map
    cout << ">";
    cout << setw(30) << left << pair.first;
    cout << right << "$" << pair.second << endl;
  }
  cout << "\nPlease scan the barcode on the paper catalogue to purchase an item.\n" << endl;
}

void buyBall(
  int barcodeNumber, 
  unordered_map<string, int> &ballsBought,
  unordered_map<int, string> &ballsBarcodes
){
  /**
    * @brief: Adds one to the number of products bought based off of the barcode number
    * @params: barcodeNumber - barcode number of product that is bought
    * @params: ballsBought - unordered map that maps the product name to the number of it bought
    * @params: ballsBarcodes - unordered map that maps the barcode to the product name
  */
  ballsBought[ballsBarcodes[barcodeNumber]] += 1;
}

bool containsProduct(
  int barcode,
  unordered_map<int, string> &ballsBarcodes
){
  /**
   * @brief: 
   * 
   */
  auto pointer = ballsBarcodes.find(barcode);
  return pointer == ballsBarcodes.end();
}

void printCart(
  unordered_map<string, float> &ballsCatalogue,
  unordered_map<string, int> &ballsBought
){
  /**
   * @brief: 
   * 
   */
  cout << "\n*** YOUR CART ***" << endl;
  for (const auto &pair : ballsCatalogue)
  {
    if (ballsBought[pair.first] > 0)
    {
      cout << pair.first;
      cout << setw(36 - pair.first.length()) << "x " << ballsBought[pair.first] << " @ $" << pair.second << " each" << endl;
    }
  }
}

void printReceipt(
  unordered_map<string, int> &ballsBought,
  unordered_map<string, float> &ballsCatalogue,
  unordered_map<string, int> &barcodeMap
){
  cout << "\n*** RECEIPT ***\nBALLS" << endl;
  cout << "************************************" << endl;
  float subTotal = 0;
  for (const auto &pair : ballsCatalogue)
  {
    if (ballsBought[pair.first] > 0)
    {
      float productTotal = ballsBought[pair.first] * pair.second;

      cout << pair.first << "  " << barcodeMap[pair.first] << endl;
      string temp = ("    " + to_string(ballsBought[pair.first])) + (" @ $");
      cout << temp;
      cout << setprecision(2) << fixed << pair.second;
      cout << setw(36 - 13 - to_string(ballsBought[pair.first]).length()) << setprecision(2) << right << fixed << productTotal << endl;
      subTotal += productTotal;
    }
}

  cout << "Subtotal";
  cout << setw(36 - 8) << fixed << setprecision(2) << subTotal << endl;


  cout << "Tax (13%)";
  cout << setw(36 - 9) << fixed << setprecision(2) << subTotal * 0.13 << endl;


  cout << "Total";
  cout << setw(36 - 5) << setprecision(2) << subTotal * 1.13 << endl;

  float payment;
  do
  {
    cout << "\nPlease enter payment amount: ";
    cin >> payment;
    if (payment < subTotal * 1.13){
      cout << "ERROR: That is insufficient funds.\n" << endl;
    }
  } while (payment < subTotal * 1.13);

  if (payment > subTotal * 1.13){
    cout << "\nYour change is $" << setprecision(2) << fixed << payment-subTotal * 1.13 << ".\n" << endl;
  }
}

void ballsStore(){
  char shopAgain;
  unordered_map<string, float> ballsCatalogue{
      {"Basketball (pairs)", 49.99},
      {"Volleyball (pairs)", 29.99},
      {"Tennis balls (pairs)", 26.99},
      {"Golf balls (pairs)", 24.99},
      {"Soccer ball (pairs)", 34.99}};

  unordered_map<int, string> ballsBarcodes{
      {1, "Basketball (pairs)"},
      {2, "Volleyball (pairs)"},
      {3, "Tennis balls (pairs)"},
      {4, "Golf balls (pairs)"},
      {5, "Soccer ball (pairs)"}};

  unordered_map<string, int> barcodeMap{
      {"Basketball (pairs)", 1},
      {"Volleyball (pairs)", 2},
      {"Tennis balls (pairs)", 3},
      {"Golf balls (pairs)", 4},
      {"Soccer ball (pairs)", 5}};

  unordered_map<string, int> ballsBought{
      {"Basketball (pairs)", 0},
      {"Volleyball (pairs)", 0},
      {"Tennis balls (pairs)", 0},
      {"Golf balls (pairs)", 0},
      {"Soccer ball (pairs)", 0}};
  do{
    ballsCatalogue = {
      {"Basketball (pairs)", 49.99},
      {"Volleyball (pairs)", 29.99},
      {"Tennis balls (pairs)", 26.99},
      {"Golf balls (pairs)", 24.99},
      {"Soccer ball (pairs)", 34.99}
    };

      ballsBarcodes = {
        {1, "Basketball (pairs)"},
        {2, "Volleyball (pairs)"},
        {3, "Tennis balls (pairs)"},
        {4, "Golf balls (pairs)"},
        {5, "Soccer ball (pairs)"}
      };

    barcodeMap = {
        {"Basketball (pairs)", 1},
        {"Volleyball (pairs)", 2},
        {"Tennis balls (pairs)", 3},
        {"Golf balls (pairs)", 4},
        {"Soccer ball (pairs)", 5}
    };

    ballsBought = {
        {"Basketball (pairs)", 0},
        {"Volleyball (pairs)", 0},
        {"Tennis balls (pairs)", 0},
        {"Golf balls (pairs)", 0},
        {"Soccer ball (pairs)", 0}
    };

    cout << "***\nWelcome to Ethan's Balls\n" << endl;
    printBallsCatalogue(ballsCatalogue);

    int barcodeInput;
    do
    {
      cout << "Scan to purchase (Type 0 to stop): ";
      cin >> barcodeInput;
      
      if (containsProduct(barcodeInput, ballsBarcodes) && barcodeInput != 0)
      {
        cout << "\nERROR: That is an invalid item barcode. Please try again.\n" << endl;
      }
      else
      {
        buyBall(barcodeInput, ballsBought, ballsBarcodes);
      }
    } while (barcodeInput != 0);

    printCart(ballsCatalogue, ballsBought);

    cout << "\nType C to confirm or anything else to re-start: ";
    cin >> shopAgain;

  } while (tolower(shopAgain) != 'c');

  printReceipt(ballsBought, ballsCatalogue, barcodeMap);
}