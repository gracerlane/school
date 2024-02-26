// Grace Lane
// p2.cpp
// 10-20-2021
// Purpose: The purpose of this program is to play a number guessing game. The
//  program will choose a random number between 0 and 50 and the user will
//  input a guess until they get the correct number. The user can play as many
//  times as they would like.

#include <iostream>
#include <string>

using namespace std;

int main()
{
  const int RANGE_MIN = 12;       
  const int RANGE_MAX = 50;       
  const char YES = 'y';           
  char ans = YES;                 // user input
  int userGuess;                  // user input
  int numToGuess;                 // number the user is trying to guess
  
  
  cout << endl << endl;
  cout << "Welcome! This is a number guessing game where you" << endl;
  cout << "will guess a random number between " << RANGE_MIN;
  cout << " and " << RANGE_MAX << "." << endl;
  cout << endl << endl;
  
  cout << "Would you like to play? (y/n) ";
  cin >> ans;
  cin.ignore();
  
  while (tolower(ans) == YES) {    
    srand(time(0));
    numToGuess = (rand() % (RANGE_MAX - RANGE_MIN + 1)) + RANGE_MIN;
	cout << endl << endl;
    cout << "First guess (" << RANGE_MIN << " and " << RANGE_MAX << "): ";
    cin >> userGuess;
	
    while (userGuess != numToGuess) {
	  if (userGuess > numToGuess) {
	    cout << "Your guess is too high." << endl;
   	  } else {
	    cout << "Your guess is too low." << endl;
	  }
      cout << "Try again (" << RANGE_MIN << " and " << RANGE_MAX << "): ";
	  cin >> userGuess;
	  cin.ignore();
    }
	
    cout << "Correct! Would you like to play again? (y/n) ";
	cin >> ans;
	cin.ignore();
  }
  
  cout << endl << endl;
  cout << "Thank you for playing! Come again!" << endl;
  cout << endl << endl;
  
  return 0;
}
