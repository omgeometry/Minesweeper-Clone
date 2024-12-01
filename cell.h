// Cell object
// Project Minesweeper Clone

#pragma once

class Cell {

public:
  // take in bool and depending on left or right click, do different things
  Cell(bool k); // constructor, bool true = bomb/ false = not bomb 

private:

  bool isFlag(); // to check flagged spaces
  bool isBomb(); // check for bomb
};