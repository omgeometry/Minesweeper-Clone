// Cell header/object
// Carter Holtmann

#pragma once
#include <Fl/Fl_Button.H>
class Cell : Fl_Button {

public:
  
  Cell(int x, int y, int w, int h);  

  void setMine(bool in); // Used in Board constructor to set mines
  void setFlag(); // Inverts the flag upon user click
  void setHidden(bool in);
  void incrementNearbyMines();

  static bool isFlag(Cell *); // to check flagged spaces
  static bool isMine(Cell *); // check for bomb
  static bool isHidden(Cell *); // check if Hidden
  static int getNearbyMines(Cell *); // check if Hidden



private:

    bool mine = false; // if set true by board.cpp then the cell is a mine
    bool flag = false; // if set true then cell is a flag
    bool hidden = true;
    int nearbyMines; // Num of adjacent mines

};
