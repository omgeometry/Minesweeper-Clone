// Cell header/object
// Carter Holtmann

#pragma once

class Cell {

public:
  
  Cell() {

    mine = false; // if set true by board.cpp then the cell is a mine
    flag = false; // if set true then cell is a flag

  }; 

  void setMine(bool mine); // Used in Board constructor to set mines
  void setFlag(); // Inverts the flag upon user click
  
  void isFlag(Cell); // to check flagged spaces
  bool isMine(Cell); // check for bomb


private:

    bool mine = false; // if set true by board.cpp then the cell is a mine
    bool flag = false; // if set true then cell is a flag

};