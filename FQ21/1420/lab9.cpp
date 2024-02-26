// Grace Lane
// lab9.cpp

#include <iostream>
#include <string>

using namespace std;

void welcome();

void goodbye();

int input();
// returns value from MIN to MAX

int summation(int num);
// returns sum from 1 to num

void inputStr(string& st1, string& st2);

void swapStr(string& st1, string& st2);

void output(string st1, string st2);

const int MIN = 5;
const int MAX = 25;

int main() 
{
  int val;
  string sval1, sval2;
  
  cout << endl << endl;
  welcome();
  
  val = input();
  
  cout << "Total sum from 1 to " << val << " is " << summation(val) << endl;
  
  inputStr(sval1, sval2);
 
  output(sval1, sval2);
 
  swapStr(sval1, sval2);
  
  output(sval1, sval2);
  
  goodbye();
  
  cout << endl << endl;

  return 0;
}

void welcome() 
{
  cout << "Welcome to Lab 9!" << endl;
}

int input()
{
  int num;
  
  cout << endl;
  while (num < MIN || num > MAX) {
    cout << "Enter an integer between " << MIN << " and " << MAX << ": ";
    cin >> num;
  }
  cout << endl;
  
  return num;
}

int summation(int num)
{
  int sum = 0;
  
  for (int i = 1; i <= num; i++) {
    sum += i;
  }
  
  return sum;
}

void inputStr(string& st1, string& st2)
{
  cout << endl;
  cout << "Enter two words: ";
  cin >> st1 >> st2;
}

void swapStr(string& st1, string& st2)
{
  string temp = st1;
  st1 = st2;
  st2 = temp;
}

void output(string st1, string st2) {
  cout << "The words in order are: " << st1 << " " << st2 << endl;
}


void goodbye() 
{
  cout << "Goodbye! Thank you for playing!";
}