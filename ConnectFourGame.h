#ifndef CONNECTFOURGAME_H
#define CONNECTFOURGAME_H
#include "Player.h"
#include "ChipTray.h"
#include "ChipSlot.h"
#include "Chip.h"
#include <string>

class ConnectFourGame {
  private:
    ChipTray chipTray;
    Player Player1;
    Player Player2;
    std::string player1Color = "yellow";
    std::string player2Color = "orange";
    const int chipsPerPlayer = 12;

  public:
    ConnectFourGame();
    void addPlayers(std::string Player1Name, std::string Player2Name);
    void promptForPlayers();
    Player getPlayer1();
    Player getPlayer2();
    void playerRounds();
    bool playerWins(char color);
    void startGame();
    void insertChip(char color, int row, int col);
    bool columnVacant(int c);
    int getColumnFromUser();
    void playerTurn(Player p);
    void displayToConsole();
};
#endif