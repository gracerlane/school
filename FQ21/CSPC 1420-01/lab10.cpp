// Grace Lane
// lab10.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string FILENAME = "/home/fac/sreeder/class/cs1420/lab10input.dat";
const int SIZE = 30;
const int COL = 5;

int main()
{
  ifstream input;
  int num;
  int evenNum[SIZE];
  int oddNum[SIZE];
  int negNum[SIZE];
  int evenCount = 0;
  int oddCount = 0;
  int negCount = 0;
  
  input.open(FILENAME);
  
  if (input.fail()) {
	cout << "file error... exiting program... press enter";
	cin.get();
	return 0;
  }
  
  while (input >> num) {
	if (num != 0) {
	  if (num < 0) {
  	    negNum[negCount] = num;
		negCount++;
      } else if (num % 2 == 0) {
        evenNum[evenCount] = num;
        evenCount++;
	  } else {
	    oddNum[oddCount] = num;
	    oddCount++;
	  }
	}
  }
  
  cout << "Negative Numbers:" << endl;
  cout << "Index Value" << endl;
  for (int i = 0; i < negCount; i++) {
	cout << setw(COL) << i;
    cout << setw(COL) << negNum[i] << endl;
  }
  cout << endl << endl;
  cout << "Even Numbers:" << endl;
  cout << "Index Value" << endl;
  for (int i = 0; i < evenCount; i++) {
	cout << setw(COL) << i;
    cout << setw(COL) << evenNum[i] << endl;
  }
  cout << endl << endl;
  cout << "Odd Numbers:" << endl;
  cout << "Index Value" << endl;
  for (int i = 0; i < oddCount; i++) {
	cout << setw(COL) << i;
    cout << setw(COL) << oddNum[i] << endl;
  }
  cout << endl << endl;
  
  input.close();

  return 0;
}