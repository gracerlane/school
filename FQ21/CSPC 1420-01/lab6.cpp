// Grace Lane
// lab6.cpp

#include <iostream>

using namespace std;

int main()
{
  int num1, num2;
  const char YES = 'y';
  char ans = YES;
  
  while (tolower(ans) == YES) {
   	cout << endl << endl;
    cout << "Please enter any two whole numbers (make the first one larger "
	     << "and a multiple of the second): ";
    cin >> num1 >> num2;
	while (num1 % num2 != 0) {
      cout << "Please try again: ";
	  cin >> num1 >> num2;
	}
	
    cout << "The other factor is " << num1 / num2;
    cout << endl << endl;
    cout << "Play again? y/n ";
    cin >> ans;
    cin.ignore();
  }
  
  return 0;
}
