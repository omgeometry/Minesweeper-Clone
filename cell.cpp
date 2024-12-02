// Carter Holtmann
// Check if the cell is a mine or flag


#include "cell.h"
using namespace std;

// return true if cell is a flag(meaning cell's flag member got updated to true)
// this function will be called when the player right clicks
Cell::Cell(int x, int y, int w, int h, const char* label)
    : Fl_Button(x, y, w, h, label) {
    Fl_Color grey = fl_rgb_color(128, 128, 128); 
    this->color(grey);
    mine = false; // if set true by board.cpp then the cell is a mine
    flag = false; // if set true then cell is a flag

}; 

bool Cell::isFlag(Cell myCell) {
    
    if(myCell.flag == true) {
        return true;   
    }
    return false;
}


// return true if cell is bomb, this function will be called when the player left clicks
bool Cell::isMine(Cell myCell) {
    
    if(myCell.mine == true) {
        return true; // true will end the game, KABOOM!
    }
    return false;
}

// Inverts the flag
void Cell::setFlag() {  
    flag = !flag;
}

// Sets mine to true, used in board initialization
void Cell::setMine(bool in) {
    mine = in;
}
