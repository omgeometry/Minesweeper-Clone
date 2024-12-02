// Cell header/object
// Carter Holtmann

#pragma once

class Cell {

public:
  
  Cell() {

    mine = false; // if set true by board.cpp then the cell is a mine
    flag = false; // if set true then cell is a flag

  }; 

  void setMine(bool in); // Used in Board constructor to set mines
  void setFlag(); // Inverts the flag upon user click

  static bool isFlag(Cell); // to check flagged spaces
  static bool isMine(Cell); // check for bomb



private:

    bool mine = false; // if set true by board.cpp then the cell is a mine
    bool flag = false; // if set true then cell is a flag

};