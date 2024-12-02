// Brian
// Board.cpp defines the Board class
#include "Board.h"
#include "cell.h"
#include <vector>
#include <random>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Board constructor definition
Board::Board(int size, int mines) {

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

    // Set the board's size before filling it with mines, set all of the Cells to false (No Mine)
    board.resize(size, vector<Cell>(size));

    // Fill the board with mines
    // NOTE: Logic may need to be modified to work with completed cell class
    for (int i = 0; i < (size * size); i++) {

        board[i / size][i % size].setMine(mineLocations[i]);

    }
}

// Dig function allows the user to check if a square is a mine. If it is, return false and end game
bool Board::dig(int i, int j) {

// If the chosen spot is flagged, return true, do not let the user dig and do not end game
    if (Cell::isFlag(board[i][j])) return true;

// If the chosen spot to dig is a mine, return false
    if (Cell::isMine(board[i][j])) return false;
    
    return true;
}

// Inverts the flag at the given position
void Board::placeFlag(int i, int j) {

    // Invert flag at given location
    board[i][j].setFlag();
} 

// Testing Method, prints board's mine locations
void Board::printBoard() {

    int size = (int)board.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << Cell::isMine(board[i][j]) << ' ';
        }
        cout << endl;
    }
}