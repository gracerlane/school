#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 10; i++) {
		cout << "*" << endl;
	}
	cout << endl;

	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	int target = 5;
	int row = target;
	int pos = target;
	int arr[row][pos];
	for (int rowI = 0; rowI < target; rowI++) {
		// for (int spaces = 0; spaces < (target - (rowI + 1)); spaces++) {
		// 	cout << " ";
		// }
		for (int i = 0; i <= rowI; i++) {
			if (rowI == i || i == 0) {
				arr[rowI][i] = 1;
				cout << arr[rowI][i] << " ";
			} else {
				arr[rowI][i] = arr[rowI - 1][i] + arr[rowI - 1][i - 1];
				cout << arr[rowI][i] << " ";
			}
		}
					cout << endl;

	}


	return 0;
}