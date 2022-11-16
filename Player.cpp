#include "Player.h" 
#include <string>

Player::Player() {}

Player::Player(std::string name, char c) {
  this->name = name;
  this->color = c;
}

void Player::setupPlayer(std::string name, char c) {
  this->name = name;
  this->color = c;
}

char Player::getColor() {
  return color;
}