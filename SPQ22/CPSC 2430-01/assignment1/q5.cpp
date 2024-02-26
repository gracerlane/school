#include <iostream>
using namespace std;

int rec_sum(int n)
{
	if (n <= 0) {
		return -1;
	} else if (n == 1) {
		return 1;
	} else {
		return n + rec_sum(n-1);
	}
}

int iter_sum(int n) {
	int t = 0;
	if (n <= 0) {
		return -1;
	} 
	for (int i = n; i > 0; i--) {
		t += i;
	}
	return t;
}



int main() 
{
	cout << "i: " << iter_sum(1) << endl;
	cout << "r: " << rec_sum(1) << endl;
	return 0;
}
