// Grace Lane
// lab2.cpp

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string word;
  int firstNum, secondNum;
  double thirdNum, fourthNum;
  
  cout << endl << endl;
  cout << "Enter any word: ";
  getline(cin, word);
  cout << "You entered " << word << endl;
  cout << endl << endl;
  
  cout << "Enter a whole number: ";
  cin >> firstNum;
  
  cout << "Enter another whole number: ";
  cin >> secondNum;
  
  cout << endl << endl;
  cout << firstNum << " divided by " << secondNum << " equals " << endl;
  cout << (firstNum / secondNum) << endl;
  cout << "The remainder of dividing " << firstNum << " by " << endl;
  cout << secondNum << " is " << (firstNum % secondNum) << endl;
  cout << endl << endl;
  
  cout << "Enter a number that contains a decimal: ";
  cin >> thirdNum;
  
  cout << "Enter another number that contains a decimal: ";
  cin >> fourthNum;
  
  cout << thirdNum << " divided by " << fourthNum << " equals " << endl;
  cout << thirdNum / fourthNum;
  cout << endl << endl;
  
  return 0;
}