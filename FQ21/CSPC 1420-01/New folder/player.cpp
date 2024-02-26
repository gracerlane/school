// exam review
// lab5
// player.cpp

#include <iostream>
#include <string>

using namespace std;

class Player
{
	private:
		string name;
		int *arr;
	public:
		Player(string, int);
		~Player();
		void setNum(int, int);
		int getNum(int) const;
}

Player::Player(string n, int num) 
{
	name = n;
	arr = new int [num]; 
}

Player::~Player()
{
	delete [] arr;
}

void Player::setNum(int num, int index)
{
	arr[index] = num;
}

int Player::getNum(int index) const
{
	return arr[index];
}

int main()
{
	int totalGames;
	string name1;
	int t1 = 0;
	string name2;
	int t2 = 0;
	int input;
	
	cout << "total games? ";
	cin >> totalGames;
	cout << endl << endl;
	
	cout << "Please enter the name of first player:";
	cin >> name1;
	Player p1 (name1, totalGames);
	for (int i = 0; i < totalGames; i++ {
		cout << "Please enter a number at index " << i + 1 << " for player " << p1 << ":"
		cin >> input;
		t1 += input;
		p1.setNum(input, i);
		cout << endl;
	}
	
	for (int i = 0; i < totalGames; i++) {
		cout << name1 << " selects: " << p1.getNum(i) << " ";
	}
	cout << endl;
	
	cout << "Please enter the name of first player:";
	cin >> name2;
	Player p2 (name2, totalGames);
	for (int i = 0; i < totalGames; i++ {
		cout << "Please enter a number at index " << i + 1 << " for player " << p2 << ":"
		cin >> input;
		t2 += input;
		p2.setNum(input, i);
		cout << endl;
	}
	
	for (int i = 0; i < totalGames; i++) {
		cout << name2 << " selects: " << p2.getNum(i) << " ";
	}
	cout << endl;
	
	if (t1 > t2) {
		cout << p1 << " wins" << endl;
	} else if (t2 > t1) {
		cout << p2 << " wins" << endl;
	} else {
		cout << "draw" << endl;
	}
	
	
	return 0;
}