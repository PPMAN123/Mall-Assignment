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
    * @params: ballsBought - unordered map that maps product name to the amount of it bought passed by reference
    * @param: ballsBarcodes - the unordered map of barcodes that map to the product name passed by reference
  */
  ballsBought[ballsBarcodes[barcodeNumber]] += 1;
}

bool containsProduct(
  int barcode,
  unordered_map<int, string> &ballsBarcodes
){
  /**
   * @brief: Checks if an item exists within the catalogue
   * @param: barcode - an integer barcode to check if it exists in the catalogue
   * @param: ballsBarcodes - the unordered map of barcodes that map to the product name passed by reference
   * @return: a boolean that returns if the barcode exists within the keys of ballsBarcodes
   */
  //Using some unordered map utilities
  auto pointer = ballsBarcodes.find(barcode);
  return pointer == ballsBarcodes.end();
}

void printCart(
  unordered_map<string, float> &ballsCatalogue,
  unordered_map<string, int> &ballsBought
){
  /**
   * @brief: Prints out the current cart of the user 
   * @param: ballsBarcodes - the unordered map of barcodes that map to the product name passed by reference
   * @params: ballsBought - unordered map that maps the product name to the number of it bought
   */

  cout << "\n*** YOUR CART ***" << endl;

  for (const auto &pair : ballsCatalogue){
    //loops through the ballsCatalogue variable
    if (ballsBought[pair.first] > 0){
      //Checks if the product has been bought, then prints out the information about whatever product that has been added to cart
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
  /**
   * @brief: 
   * @params: ballsBought - unordered map that maps product name to the amount of it bought passed by reference
   * @params: ballsCatalogue - Takes in an unordered map of the catalogue with product names and prices by reference
   * @params: barcodeMap - a reverse of the ballsBarcode variable, to map a product name to a barcode, as I realized that the logic I intended to use does not translate to C++ very well. (I wanted to do a logic that works well with JSON)
  */

  cout << "\n*** RECEIPT ***\nBALLS" << endl;
  cout << "************************************" << endl;

  float subTotal = 0;
  for (const auto &pair : ballsCatalogue){
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
  unordered_map<string, float> ballsCatalogue;
  unordered_map<int, string> ballsBarcodes;
  unordered_map<string, int> barcodeMap;
  unordered_map<string, int> ballsBought;

  do{
    ballsCatalogue = {
      {"Basketball (pair)", 71.98},
      {"Volleyball (pair)", 59.98},
      {"Tennis balls 3x (pair)", 15.98},
      {"Golf balls 12x (pair)", 49.98},
      {"Soccer ball (pair)", 89.98}
    };

    ballsBarcodes = {
      {1, "Basketball (pair)"},
      {2, "Volleyball (pair)"},
      {3, "Tennis balls 3x (pair)"},
      {4, "Golf balls 12x (pair)"},
      {5, "Soccer ball (pair)"}
    };

    barcodeMap = {
      {"Basketball (pair)", 1},
      {"Volleyball (pair)", 2},
      {"Tennis balls 3x (pair)", 3},
      {"Golf balls 12x (pair)", 4},
      {"Soccer ball (pair)", 5}
    };

    ballsBought = {
      {"Basketball (pair)", 0},
      {"Volleyball (pair)", 0},
      {"Tennis balls 3x (pair)", 0},
      {"Golf balls 12x (pair)", 0},
      {"Soccer ball (pair)", 0}
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