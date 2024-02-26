// Grace Lane
// lab16.cpp

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 25;
const int MIN = 20;
const int INDEX_WIDTH = 5;
const int VAL_WIDTH = 20;

void swapVal(int& val1, int& val2);
void selectSort(int list[], int numE);
void print(int list[], int numE);

int main()
{
  int arr[MAX];
  int count;
  
  srand(time(0));
  
  cout << endl << endl;
  while (count < MIN || count > MAX) {
	cout << "How many numbers? (" << MIN << " to " << MAX << ") ";
	cin >> count;
  }
    
  for (int i = 0; i < count; i++) {
	arr[i] = rand();
  }
  
  print(arr, count);
  
  selectSort(arr, count);
  
  print(arr, count);
  
  cout << endl << endl;
  
  return 0;
}

void print(int list[], int numE)
{
  cout << endl << endl;
  cout << "Index               Value" << endl;
  for (int i = 0; i < numE; i++) {
    cout << setw(INDEX_WIDTH) << i << setw(VAL_WIDTH) << list[i] << endl;
  }
}

void swapVal(int& val1, int& val2)
{
  int temp = val1;
  val1 = val2;
  val2 = temp;
}
void selectSort(int list[], int numE)
{
  int index;
  for (int i = 0; i < numE - 1; i++) {
	index = i;
	for (int j = i + 1; j < numE; j++) {
	  if (list[j] < list[index]) {
		index = j;
	  }
	}
	if (index != i) {
	  swapVal(list[i], list[index]);
	}
  }
}



