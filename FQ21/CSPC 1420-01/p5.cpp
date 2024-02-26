// Grace Lane
// 11-19-2021
// p5.cpp
// Purpose: The purpose of this program is to allow Everything Electronic!
//  to track their inventory. The program will ask for a filename to use. Then,
//  a menu will come up asking the user if they want to see Inventory Report,
//  Reorder Report, or Quit. The first report will print out the inventory list
//  including the total value of all the items. The other report will print
//  out the items whose current quantity is below their minimum(items that are
//  under stocked). This report will include the total cost to order the
//  items needed. After each report, the user will be brought back to the menu
//  and can choose another report to see or to quit. To see another file, the
//  user will need to quit the program and restart to enter another filename.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX = 150;               // max number of parts

const int NAME_COL = 20;           // for displaying the table
const int MANU_COL = 20;
const int QUAN_COL = 6;
const int MIN_COL = 8;
const int PRICE_COL = 8;
const int VAL_COL = 8;
const int DOLLAR_COL = 2;
const char DOLLAR = '$';

const int SCREEN_HEIGHT = 25;      // for clearing the screen

const int REPORT1 = 1;             // for menu input
const int REPORT2 = 2;
const int QUIT = 3;

struct Item
{
  string name;
  string manufacturer;
  int quantity;
  int min;
  double price;
};

void welcome();
// displays the welcome message

void goodbye();
// displays goodbye message

int menu();
// displays menu and returns valid menu choice;

int readFile(Item storage[]);
// requests file name, reads file, returns number of records

void clrScreen();
// clears the screen approximately 25 lines

void printInventory(const Item storage[], int numE);
// print all inventory information including total value of inventory for all 
//  parts

void printList(const Item storage[], int numE);
// print list of items whose current quantity is below minimum

void swapVal(Item& val1, Item& val2);
// swaps val1 and val2

void selectSort(Item storage[], int numE);
// sorts the array in alphabetical order

int main()
{
  Item list[MAX];
  int numItems = 0;
  int menuInput = 0;
  
  clrScreen();
  welcome();
  
  
  numItems = readFile(list);
  if (numItems == 0) {
    cout << endl << endl;
	cout << "file error... exiting program... press enter...";
	cin.get();
	cout << endl << endl;
	return 0;
  } else {
	selectSort(list, numItems);
    menuInput = menu();
	while (menuInput != QUIT) {
      switch (menuInput)
	  {
		case REPORT1:
          printInventory(list, numItems);
		  break;
        case REPORT2:
		  printList(list, numItems);
		  break;
	  }
	  cout << endl << endl;
	  cout << "Press enter to continue...";
	  cin.get();
	  menuInput = menu();
    }
	goodbye();
  }
  

  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << "           Welcome to Everything Electronic! Inventory Program."
       << endl;
  cout << "      You will be asked to enter a file name, and then decide which"
       << endl;
  cout << "                    report you would like to see." << endl;
  cout << endl << endl;
}

void goodbye()
{
  cout << endl;
  cout << "               Thank you for using this inventory program!" << endl;
  cout << endl;
}

int menu()
{
  int menuInput;
  clrScreen();
  cout << "                         Everything Electronic!" << endl << endl;
  cout << "                         (" << REPORT1 << ") Inventory Report" 
       << endl << endl;
  cout << "                         (" << REPORT2 << ") Reorder Report" 
       << endl << endl;
  cout << "                         (" << QUIT << ") Quit" << endl << endl;
  cout << "                         Choice: ";
  cin >> menuInput;
  cin.ignore();
  return menuInput;
}

void clrScreen()
{
  for (int i = 0; i <= SCREEN_HEIGHT; i++) {
	cout << endl << endl;
  }
}

int readFile(Item storage[])
{
  ifstream input;
  string inputFile;
  int count = 0;
  
  cout << endl << endl;
  cout << "Which file would you like to read? ";
  getline(cin, inputFile);
  
  input.open(inputFile.c_str());
  
  if (input.fail()) {
    return 0;
  } else {
	while (input >> storage[count].name) {
	  input >> storage[count].manufacturer >> storage[count].quantity 
	        >> storage[count].min >> storage[count].price;
	  count++;
    }
  }
  input.close();
  return count;
}

void printInventory(const Item storage[], int numE)
{
  const int SCREEN_WIDTH = 80;
  const char BLANK = ' ';
  const string TITLE = "Inventory Report";
  const string HEADING = "Item                Manufacturer        ";
  const string MORE_HEADINGS = "Quantity   Cost each    Total value";
  const string SPACES = "     ";

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(DOLLAR_COL);
  
  int totalQuantity = 0;
  double totalVal = 0.0;
  
  clrScreen();
  for (unsigned i = 0; i < (SCREEN_WIDTH - TITLE.length())/2; i++) {
	cout << BLANK;
  }
  cout << TITLE << endl;
  cout << HEADING << MORE_HEADINGS << endl;
  
  for (int i = 0; i < numE/2; i++) {
	cout << left << setw(NAME_COL) << storage[i].name
	     << setw(MANU_COL) << storage[i].manufacturer;
	cout << right << setw(QUAN_COL) << storage[i].quantity
	     << setw(DOLLAR_COL) << SPACES << DOLLAR << setw(PRICE_COL) 
		 << storage[i].price << setw(DOLLAR_COL) << SPACES << DOLLAR
		 << setw(VAL_COL) << (storage[i].quantity * storage[i].price)
		 << endl;
		 
	totalQuantity += storage[i].quantity;
	totalVal += (storage[i].quantity * storage[i].price);
  }
  
  cout << endl << endl;
  cout << "Press enter to continue...";
  cin.get();
  cout << endl << endl;
  
  for (int i = numE/2; i < numE; i++) {
	cout << left << setw(NAME_COL) << storage[i].name
	     << setw(MANU_COL) << storage[i].manufacturer;
	cout << right << setw(QUAN_COL) << storage[i].quantity
	     << setw(DOLLAR_COL) << SPACES << DOLLAR << setw(PRICE_COL) 
		 << storage[i].price << setw(DOLLAR_COL) << SPACES << DOLLAR
		 << setw(VAL_COL) << (storage[i].quantity * storage[i].price)
		 << endl;
		 
	totalQuantity += storage[i].quantity;
	totalVal += (storage[i].quantity * storage[i].price);
  }
  cout << endl << endl;
  cout << "Number of different items: " << numE << endl;
  cout << "Total Quantity: " << totalQuantity << endl;
  cout << "Total value of all items: " << DOLLAR << totalVal;
}

void printList(const Item storage[], int numE)
{
  const int SCREEN_WIDTH = 80;
  const char BLANK = ' ';
  const string TITLE = "Reorder Report";
  const string HEADING = "Item                Manufacturer       ";
  const string MORE_HEADINGS = "Quantity  Minimum  Order     Cost";
  const string SPACES = "   ";

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(DOLLAR_COL);
  
  int order = 0;
  int orderTotal = 0;
  double totalCost = 0;
  
  clrScreen();
  for (unsigned i = 0; i < (SCREEN_WIDTH - TITLE.length())/2; i++) {
	cout << BLANK;
  }

  cout << TITLE << endl;
  cout << HEADING << MORE_HEADINGS << endl;
  
  for (int i = 0; i < numE; i++) {
	if (storage[i].quantity < storage[i].min) {
	  cout << left << setw(NAME_COL) << storage[i].name
	       << setw(MANU_COL) << storage[i].manufacturer;
	  cout << right << setw(QUAN_COL) << storage[i].quantity
	       << setw(MIN_COL) << storage[i].min << setw(MIN_COL)
		   << (storage[i].min - storage[i].quantity)
		   << setw(DOLLAR_COL) << SPACES << DOLLAR << setw(PRICE_COL)
		   << (storage[i].price * (storage[i].min - storage[i].quantity))
		   << endl;
	order++;
	orderTotal += (storage[i].min - storage[i].quantity);
	totalCost += (storage[i].price * (storage[i].min - storage[i].quantity));
	}
  }
  cout << endl << endl;
  cout << "Number of different items: " << order << endl;
  cout << "Total number to order: " << orderTotal << endl;
  cout << "Total cost: " << DOLLAR << totalCost;
	  
  
}

void swapVal(Item& val1, Item& val2)
{
  Item temp = val1;
  val1 = val2;
  val2 = temp;
}

void selectSort(Item storage[], int numE)
{
  int index;
  for (int i = 0; i < numE - 1; i++) {
	index = i;
	for (int j = i + 1; j < numE; j++) {
	  if (storage[j].name < storage[index].name) {
		index = j;
	  }
	}
	if (index != i) {
	  swapVal(storage[i], storage[index]);
	}
  }
}