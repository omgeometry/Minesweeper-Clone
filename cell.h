// Cell header/object
// Carter Holtmann

#pragma once
#include <Fl/Fl_Button.H>
class Cell {

public:
  
  Cell(int x, int y, int w, int h, const char* label = 0);  

  void setMine(bool in); // Used in Board constructor to set mines
  void setFlag(); // Inverts the flag upon user click

  static bool isFlag(Cell); // to check flagged spaces
  static bool isMine(Cell); // check for bomb



private:

    bool mine = false; // if set true by board.cpp then the cell is a mine
    bool flag = false; // if set true then cell is a flag

};