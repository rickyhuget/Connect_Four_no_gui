#ifndef CONNECTFOURGAME_H
#define CONNECTFOURGAME_H
#include "Player.h"
#include <string>

class ConnectFourGame {
  private:
    Player firstPlayer;
    Player secondPlayer;
    std::string color1 = "red";
    std::string color2 = "blue";

  public:
    ConnectFourGame();
    void addPlayers(std::string firstPlayerName, std::string secondPlayerName);
    void promptForPlayers();
    Player getFirstPlayer();
    Player getSecondPlayer();
    void initiateTurns();
    void startGame();
    void firstPlayerTurn();
    void secondPlayerTurn();
};
#endif