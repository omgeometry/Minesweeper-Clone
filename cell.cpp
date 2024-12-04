// Carter Holtmann
// Check if the cell is a mine or flag


#include "cell.h"
#include <string>
#include <stdlib.h>
#include <unordered_map>
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
    labels.insert(make_pair(1, "1"));
    labels.insert(make_pair(2, "2"));
    labels.insert(make_pair(3, "3"));
    labels.insert(make_pair(4, "4"));
    labels.insert(make_pair(5, "5"));
    labels.insert(make_pair(6, "6"));
    labels.insert(make_pair(7, "7"));
    labels.insert(make_pair(8, "8"));

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
    Fl_Button::set();
    if(Cell::isMine(this)){
        this->label("Mine!");
    }else if(Cell::getNearbyMines(this) > 0){
        this->label(labels[Cell::getNearbyMines(this)]);
    }
}

void Cell::setCallback(Fl_Callback* cb, void* data) {
    this->callback(cb, data);  // Call the base class's callback method
}


void Cell::setFlag() {  
    Cell::color(FL_GREEN);
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
