#include "ChipTray.h"
#include "library.h"
#include <iostream>
using namespace std;

ChipTray::ChipTray() {
  connectChipSlots();
}

char ChipTray::getChipColorFromSlot(int row, int col) {
  return chipRack[row][col].getChip().getColor();
}

int ChipTray::findLowestVacantRow(int col) {
  for (int row = (ROWS-1); row >= 0; row--) {
    if (chipRack[row][col].isEmpty())
      return row;
  }
  return -1;
}

void ChipTray::insertChip(char color, int col) {
  Chip c(color);
  int row = findLowestVacantRow(col);
  if (isYellow(color)) {
    chipRack[row][col].addChipToSlot(c);
  }
  else if (isOrange(color)) {
    chipRack[row][col].addChipToSlot(c);
  }
  else {
     errorMessage("ChipTray::insertChip(char color, int row, int col)"); return;
  }
  _lastSlot =  &chipRack[row][col];
}

//Display method
void ChipTray::displayRack() {
  cout << endl;
  columnMarkers(COLUMNS);
  for (int row = 0; row <= ROWS-1; row++) {
    cout << " " << row << " ";
    for (int col = 0; col <= COLUMNS-1; col++)
      cout << getChipColorFromSlot(row, col) << " ";
    cout << row << endl;
  }
  columnMarkers(COLUMNS);  
  cout << endl;
}

// connect slot pointers methods
void ChipTray::connectTopLeftCorner(int row, int column) {
  chipRack[row][column].connectToRight(chipRack[row+1][column]);
  chipRack[row][column].connectToBottomMid(chipRack[row+1][column]);
  chipRack[row][column].connectToBottomRight(chipRack[row+1][column+1]);
}

void ChipTray::connectTopRightCorner(int row, int column) {
  chipRack[row][COLUMNS-1].connectToLeft(chipRack[row][column-1]);
  chipRack[row][COLUMNS-1].connectToBottomLeft(chipRack[row+1][column-1]);
  chipRack[row][COLUMNS-1].connectToBottomMid(chipRack[row+1][column]);
}

void ChipTray::connectBottomLeftCorner(int row, int column) {
  chipRack[ROWS-1][column].connectToTopMid(chipRack[row-1][column]);
  chipRack[ROWS-1][column].connectToTopRight(chipRack[row-1][column+1]);
  chipRack[ROWS-1][column].connectToRight(chipRack[row+1][column]);
}

void ChipTray::connectBottomRightCorner(int row, int column) {
  chipRack[ROWS-1][COLUMNS-1].connectToTopLeft(chipRack[row-1][column-1]);
  chipRack[ROWS-1][COLUMNS-1].connectToTopMid(chipRack[row-1][column]);
  chipRack[ROWS-1][COLUMNS-1].connectToLeft(chipRack[row][column-1]);
}

void ChipTray::connectLeftEdgeSlotPtrs(int i, int j) {
  chipRack[i][j].connectToTopMid(chipRack[i-1][j]);
  chipRack[i][j].connectToTopRight(chipRack[i-1][j+1]);
  chipRack[i][j].connectToRight(chipRack[i+1][j]);
  chipRack[i][j].connectToBottomMid(chipRack[i+1][j]);
  chipRack[i][j].connectToBottomRight(chipRack[i+1][j+1]);
}

void ChipTray::connectRightEdgeSlotPtrs(int i, int j) {
  chipRack[i][j].connectToTopLeft(chipRack[i-1][j-1]);
  chipRack[i][j].connectToTopMid(chipRack[i-1][j]);
  chipRack[i][j].connectToLeft(chipRack[i][j-1]);
  chipRack[i][j].connectToBottomLeft(chipRack[i+1][j-1]);
  chipRack[i][j].connectToBottomMid(chipRack[i+1][j]);
}

void ChipTray::connectTopEdgeSlotPtrs(int i, int j) {
  chipRack[i][j].connectToLeft(chipRack[i][j-1]);
  chipRack[i][j].connectToRight(chipRack[i+1][j]);
  chipRack[i][j].connectToBottomLeft(chipRack[i+1][j-1]);
  chipRack[i][j].connectToBottomMid(chipRack[i+1][j]);
  chipRack[i][j].connectToBottomRight(chipRack[i+1][j+1]);
}

void ChipTray::connectBottomEdgeSlotPtrs(int i, int j) {
  chipRack[i][j].connectToTopLeft(chipRack[i-1][j-1]);
  chipRack[i][j].connectToTopMid(chipRack[i-1][j]);
  chipRack[i][j].connectToTopRight(chipRack[i-1][j+1]);
  chipRack[i][j].connectToLeft(chipRack[i][j-1]);
  chipRack[i][j].connectToRight(chipRack[i+1][j]);
}

void ChipTray::connectAllPtrs(int i, int j) {
  chipRack[i][j].connectToTopLeft(chipRack[i-1][j-1]);
  chipRack[i][j].connectToTopMid(chipRack[i-1][j]);
  chipRack[i][j].connectToTopRight(chipRack[i-1][j+1]);
  chipRack[i][j].connectToLeft(chipRack[i][j-1]);
  chipRack[i][j].connectToRight(chipRack[i+1][j]);
  chipRack[i][j].connectToBottomLeft(chipRack[i+1][j-1]);
  chipRack[i][j].connectToBottomMid(chipRack[i+1][j]);
  chipRack[i][j].connectToBottomRight(chipRack[i+1][j+1]);
}

void ChipTray::connectInsideSlots() {
  for (int i = 1; i <= (ROWS-2); i++) {
    for (int j = 1; j <= (COLUMNS-2); j++)
      connectAllPtrs(i, j);
  }
}

void ChipTray::connectEdgeSlots() {
  for (int i = 1; i <= (ROWS-2); i++)
    connectLeftEdgeSlotPtrs(i, 0);
  for (int i = 1; i <= (ROWS-2); i++)
    connectRightEdgeSlotPtrs(i, COLUMNS-1);
  for (int i = 1; i <= (COLUMNS-2); i++)
    connectTopEdgeSlotPtrs(0, i);
  for (int i = 1; i <= (COLUMNS-2); i++)
    connectBottomEdgeSlotPtrs(ROWS-1, i);
}

void ChipTray::connectCornerSlots() {
  int row, column;
  row = 0; column = 0;
  connectTopLeftCorner(row, column);
  row = 0; column = COLUMNS-1;
  connectTopRightCorner(row, column);
  row = ROWS-1; column = 0;
  connectBottomLeftCorner(row, column);
  row = ROWS-1; column = COLUMNS-1;
  connectBottomRightCorner(row, column);
}

void ChipTray::connectChipSlots() {
  connectInsideSlots();
  connectEdgeSlots();
  connectCornerSlots();
}