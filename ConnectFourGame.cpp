#include "ConnectFourGame.h"
#include "library.h"
#include <iostream>
#include <string>
using namespace std;

ConnectFourGame::ConnectFourGame() {}

Player ConnectFourGame::getPlayer1() {
  return Player1;
}

Player ConnectFourGame::getPlayer2() {
  return Player2;
}

void ConnectFourGame::addPlayers(string Player1Name, string Player2Name) {
  Player1.setupPlayer(Player1Name, 'Y'); 
  Player2.setupPlayer(Player2Name, 'O'); 
}

void ConnectFourGame::promptForPlayers() {
  string p1, p2;
  cout << "Add " << player1Color << " player's name: ";
  cin >> p1;
  cout << "Add " << player2Color << " player's name: ";
  cin >> p2;
  addPlayers(p1, p2);
}

bool ConnectFourGame::playerWins(char color) {
  if (chipTray._lastSlot->fourConseqColors(color))
    return true;
  return false;
}

void ConnectFourGame::playerRounds() {
  for (int i = 0; i < chipsPerPlayer; i++) {
    playerTurn(Player1);
    if (playerWins(Player1.getColor())) {
      announceWinner(Player1.getName()); return;
    }
    playerTurn(Player2);
    if (playerWins(Player2.getColor())) {
      announceWinner(Player2.getName()); return;
    }
  }
}

void ConnectFourGame::startGame() {
  promptForPlayers();
  playerRounds();
}

bool ConnectFourGame::columnVacant(int c) {
  if (chipTray.getChipColorFromSlot(0, c) == ' ')
    return true;
  return false;
}

int ConnectFourGame::getColumnFromUser() {
  int n;
  do {
    cin >> n;
    if (is_0_thru_6(n) && columnVacant(n)) return n;
    else cout << "Invalid number. Please choose again." << endl;
  } while (true);
}

void ConnectFourGame::playerTurn(Player p) {
  displayToConsole();
  promptForChipInsert(p.getName());
  int col = getColumnFromUser();
  chipTray.insertChip(p.getColor(), col);
}

void ConnectFourGame::displayToConsole() {
  chipTray.displayRack();
}