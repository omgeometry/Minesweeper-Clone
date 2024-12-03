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
    this->x = x;
    this->y = y;
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

int* Cell::getCoordinates(Cell* myCell){
    int array[2] = {myCell->x, myCell->y};
    int* pointer = array;
    return pointer;
}

// Inverts the flag
void Cell::set(){
    set();
    if(this->isMine){
        this->label("Mine!");
    }else{
        this->label((char*) nearbyMines + '0');
    }
}

void Cell::setCallback(Fl_Callback* cb, void* data) {
    this->callback(cb, data);  // Call the base class's callback method
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
