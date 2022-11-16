#ifndef CHIPTRAY_H
#define CHIPTRAY_H
#include "ChipSlot.h"

class ChipTray {
  private:
    ChipSlot chipRack[7][6];

    void connectChipSlots();
    void connectCornerSlots();
    void connectSideSlots();
    void connectInsideSlots();

  public:
    ChipTray();
    void insertChip(int row, int col);
    char getChipColorFromSlot(int row, int col);
    void checkEndState();
};
#endif