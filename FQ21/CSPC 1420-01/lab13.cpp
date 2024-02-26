// Grace Lane
// lab13.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ROWS = 5;
const int COLS = 8;
const int COL_WIDTH = 5;
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";

void printTable(const int table[][COLS]);

int tableSum(const int table[][COLS]);

int main()
{
  ifstream input;
  int table[ROWS][COLS] = {0};
  input.open(FILENAME);
  int total;
  
  if (input.fail()) {
	cout << "file error... exiting program... press enter";
	cin.get();
	return 0;
  }
  
  for (int r = 0; r < ROWS; r++) {
	for (int c = 0; c < COLS; c++) {
	  input >> table[r][c];         // reads through file and assigns to array
	}
  }
  
  printTable(table);
  
  total = tableSum(table);
  cout << "Total in table is: " << total;
  cout << endl << endl;
  
  return 0;
}

void printTable(const int table[][COLS])
{
  int rowTotal, colTotal;
  cout << endl << endl;
  for (int r = 0; r < ROWS; r++) {
	rowTotal = 0;
	for (int c = 0; c < COLS; c++) {
	  rowTotal += table[r][c];
	  cout << setw(COL_WIDTH) << table[r][c];
	}
	cout << " TOTAL: " << setw(COL_WIDTH) << rowTotal;
	cout << endl;
  }
  
  cout << endl << endl;
  cout << "COLUMN TOTALS:" << endl;
  for (int c = 0; c < COLS; c++) {
	colTotal = 0;
	for (int r = 0; r < ROWS; r++) {
	  colTotal += table[r][c];
	}
	cout << setw(COL_WIDTH) << colTotal;
  }
}

int tableSum(const int table[][COLS])
{
  int tableTotal = 0;
  cout << endl << endl;
  for (int r = 0; r < ROWS; r++) {
	for (int c = 0; c < COLS; c++) {
	  tableTotal += table[r][c];
	}
  }
  return tableTotal;
}