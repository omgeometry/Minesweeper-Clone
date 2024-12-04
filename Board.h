// Brian
// Board.h - Header file for the board class. Stores all of the cells to facilitate gameplay
#ifndef BOARD_H
#define BOARD_H
#include "cell.h"
#include <vector>
#include <unordered_map>
#include "Fl/Fl_Window.H"
using namespace std;

class Board : public Fl_Window{
    public:
        Board(int width, int height, int size, int mines);     // Size of board is dictated by the gamemode selected
        void placeFlag(int i, int j);   // Inverts the flag at the given coordonate (i, j)
        void dig(int i, int j);         // Digs at the given location. If a mine is hit, return false
        void printBoard();
        void updateNearbyMines(int x, int y, int size);
        bool gameOver;

    private:
        void buttonCallback(Cell* button);
        unordered_map< Cell*, bool > visited_cells;
        vector< vector< Cell* > > board;
        int widthPixels;
        int heightPixels;
        int freeSpacesFound; // Number of free spacees the user has found, used for win condition
        int totalFreeSpaces; // Total number of free spaces on the board. Used for win condition
        
};
#endif