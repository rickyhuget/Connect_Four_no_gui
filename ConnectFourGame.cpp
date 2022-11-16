#include "ConnectFourGame.h"
#include <iostream>
#include <string>
using namespace std;

ConnectFourGame::ConnectFourGame() {}

Player ConnectFourGame::getFirstPlayer() {
  return firstPlayer;
}

Player ConnectFourGame::getSecondPlayer() {
  return secondPlayer;
}

void ConnectFourGame::addPlayers(string firstPlayerName, string secondPlayerName) {
  firstPlayer.setupPlayer(firstPlayerName, 'R'); 
  secondPlayer.setupPlayer(secondPlayerName, 'B'); 
}

void ConnectFourGame::promptForPlayers() {
  string p1, p2;
  cout << "Add " << color1 << " player's name: ";
  cin >> p1;
  cout << "Add " << color2 << " player's name: ";
  cin >> p2;
  addPlayers(p1, p2);
}

void ConnectFourGame::initiateTurns() {
  for (int i = 0; i < 12; i++) {
    firstPlayerTurn();
    secondPlayerTurn();
  }
}

void ConnectFourGame::startGame() {
  promptForPlayers();
  initiateTurns();
}

void ConnectFourGame::firstPlayerTurn() {
  
}

void ConnectFourGame::secondPlayerTurn() {
  
}