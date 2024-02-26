// Grace Lane
// lab15.cpp

#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 75;
const char YES = 'y';
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab15input.dat";

bool findWord(const string list[], int numElements, string target,
              int& targetIndex);
// true if target word is in list

int main()
{
  fstream input;
  string words[MAX];
  string userTarget;
  int count = 0;
  int targetIndex = -1;
  char play = YES;


  input.open(FILENAME);
  if (input.fail()) {
	cout << endl << endl;
    cout << "file error... exiting program... press enter";
	cin.get();
	cout << endl << endl;
	return 0;
  }
  
  while (input >> words[count]) {
	count++;
  }
  
  for (int i = 0; i < count; i++) {
	cout << words[i] << endl;
  }
  
  input.close();

  cout << endl << endl;
  while (tolower(play) == YES) {
    cout << "Enter a word to search for: ";
    cin >> userTarget;
    if (findWord(words, count, userTarget, targetIndex)) {
	  cout << "Your word is at index: " << targetIndex;
    } else {
	  cout << "Your word was not found";
	}
	cout << endl << endl;
	cout << "Play again? y/n ";
	cin >> play;
  }
  
  return 0;
}

bool findWord(const string list[], int numElements, string target,
              int& targetIndex)
{
  int index = 0;
  
  while (index < numElements && list[index] != target) {
	index++;
  }
  
  if (list[index] == target) {
    targetIndex = index;
    return true;
  } else {
    targetIndex = -1;
    return false;
  }
  
}