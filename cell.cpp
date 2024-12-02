// Carter Holtmann
// Check if the cell is a mine or flag
#include "cell.h"
using namespace std;

// return true if the cell has a flag, false if it does not
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
