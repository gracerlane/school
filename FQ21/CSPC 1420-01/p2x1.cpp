// Grace Lane
// p2.cpp
// 10-20-2021
// Purpose: This program will open a menu to allow the user to play the game,
//  see the top three scores, or quit. If the user chooses to play, the program
//  will choose a random number between a range of numbers. Then, the user will
//  input a guess until they get the correct number. They can play the game as
//  many times as they would like.

#include <iostream>
#include <string>

using namespace std;

int main()
{
  const int RANGE_MIN = 23;      
  const int RANGE_MAX = 60;      
  int userGuess;                 // user input
  int menuInput = 1;             // user input
  int numToGuess;                // number the user is trying to guess
  int numOfGuesses;              
  int score1 = 100;              // top scores
  int score2 = 200;
  int score3 = 300;    
 
  while (menuInput == 1 || menuInput == 2) {
    cout << endl;	  
    cout << "Game Menu: " << endl;
    cout << "(1) Play" << endl;
    cout << "(2) Top Scores" << endl;
    cout << "(3) Quit" << endl;
    cout << "Choice: ";
    cin >> menuInput;
	cin.ignore();
  
    if (menuInput == 1) {
	  cout << endl;
      cout << "Welcome! This is a number guessing game where you" << endl;
      cout << "will guess a random number between " << RANGE_MIN;
      cout << " and " << RANGE_MAX << "." << endl;
      numOfGuesses = 1;	  
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
	    numOfGuesses++;
      }
	  
	  
	  if (numOfGuesses <= score1) {
		score3 = score2;
		score2 = score1;
        score1 = numOfGuesses;
	  } else if (numOfGuesses <= score2) {
	    score3 = score2;
		score2 = numOfGuesses;
	  } else if (numOfGuesses <= score3){
		  score3 = numOfGuesses;
	  }
	  
	  cout << endl;
      cout << "Correct! It took you " << numOfGuesses << " tries." << endl;
	  cout << "Press enter to return to menu...";
	  cin.get();
    } else if (menuInput == 2) {
	  cout << endl;
  	  cout << "Top Scores:" << endl;
	  cout << "1. " << score1 << endl;
	  cout << "2. " << score2 << endl;
	  cout << "3. " << score3 << endl;
	  cout << "Press enter to return to menu...";
   	  cin.get();
	  
    } else if (menuInput == 3) {
	  cout << endl;
	  cout << "Thank you! Please come again!" << endl;
	  cout << endl;
    }

  }
  
  return 0;
}