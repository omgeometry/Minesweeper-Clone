// Brian
// Board.h - Header file for the board class. Stores all of the cells to facilitate gameplay
#ifndef BOARD_H
#define BOARD_H
#include "cell.h"
#include <vector>
using namespace std;

class Board {
    public:
        Board(int size, int mines);    // Size of board is dictated by the gamemode selected

    private:
        vector< vector< cell > > board;
        
};

#endif