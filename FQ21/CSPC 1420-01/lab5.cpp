// Grace Lane
// lab5.cpp

#include <iostream>

using namespace std;

int main()
{
  int num1, num2;
  const char YES = 'y';
  char ans = YES;
  
  while (tolower(ans) == YES) {
	cout << endl << endl;
    cout << "Please enter two whole numbers: ";
    cin >> num1 >> num2;
  
    if(num1 > num2) {
	    if (num1 % num2 == 0) {
          cout << "Yes, it is a multiple and the other factor is " 
		       << num1 / num2 << endl;
        } else {
	      cout << "No, it is not a multiple";
        }
    } else if (num2 % num1 == 0) {
	  cout << "Yes, and the other factor is " << num2 / num1;
    } else {
      cout << "No, it is not a multiple";
    }

    cout << endl << endl;
	cout << "Play again? y/n ";
	cin >> ans;
	cin.ignore();
  }
  
  return 0;
}