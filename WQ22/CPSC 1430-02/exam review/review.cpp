#include <iostream>

using namespace std;

int main()
{
	int a = 5;
	int *ptr = &a;

	cout << a << endl;     // value
	cout << *ptr << endl;  // value

	cout << &ptr << endl;  // address of pointer

	cout << ptr << endl;
	cout << &a << endl;

	int arr[3] = {1, 2, 3};
	cout << arr << endl;
	cout << &arr << endl;


	return 0;
}