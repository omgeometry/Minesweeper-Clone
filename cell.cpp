// Carter Holtmann
// Check if the cell is a mine or flag


#pragma once
#include "cell.h"
using namespace std;

// return true if cell is a flag(meaning cell's flag member got updated to true)
// this function will be called when the player right clicks
void Cell::isFlag(Cell myCell) {
    
    if(myCell.flag == false) {
        myCell.flag == true; // if cell is not a flag, make it one on right click, otherwise do nothing and continue
    }
}

// return true if cell is bomb, this function will be called when the player left clicks
bool Cell::isMine(Cell myCell) {
    
    if(myCell.mine == true) {
        return true; // true will end the game, KABOOM!
    }
    return false;
}