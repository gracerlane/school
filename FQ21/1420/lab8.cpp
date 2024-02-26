// Grace Lane
// lab8.cpp

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{ 
  const int MIN = 3;
  const int MAX = 9;
  int input = 0;
  
  cout << endl << endl;
  while (input < MIN || input > MAX) {
	cout << "Please enter a number between " << MIN << " and " << MAX << ": ";
    cin >> input;
  }
  
  cout << endl << endl;
  cout << "4. " << input << " lines with 1 ones on the first line, " 
       << "2 twos on the second, etc. to " << input << " " << input << "s"
	   << " on the last line.";
  cout << endl << endl;
  for (int i = 1; i <= input; i++) {
	for (int j = 1; j <= i; j++) {
	  cout << i << ' ';
	}
	cout << endl;
  }
  
  cout << endl << endl;
  cout << "5. the outline of a half-diamond, with " << input
       << " at the widest point.";
  cout << endl << endl;
  for (int i = 1; i <= input; i++) {
	for (int j = 1; j < i; j++) {
	  cout << ' ';
	}
	cout << i;
	cout << endl;
  }
  for (int i = input - 1; i >= 1; i--) {
	for (int j = i; j > 1; j--) {
	  cout << ' ';
	}
	cout << i;
	cout << endl;
  }
  
  cout << endl << endl;
  cout << "6. A full-diamond outline, with " << input << " at the widest "
       << "point.";
  cout << endl << endl;
  
  // first one
  for (int i = 1; i < input; i++) {
	cout << ' ';
  }
  cout << '1' << endl;
  
  // top half
  for (int row = 2; row <= input; row++) {
	for (int spaces = input; spaces > row; spaces--) {
	  cout << ' ';
	}
	cout << row;
	for (int midSpaces = 1; midSpaces <= row * 2 - 3; midSpaces++) {
	  cout << ' ';
	}
	cout << row << endl;
  }
  
  // bottom half
  for (int row = input - 1; row >= 2; row--) {
	for (int spaces = row; spaces < input; spaces++) {
	  cout << ' ';
	}
	cout << row;
	for (int midSpaces = 1; midSpaces <= row * 2 - 3; midSpaces++) {
	  cout << ' ';
	}
	cout << row << endl;
  }
  
  // last one
  for (int i = 1; i < input; i++) {
	cout << ' ';
  }
  cout << '1' << endl;
  
  cout << endl;
  return 0;
}

