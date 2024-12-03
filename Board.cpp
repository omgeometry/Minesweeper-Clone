// Brian
// Board.cpp defines the Board class
#include "Board.h"
#include "cell.h"
#include <vector>
#include <random>
#include "Fl/Fl_Window.H"
using namespace std;

// Board constructor definition

Board::Board(int size, int mines) : Fl_Window(widthPixels, heightPixels, boardName)
{

    // To set the mines, I make a vector of booleans of a size equal to the number of mines and set each value to true. This vector is then
    // expanded to the size of the board with all of the new values being false. Then the booleans are shuffled and each one will corrospond to a mine
    vector<bool> mineLocations(mines, true);
    mineLocations.resize(size * size, false);

    srand(time(NULL));

    // Fisher Yates shuffle method
    for (int i = 0; i < (size * size); i++) {
        int j = i + rand() % ((size * size) - i);
        swap(mineLocations[i], mineLocations[j]);
    }

    // Set the board's size before filling it with mines, set all of the Cells to false (No Bomb)
    board.resize(size, vector<Cell()>(size));

    // Fill the board with mines
    // NOTE: Logic may need to be modified to work with completed cell class
    for (int i = 0; i < (size * size); i++) {
        board[i / size][i % size].setMine(mineLocations[i]);
    }
}

// Dig function allows the user to check if a square is a bomb. If it is, return false and end game
bool Board::dig(int i, int j) {

// If the chosen spot is flagged, return true, do not let the user dig and do not end game
    if (Cell::isFlag(board[i][j])) return true;

// If the chosen spot to dig is a mine, return false
    if (Cell::isMine(board[i][j])) return false;
    
    
}

// Inverts the flag at the given position
void Board::placeFlag(int i, int j) {

    // Invert flag at given location
    board[i][j].placeFlag();
} 