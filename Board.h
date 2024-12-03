// Brian
// Board.h - Header file for the board class. Stores all of the cells to facilitate gameplay
#ifndef BOARD_H
#define BOARD_H
#include "cell.h"
#include <vector>
#include "Fl/Fl_Window.H"
using namespace std;

class Board : Fl_Window{
    public:
        Board(int size, int mines);     // Size of board is dictated by the gamemode selected
        void placeFlag(int i, int j);   // Inverts the flag at the given coordonate (i, j)
        bool dig(int i, int j);         // Digs at the given location. If a mine is hit, return false
        void printBoard();

    private:
        vector< vector< Cell > > board;
        int widthPixels = 800;
        int heightPixels = 800;
        char* boardName = "Minesweeper";
        
};

#endif