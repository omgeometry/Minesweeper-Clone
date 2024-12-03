// Brian
// Board.cpp defines the Board class
#include "Board.h"
#include "cell.h"
#include <vector>
#include <random>
#include <cstdlib>
#include <time.h>
#include "Fl/Fl_Window.H"
#include <iostream>

using namespace std;

// Takes the location of a placed mine and then increments all nearby Cell's nearbyMines
void Board::updateNearbyMines(int x, int y, int size) {
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            int tempX = x + i;
            int tempY = y + j;

            // Check Bounds
            if ((tempX >= 0 && tempY >= 0) && (tempX < size && tempY < size)) {
                board[tempX][tempY]->incrementNearbyMines();
            }
            
        }
    }
}

// Board constructor definition
Board::Board(int width, int height, int size, int mines) : Fl_Window(width, height, "Minesweeper")
{
    widthPixels = width;
    heightPixels = height;
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

    board.resize(size);
    for(vector<Cell*> row: board){
        row.resize(size);
    }
    for (auto &i : board)
        i.resize(size);
    int squareWidth = widthPixels/size;
    int squareHeight = heightPixels/size;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            board[i][j] = new Cell(i * squareWidth, j * squareHeight, squareWidth, squareHeight);
        }
    }
    // Cell* test = new Cell(50, 50, 50, 50);
    // Fill the board with mines
    // NOTE: Logic may need to be modified to work with completed cell class
    for (int i = 0; i < (size * size); i++) {
        board[i / size][i % size]->setMine(mineLocations[i]);

        // Set Nearby Mines
        if (mineLocations[i]) updateNearbyMines(i / size, i % size, size);
    }
    gameOver = false;
}

// Dig function allows the user to check if a square is a bomb. If it is, return false and end game
void Board::dig(int i, int j) {

// Check Bounds
    if ((i || j < 0) || (i || j >= board.size())) return;

// Check if already revealed
    if (Cell::isHidden(board[i][j])) return;

// If the chosen spot is flagged, return true, do not let the user dig and do not end game
    if (Cell::isFlag(board[i][j])) return;

// If the chosen spot to dig is a mine, return and signal game over
    if (Cell::isMine(board[i][j])) {
        gameOver = true;
        return;
    }
    
    return;
}

// Inverts the flag at the given position
void Board::placeFlag(int i, int j) {

    // Invert flag at given location
    board[i][j]->setFlag();
} 

void Board::printBoard() {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {

            // if (Cell::isHidden(board[i][j])) {
            //     cout << "- ";
            // } else {
            //     cout << "x ";
            // }
            
            if (Cell::isMine(board[i][j])) {
                cout << "X ";
            } else if (Cell::getNearbyMines(board[i][j]) == 0) {
                cout << "  ";
            } else {
                cout << Cell::getNearbyMines(board[i][j]) << ' ';
            }
            
        }
        cout << endl;
    }
}
