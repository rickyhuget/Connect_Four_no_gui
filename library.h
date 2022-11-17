#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>

void errorMessage(std::string s);
void promptForChipInsert(std::string s);
bool isYellow(char c);
bool isOrange(char c);
void columnMarkers(int columns);
bool is_0_thru_6(int n);
void announceWinner(std::string name);

#endif