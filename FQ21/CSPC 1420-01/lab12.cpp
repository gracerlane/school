// Grace Lane
// lab12.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX = 50;
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab12input.dat";

void printList(const double arr[], int numElements);
// prints a neatly formatted list, with values printed to three digits of
//  precision

double total(const double arr[], int numElements);
// returns the total sum of all the values

int readFile(double arr[]);
// returns number of values read from file

int main()
{
  double list[MAX];
  int count;
  double sum;

  count = readFile(list);
  if (count == 0) {
	cout << "file error... exiting program... press enter";
	cin.get();
	return 0;
  }
  printList(list, count);
  sum = total(list, count);
  cout << endl << endl;
  cout << "Total: " << sum;
  cout << endl << endl;
  
  return 0;
}

int readFile(double arr[])
{
  int numbers = 0;
  double num;
  ifstream input;
  input.open(FILENAME);
  if (input.fail()) {
	return 0;
  }
  
  cout << endl << endl;
  while (input >> num) {
	  arr[numbers] = num; 
	  numbers++;
  }
  input.close();
  return numbers;
}

void printList(const double arr[], int numElements)
{
  const int INDEX_WIDTH = 5;
  const int NUM_WIDTH = 9;
  const int DECIMALS = 3;
    
  cout << "Index    Value" << endl;
  for (int i = 0; i < numElements; i++) {
	cout << setw(INDEX_WIDTH) << i << setw(NUM_WIDTH) << fixed << showpoint
	     << setprecision(DECIMALS) << arr[i] << endl;
  }
  
}

double total(const double arr[], int numElements)
{
  double sum = 0;
  for (int i = 0; i < numElements; i++) {
	sum += arr[i];
  }
  return sum;
}