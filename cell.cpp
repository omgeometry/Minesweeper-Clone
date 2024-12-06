// Carter Holtmann
// Check if the cell is a mine or flag


#include "cell.h"
#include "Fl/Fl.H"
#include <string>
#include <stdlib.h>
#include <iostream>
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
    nearbyMines = 0;
    this->x = x;
    this->y = y;
    labelColors.insert(make_pair(1, FL_BLUE));
    labelColors.insert(make_pair(2, FL_GREEN));
    labelColors.insert(make_pair(3, FL_RED)); 
    labelColors.insert(make_pair(4, fl_rgb_color(128,0,128))); //purple
    labelColors.insert(make_pair(5, FL_RED));
    labelColors.insert(make_pair(6, FL_GREEN));
    labelColors.insert(make_pair(7, FL_GREEN));
    labelColors.insert(make_pair(8, FL_GREEN));
    labels.insert(make_pair(1, "1"));
    labels.insert(make_pair(2, "2"));
    labels.insert(make_pair(3, "3"));
    labels.insert(make_pair(4, "4"));
    labels.insert(make_pair(5, "5"));
    labels.insert(make_pair(6, "6"));
    labels.insert(make_pair(7, "7"));
    labels.insert(make_pair(8, "8"));

}; 

// Define handle() in order to differentiate right and left clicks (dig vs. flag)
int Cell::handle(int event) {
    switch (event) {
        case FL_PUSH:  // Mouse button press event
            if (Fl::event_button() == FL_LEFT_MOUSE) {
                return Fl_Button::handle(event);
            } else if (Fl::event_button() == FL_RIGHT_MOUSE) {
                setFlag();
                return 1;
            }
            return 1;  // Event is handled

        default:
            return Fl_Button::handle(event);  // Default handling
    }
}

// Return true if given cell has a flag. Keeps cell from being dug
bool Cell::isFlag(Cell* myCell) {
    if(myCell->flag == true) {
        return true;   
    }
    return false;
}

// Return true if cell is bomb, this function will be called when the player left clicks
bool Cell::isMine(Cell* myCell) {
    if(myCell->mine == true) {
        return true; 
    }
    return false;
}

// Returns the number of nearby mines wich will be displayed if the cell is not a mine or == 0
int Cell::getNearbyMines(Cell* myCell) {
    return myCell->nearbyMines;
}

int* Cell::getCoordinates(Cell* myCell){
    int array[2] = {myCell->x, myCell->y};
    int* pointer = array;
    return pointer;
}

//Reveals the cell by setting the label text and pushing it
void Cell::set(){
    Fl_Button::set();
    if(Cell::isMine(this)){
        this->label("Mine!");
    }else if(Cell::getNearbyMines(this) > 0){
        this->labelcolor(labelColors[Cell::getNearbyMines(this)]);
        this->label(labels[Cell::getNearbyMines(this)]);
    }
}

void Cell::setCallback(Fl_Callback* cb, void* data) {
    this->callback(cb, data);  // Call the base class's callback method
}

// Inverts the flag on click
void Cell::setFlag() {  
    // Checks state of flag and then changes its color accordingly
    if(flag){
        this->color(fl_rgb_color(128, 128, 128));
        this->redraw();
    }else{
        this->color(FL_GREEN);
        this->redraw();
    }
    flag = !flag;
}

// Sets mine state, used in board initialization
void Cell::setMine(bool in) {
    mine = in;
}

// Used to calculate the number that goes in each non-mine Cell
void Cell::incrementNearbyMines() {
    nearbyMines++;  
}
