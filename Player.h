#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
  private:
    std::string name;
    char color;

  public:
    Player();
    Player(std::string name, char c);
    void setupPlayer(std::string name, char c);
    std::string getName();
    char getColor();
};
#endif