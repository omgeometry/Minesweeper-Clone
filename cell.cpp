// Carter Holtmann
// Check if the cell is a mine or flag


#include "cell.h"
using namespace std;

// return true if cell is a flag(meaning cell's flag member got updated to true)
// this function will be called when the player right clicks
Cell::Cell(int x, int y, int w, int h)
    : Fl_Button(x, y, w, h, 0) {
    Fl_Color grey = fl_rgb_color(128, 128, 128); 
    this->color(grey);
    mine = false; // if set true by board.cpp then the cell is a mine
    flag = false; // if set true then cell is a flag
    hidden = true;
    nearbyMines = 0;

}; 

bool Cell::isFlag(Cell* myCell) {
    
    if(myCell->flag == true) {
        return true;   
    }
    return false;
}


// return true if cell is bomb, this function will be called when the player left clicks
bool Cell::isMine(Cell* myCell) {
    
    if(myCell->mine == true) {
        return true; // true will end the game, KABOOM!
    }
    return false;
}

// return true if cell is bomb, this function will be called when the player left clicks
bool Cell::isHidden(Cell* myCell) {
    
    if(myCell->hidden == true) {
        return true; // true will end the game, KABOOM!
    }
    return false;
}

int Cell::getNearbyMines(Cell* myCell) {
    return myCell->nearbyMines;
}

// Inverts the flag
void Cell::set(){
    set();
    if(this->isMine){
        this->label("Mine!");
    }else{
        this->label((char*) surroundingMines + '0');
    }
}
void Cell::setFlag() {  
    flag = !flag;
}

// Sets mine to true, used in board initialization
void Cell::setMine(bool in) {
    mine = in;
}

void Cell::setHidden(bool in) {
    hidden = in;
}

void Cell::incrementNearbyMines() {
    nearbyMines++;
}
