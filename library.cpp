#include "library.h"
#include <iostream>
#include <string>
using namespace std;

void errorMessage(string s) {
  cout << " Error in \'" << s << "\' method." << endl;
}

void promptForChipInsert(string s) {
  cout << s << "\'s turn." << endl;
  cout << "Which column would you like to insert your chip?" << endl;
  cout << "Enter a number (0 through 6). ";
}

bool isYellow(char c) {
  if (c == 'Y')
    return true;
  return false;
}

bool isOrange(char c) {
  if (c == 'O')
    return true;
  return false;
}

void columnMarkers(int columns) {
  cout << "   ";
  for (int col = 0; col <= columns-1; col++)
    cout << col << " ";
  cout << endl;
}

bool is_0_thru_6(int n) {
  if ((0 <= n) && (n <= 6))
    return true;
  return false;
}

void announceWinner(string name) {
  cout << "Game over. " << name << " wins!" << endl;
}