// Grace Lane
// lab4.cpp

#include <iostream>

using namespace std;

int main()
{
  int num1, num2;
  
  cout << endl << endl;
  cout << "Please enter two whole numbers: ";
  cin >> num1 >> num2;
  
  if(num1 > num2) {
	  if (num1 % num2 == 0) {
        cout << "Yes, and the other factor is " << num1 / num2;
      } else {
	    cout << "No, it is not a multiple";
      }
  } else if (num2 % num1 == 0) {
		  cout << "Yes, and the other factor is " << num2 / num1;
  } else {
      cout << "No, it is not a multiple";
  }
  
  cout << endl << endl;

  return 0;
}