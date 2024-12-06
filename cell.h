// Cell header/object
// Carter Holtmann

#pragma once
#include <Fl/Fl_Button.H>
#include <unordered_map>
class Cell : public Fl_Button {

public:
  
  Cell(int x, int y, int w, int h);  

  void setMine(bool in); // Used in Board constructor to set mines
  void setFlag(); // Inverts the flag upon user click
  void setHidden(bool in);
  void incrementNearbyMines();
  void setCallback(Fl_Callback* cb, void* data = nullptr);
  
  static bool isFlag(Cell *); // to check flagged spaces
  static bool isMine(Cell *); // check for bomb
  static int getNearbyMines(Cell *); // check if Hidden
  static int* getCoordinates(Cell *);
  void set();

private:
    int handle(int event) override;
    std::unordered_map< int, const char* > labels;
    std::unordered_map< int, Fl_Color > labelColors;
    bool mine = false; // if set true by board.cpp then the cell is a mine
    bool flag = false; // if set true then cell is a flag
    int x;
    int y;
    int nearbyMines; // Num of adjacent mines

};
