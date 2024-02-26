// Grace Lane
// lab7.cpp

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{ 
  const int MIN = 3;
  const int MAX = 9;
  const int COL_WIDTH = 3;
  const char SPACE = ' ';
  int input = 0;
  
  cout << endl;
  cout << "Please enter a number between " << MIN << " and " << MAX << ": ";
  cin >> input;
  while (input < MIN || input > MAX) {
	cout << "Please enter a number between " << MIN << " and " << MAX << ": ";
    cin >> input;
  }
  
  cout << endl << endl;
  cout << "1. " << input << " copies of " << input << " on one line.";
  cout << endl << endl;
  for (int i = 1; i <= input; i++) {
	cout << input;
  }
  
  cout << endl << endl;
  cout << "2. " << input << " lines with a single 1 on each line.";
  cout << endl << endl;
  for (int i = 1; i <= input; i++) {
	cout << '1' << endl;
  }
  
  cout << endl << endl;
  cout << "3. Multiplication table to " << input;
  cout << endl << endl;
  for (int i = 0; i < COL_WIDTH; i++) {
	coud << SPACE;
  }
  for (int col = 1; col <= input; col++) {
	cout << setw(COL_WIDTH) << col;
  }
  cout << endl;
  for (int row = 1; row <= input; row++) {
	cout << row;
	for (int col = 1; col <= input; col++) {
	  cout << setw(COL_WIDTH) << row * col;
	}
	cout << endl;
  }
  
  cout << endl << endl;  
  return 0;
}