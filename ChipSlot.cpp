#include "ChipSlot.h"

ChipSlot::ChipSlot() {}

bool ChipSlot::hasBlueChip() {
  if (chip.getColor() == 'B')
    return true;
  return false;
}

bool ChipSlot::hasRedChip() {
  if (chip.getColor() == 'R')
    return true;
  return false;
}

bool ChipSlot::isEmpty() {
  if (hasRedChip() || hasBlueChip())
    return false;
  return true;
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