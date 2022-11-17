#ifndef CHIPTRAY_H
#define CHIPTRAY_H
#include "ChipSlot.h"

const int ROWS = 6;
const int COLUMNS = 7;

class ChipTray {
  private:
    ChipSlot chipRack[ROWS][COLUMNS];

    // connect slot pointers methods
    void connectTopLeftCorner(int row, int column);
    void connectTopRightCorner(int row, int column);
    void connectBottomLeftCorner(int row, int column);
    void connectBottomRightCorner(int row, int column);
    void connectLeftEdgeSlotPtrs(int i, int j);
    void connectRightEdgeSlotPtrs(int i, int j);
    void connectTopEdgeSlotPtrs(int i, int j);
    void connectBottomEdgeSlotPtrs(int i, int j);
    void connectAllPtrs(int i, int j);
    void connectInsideSlots();
    void connectEdgeSlots();
    void connectCornerSlots();
    void connectChipSlots();
    
  public:
    ChipSlot* _lastSlot = nullptr;

    ChipTray();
    void displayRack();
    int findLowestVacantRow(int col);
    void insertChip(char color, int col);
    char getChipColorFromSlot(int row, int col);
};
#endif