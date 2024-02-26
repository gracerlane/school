// Grace Lane
// lab11.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ROWS = 5;
const int COLS = 8;
const int COL_WIDTH = 5;
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";

int main()
{
  ifstream input;
  int arr[ROWS][COLS] = {0};
  int rowTotal;
  int colTotal;
  int tableTotal;  
  input.open(FILENAME);
  
  if (input.fail()) {
	cout << "file error... exiting program... press enter";
	cin.get();
	return 0;
  }
  cout << endl << endl;
  for (int r = 0; r < ROWS; r++) {
	rowTotal = 0;
	for (int c = 0; c < COLS; c++) {
	  input >> arr[r][c];         // reads through file and assigns to array
	  rowTotal += arr[r][c];
	  cout << setw(COL_WIDTH) << arr[r][c];
	}
	cout << " TOTAL: " << setw(COL_WIDTH) << rowTotal;
    tableTotal += rowTotal;
	cout << endl;
  }
  
  cout << endl << endl;
  cout << "COLUMN TOTALS:" << endl;
  for (int c = 0; c < COLS; c++) {
	colTotal = 0;
	for (int r = 0; r < ROWS; r++) {
	  colTotal += arr[r][c];
	}
	cout << setw(COL_WIDTH) << colTotal;
  }
	
  cout << endl << endl;
  cout << "Total in table is: " << tableTotal;
  cout << endl << endl;
  
  return 0;
}