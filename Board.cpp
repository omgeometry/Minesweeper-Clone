// Brian
// Board.cpp defines the Board class
#include "Board.h"
#include "cell.h"
#include <vector>
#include <random>
#include <cstdlib>
#include <time.h>
#include "Fl/Fl_Window.H"
#include "Fl/fl_ask.H"
#include "Fl/fl_message.H"
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
void Board::dig(int i, int j) {

    // Check Bounds
    if(i >= board.size() || j >= board.size() || i < 0 || j < 0){
        return;
    }
    if(visited_cells[board[i][j]]){
        return;
    }else{
        visited_cells.insert_or_assign(board[i][j], true);
    }
    if(Cell::isFlag(board[i][j])){
        return;
    }

    if (Cell::isMine(board[i][j])) {
        cout << "The game is over" << endl;
        gameOver = true;
        board[i][j]->set();

        fl_message_title("Actually terrible!");
        fl_message("Cheeks at minesweeper fr!");
        std::exit(0);
    }
    if(Cell::getNearbyMines(board[i][j]) > 0){
        board[i][j]->set();
        // Incase a Cell next to a mine is clicked, include win condition here aswell.
        freeSpacesFound++;
        if (freeSpacesFound >= totalFreeSpaces) {
            // Print winning message and quit program
            fl_message_title("Youre a winner!");
            fl_message("Congratulations!");
            std::exit(0);
        }
        return;
    }
    
    // Recursively call dig() to reveal additional spaces     
    dig(i-1, j);
    dig(i+1, j);
    dig(i, j-1);
    dig(i, j+1);

    board[i][j]->set();

    freeSpacesFound++;
    // Count total number of free spaces the user has found and then check win condition   
    if (freeSpacesFound >= totalFreeSpaces) {
        fl_message_title("Youre a winner!");
        fl_message("Congratulations!");
        std::exit(0);
    }

    return;
}

// Board constructor definition
Board::Board(int width, int height, int size, int mines) : Fl_Window(width, height, "Minesweeper")
{
    widthPixels = width;
    heightPixels = height;
    totalFreeSpaces = size * size - mines;
    freeSpacesFound = 0;
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
            int values[2] = {i, j};
            visited_cells.insert_or_assign(board[i][j], false);
            board[i][j]->setCallback([](Fl_Widget* widget, void* data) {
            Board* window = (Board*)data;  // Get the 'this' pointer via data
            Cell* button = dynamic_cast<Cell*>(widget);
            window->buttonCallback(button);  // Call the member function 'dig'
        }, this);
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

void Board::buttonCallback(Cell* button){
    int* coordinates = Cell::getCoordinates(button);
    int i = coordinates[0] * board.size()/widthPixels;
    int j = coordinates[1] * board.size()/widthPixels;
    dig(i, j);
}

// Inverts the flag at the given position
void Board::placeFlag(int i, int j) {

    // Invert flag at given location
    board[i][j]->setFlag();
} 

// Displays the solution to the board in the terminal
void Board::printBoard() {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {

            if (Cell::isMine(board[j][i])) {
                cout << "X ";
            } else if (Cell::getNearbyMines(board[j][i]) == 0) {
                cout << "  ";
            } else {
                cout << Cell::getNearbyMines(board[j][i]) << ' ';
            }
            
        }
        cout << endl;
    }
}
