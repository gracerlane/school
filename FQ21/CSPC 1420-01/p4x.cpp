// Grace Lane
// p4.cpp
// 11-17-2021
// Purpose: The purpose of this program is to play a small memory matching game
//  that will have MAX_MATCHES for the user to guess. The user can say if they
//  are a beginner or expert and the wait time will change accordingly. They
//  can play as many times as they want. When shown the cards, the user will
//  see stars unless they have already found a match. If there is a match, the
//  card will be an underscore. The program makes sure the user chooses
//  different cards and that the chosen card is still on the board. The program
//  will alternate between two different files.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

const char YES = 'y';           // for user input
const char BEG = 'b';
const char EXP = 'e';

const int MAX_MATCHES = 6;      // number of matches user has to make

const int BEG_SEC = 5;          // wait time
const int EXP_SEC = 2;

const int COL_WIDTH = 2;        // for displaying the board
const int ROWS = 3;         
const int COLS = 4;          
const int BLANKS = 25;          
const char STAR = '*';
const char UNDERSCORE = '_';    
const char SPACE = ' ';
const string OPEN = "[";
const string CLOSE = "]";
//const int SCREEN_HEIGHT = 40;   // what this for??????

const string FILE1 = "/home/fac/sreeder/class/cs1420/p4data1.dat";
const string FILE2 = "/home/fac/sreeder/class/cs1420/p4data2.dat";

void welcome();
// displays welcome message

void displayBoard(char board[][COLS]);
// displays the board

void displayBoard(char board[][COLS], int row1, int col1);
// displays the board with one card flipped

void displayBoard(char board[][COLS], int row1, int col1, int row2, int col2);
// displays the board with two cards flipped over

void wait(int seconds);
// pauses the programs for seconds

void goodbye();
// displays goodbye message

int main()
{
  char play = YES;                       // for user input
  char level;                            
  int row1, row2, col1, col2;

  char gameBoard[ROWS][COLS];            // sets up cards in a board ROWSxCOLS
  
  int matches;                           // matches made by user
  int count;                             // number of turns made by user
  int seconds;                           // wait time
  
  int gameNumber = 1;                    // for choosing file

  welcome();
  
  cout << "Would you like to play? (y/n) ";
  cin >> play;
  cout << endl << endl;
  if (tolower(play) == YES) {
	cout << "Are you a (b)eginner or an (e)xpert? ";
    cin >> level;
	cin.ignore();
	if (tolower(level) == BEG) {
	  seconds = BEG_SEC;
    } else if (tolower(level) == EXP) {
	  seconds = EXP_SEC;
    }
  }
  cout << endl << endl;
  
  // while the user wants to play
  while (tolower(play) == YES) {
	ifstream input;
    matches = 0;
    count = 0;
	
	// alternates between files
	if (gameNumber == 1) {
      input.open(FILE1);
	  if (input.fail()) {
	    cout << endl << endl;
	    cout << "file 1 error... exiting program... press enter";
	    cin.get();
	    cout << endl << endl;
	    return 0;
      }
	  cout << "You will be playing with file 1." << endl;
	  gameNumber = 2;
    } else {
	  input.open(FILE2);
	  if (input.fail()) {
	    cout << endl << endl;
	    cout << "file 2 error... exiting program... press enter";
	    cin.get();
	    cout << endl << endl;
	    return 0;
      }
	  cout << "You will be playing with file 2." << endl;
	  gameNumber = 1;
    }
	
	// reads through file row by row and assigns to array
	for (int r = 0; r < ROWS; r++) {
	  for (int c = 0; c < COLS; c++) {
	    input >> gameBoard[r][c];    
	  }
    }
	
	// while the user hasn't made all the matches
	while (matches < MAX_MATCHES) {
	  wait(seconds);
	  for (int i = 0; i < BLANKS; i++) {
	    cout << endl << endl;
	  }
      displayBoard(gameBoard);
	  cout << "Row? ";
	  cin >> row1;
	  if (row1 > ROWS) {                   // can i do this more efficiently?
		cout << "Try again." << endl;
		cout << "Row? ";
		cin >> row1;
	  }
	  cout << "Col? ";
	  cin >> col1;
	  if (col1 > COLS) {
		cout << "Try again." << endl;
		cout << "Col? ";
		cin >> col1;
	  }
	  while (gameBoard[row1][col1] == UNDERSCORE) {
		cout << endl << endl;
		cout << "That card is gone. Please select another." << endl;
		cout << endl << endl;
		wait(1);
	    for (int i = 0; i < BLANKS; i++) {
	      cout << endl << endl;
	    }
		displayBoard(gameBoard, row1, col1);
		cout << "Row? ";
		cin >> row1;
		if (row1 > ROWS) {
		  cout << "Try again." << endl;
		  cout << "Row? ";
	   	  cin >> row1;
	    }
	    cout << "Col? ";
	    cin >> col1;
	    if (col1 > COLS) {
		  cout << "Try again." << endl;
		  cout << "Col? ";
		  cin >> col1;
	    }
	  }
	  
	  for (int i = 0; i < BLANKS; i++) {
	    cout << endl << endl;
	  }
	  displayBoard(gameBoard, row1, col1);
	  cout << "Row? ";
	  cin >> row2;
	  if (row2 > ROWS) {
		cout << "Try again." << endl;
		cout << "Row? ";
	   	cin >> row2;
	  }
	  cout << "Col? ";
	  cin >> col2;
	  if (col2 > COLS) {
		cout << "Try again." << endl;
		cout << "Col? ";
		cin >> col2;
	  }
	  while (row1 == row2 && col1 == col2) {
		cout << endl << endl;
		cout << "You have already selected this card." << endl;
		cout << "Please enter a different row and col." << endl;
		cout << endl << endl;
		wait(1);
		for (int i = 0; i < BLANKS; i++) {
	      cout << endl << endl;
	    }
	    displayBoard(gameBoard, row1, col1);
		cout << "Row? ";
		cin >> row2;
		if (row2 > ROWS) {
		  cout << "Try again." << endl;
		  cout << "Row? ";
	   	  cin >> row2;
	    }
	    cout << "Col? ";
	    cin >> col2;
	    if (col2 > COLS) {
		  cout << "Try again." << endl;
		  cout << "Col? ";
		  cin >> col2;
	    }
	  }
	  while (gameBoard[row2][col2] == UNDERSCORE) {
		cout << endl << endl;
		cout << "That card is gone. Please select another." << endl;
		cout << endl << endl;
		wait(1);
		for (int i = 0; i < BLANKS; i++) {
	      cout << endl << endl;
	    }
		displayBoard(gameBoard, row1, col1);
		cout << "Row? ";
		cin >> row2;
		if (row2 > ROWS) {
		  cout << "Try again." << endl;
		  cout << "Row? ";
	   	  cin >> row2;
	    }
	    cout << "Col? ";
	    cin >> col2;
	    if (col2 > COLS) {
		  cout << "Try again." << endl;
		  cout << "Col? ";
		  cin >> col2;
	    }
	  }
	  
	  for (int i = 0; i < BLANKS; i++) {
	    cout << endl << endl;
	  }
	  displayBoard(gameBoard, row1, col1, row2, col2);
	  if (gameBoard[row1][col1] == gameBoard[row2][col2]) {
		cout << "It's a match! ";
	    gameBoard[row1][col1] = UNDERSCORE;
	    gameBoard[row2][col2] = UNDERSCORE;
	    matches++;
	  } else {
		cout << "Sorry that's not a match. ";
	  }
	  count++;
	}
	
	wait(seconds);
	for (int i = 0; i < BLANKS; i++) {
	  cout << endl << endl;
	}
	displayBoard(gameBoard, row1, col1, row2, col2);
	cout << "Congrats! You found all the matches!" << endl;
	cout << "It took you " << count << " tries." << endl;
	cout << "Play again? (y/n) ";
	cin >> play;
	cin.ignore();
	cout << endl << endl;
  }
  
  goodbye();
  
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << "Welcome to my memory game! This game has " << ROWS * COLS
       << " cards!" << endl;
  cout << "You will need to get " << MAX_MATCHES << " matches. Good luck!";
  cout << endl << endl;
}

void displayBoard(char board[][COLS])
{
  cout << SPACE;
  for (int c = 0; c < COLS; c++) {
   	cout << setw(COL_WIDTH + 2) << c;
  }
  cout << endl;
  for (int r = 0; r < ROWS; r++) {
	cout << setw(COL_WIDTH) << r;
	for (int c = 0; c < COLS; c++) {
	  if (board[r][c] != UNDERSCORE) {
	  cout << setw(COL_WIDTH) << OPEN << STAR << CLOSE;
	  } else {
	  cout << setw(COL_WIDTH) << OPEN << board[r][c] << CLOSE;
	  }
	}
	cout << endl << endl;
  }
}

void displayBoard(char board[][COLS], int row1, int col1)
{
  cout << SPACE;
  for (int c = 0; c < COLS; c++) {
   	cout << setw(COL_WIDTH + 2) << c;
  }
  cout << endl;
  for (int r = 0; r < ROWS; r++) {
	cout << setw(COL_WIDTH) << r;
	for (int c = 0; c < COLS; c++) {
	  if (r == row1 && c == col1) {
		cout << setw(COL_WIDTH) << OPEN << board[r][c] << CLOSE;
	  } else if (board[r][c] == UNDERSCORE) {
		cout << setw(COL_WIDTH) << OPEN << UNDERSCORE << CLOSE;
	  } else {
		cout << setw(COL_WIDTH) << OPEN << STAR << CLOSE;
	  }
	}
	cout << endl << endl;
  }
}

void displayBoard(char board[][COLS], int row1, int col1, int row2, int col2)
{
  cout << SPACE;
  for (int c = 0; c < COLS; c++) {
   	cout << setw(COL_WIDTH + 2) << c;
  }
  cout << endl;
  for (int r = 0; r < ROWS; r++) {
	cout << setw(COL_WIDTH) << r;
	for (int c = 0; c < COLS; c++) {
	  if (r == row1 && c == col1) {
		cout << setw(COL_WIDTH) << OPEN << board[r][c] << CLOSE;
	  } else if (r == row2 && c == col2) {
		cout << setw(COL_WIDTH) << OPEN << board[r][c] << CLOSE;
	  } else if (board[r][c] == UNDERSCORE) {
		cout << setw(COL_WIDTH) << OPEN << UNDERSCORE << CLOSE;
	  } else {
		cout << setw(COL_WIDTH) << OPEN << STAR << CLOSE;
	  }
	}
	cout << endl << endl;
  }
}

void wait(int seconds)
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;
  while (clock() < endwait) {}
}

void goodbye()
{
  cout << "Thank you for playing! Please come again!";
  cout << endl << endl;
}
