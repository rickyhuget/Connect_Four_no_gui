#ifndef CHIPSLOT_H
#define CHIPSLOT_H
#include "Chip.h"

class ChipSlot {
  private:
    Chip chip = Chip(' ');
    ChipSlot* ptrTopLeft = nullptr;
    ChipSlot* ptrTopMid = nullptr;
    ChipSlot* ptrTopRight = nullptr;
    ChipSlot* ptrLeft = nullptr;
    ChipSlot* ptrRight = nullptr;
    ChipSlot* ptrBottomLeft = nullptr;
    ChipSlot* ptrBottomMid = nullptr;
    ChipSlot* ptrBottomRight = nullptr;

  public:
    ChipSlot();
    bool hasPlayer1Chip();
    bool hasPlayer2Chip();
    bool isEmpty();
    Chip getChip();
    char getChipColor();
    void addChipToSlot(Chip c);

    ChipSlot* getTopLeft();
    ChipSlot* getTopMid();
    ChipSlot* getTopRight();
    ChipSlot* getLeft();
    ChipSlot* getRight();
    ChipSlot* getBottomLeft();
    ChipSlot* getBottomMid();
    ChipSlot* getBottomRight();

    void connectToTopLeft(ChipSlot cs);
    void connectToTopMid(ChipSlot cs);
    void connectToTopRight(ChipSlot cs);
    void connectToLeft(ChipSlot cs);
    void connectToRight(ChipSlot cs);
    void connectToBottomLeft(ChipSlot cs);
    void connectToBottomMid(ChipSlot cs);
    void connectToBottomRight(ChipSlot cs);

    int topLeftDirection(char color);
    int topMidDirection(char color);
    int topRightDirection(char color);
    int leftDirection(char color);
    int rightDirection(char color);
    int bottomLeftDirection(char color);
    int bottomMidDirection(char color);
    int bottomRightDirection(char color);

    bool fourConseqColors(char color);
};
#endif