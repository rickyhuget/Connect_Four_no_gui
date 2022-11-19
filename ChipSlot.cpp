#include "ChipSlot.h"

ChipSlot::ChipSlot() {}

bool ChipSlot::hasPlayer1Chip() {
  if (chip.getColor() == 'Y')
    return true;
  return false;
}

bool ChipSlot::hasPlayer2Chip() {
  if (chip.getColor() == 'O')
    return true;
  return false;
}

bool ChipSlot::isEmpty() {
  if (hasPlayer1Chip() || hasPlayer2Chip())
    return false;
  return true;
}

void ChipSlot::addChipToSlot(Chip c) {
  chip = c;
}

char ChipSlot::getChipColor() {
  return chip.getColor();
}

Chip ChipSlot::getChip() {return chip;}

ChipSlot* ChipSlot::getTopLeft() {return ptrTopLeft;}
ChipSlot* ChipSlot::getTopMid() {return ptrTopMid;}
ChipSlot* ChipSlot::getTopRight() {return ptrTopRight;}
ChipSlot* ChipSlot::getLeft() {return ptrLeft;}
ChipSlot* ChipSlot::getRight() {return ptrRight;}
ChipSlot* ChipSlot::getBottomLeft() {return ptrBottomLeft;}
ChipSlot* ChipSlot::getBottomMid() {return ptrBottomMid;}
ChipSlot* ChipSlot::getBottomRight() {return ptrBottomRight;}

void ChipSlot::connectToTopLeft(ChipSlot cs) {ptrTopLeft = &cs;}
void ChipSlot::connectToTopMid(ChipSlot cs) {ptrTopMid = &cs;}
void ChipSlot::connectToTopRight(ChipSlot cs) {ptrTopRight = &cs;}
void ChipSlot::connectToLeft(ChipSlot cs) {ptrLeft = &cs;}
void ChipSlot::connectToRight(ChipSlot cs) {ptrRight = &cs;}
void ChipSlot::connectToBottomLeft(ChipSlot cs) {ptrBottomLeft = &cs;}
void ChipSlot::connectToBottomMid(ChipSlot cs) {ptrBottomMid = &cs;}
void ChipSlot::connectToBottomRight(ChipSlot cs) {ptrBottomRight = &cs;}

int ChipSlot::topLeftDirection(char color) {
  if (getTopLeft() == nullptr) {return 0;}
  if (getTopLeft()->getChipColor() == color) {return 1 + getTopLeft()->topLeftDirection(color);}
  else {return 0;}
}
int ChipSlot::topRightDirection(char color) {
  if (getTopRight() == nullptr) {return 0;}
  if (getTopRight()->getChipColor() == color) {return 1 + getTopRight()->topRightDirection(color);}
  else {return 0;}
}
int ChipSlot::leftDirection(char color) {
  if (getLeft() == nullptr) {return 0;}
  if (getLeft()->getChipColor() == color) {return 1 + getLeft()->leftDirection(color);}
  else {return 0;}
}
int ChipSlot::rightDirection(char color) {
  if (getRight() == nullptr) {return 0;} 
  if (getRight()->getChipColor() == color) {return 1 + getRight()->rightDirection(color);}
  else {return 0;} 
}
int ChipSlot::bottomLeftDirection(char color) {
  if (getBottomLeft() == nullptr) {return 0;}
  if (getBottomLeft()->getChipColor() == color) {return 1 + getBottomLeft()->bottomLeftDirection(color);}
  else {return 0;}
}

int ChipSlot::bottomMidDirection(char color) {
  if (getBottomMid() == nullptr) {return 0;} 
  if (getBottomMid()->getChipColor() == color) {return (1 + getBottomMid()->bottomMidDirection(color));}
  else {return 0;}
}

int ChipSlot::bottomRightDirection(char color) {
  if (getBottomRight() == nullptr) {return 0;}
  if (getBottomRight()->getChipColor() == color) {return 1 + getBottomRight()->bottomRightDirection(color);}
  else {return 0;}
}

bool ChipSlot::fourConseqColors(char color) {
  if (topLeftDirection(color) >= 3)
    return true;
  if (topRightDirection(color) >= 3)
    return true;
  if (leftDirection(color) >= 3)
    return true;
  if (rightDirection(color) >= 3)
    return true;
  if (bottomLeftDirection(color) >= 3)
    return true;
  if (bottomMidDirection(color) >= 3)
    return true;
  if (bottomRightDirection(color) >= 3)
    return true;
  
  return false;
}