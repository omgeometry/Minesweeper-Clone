// Brian Stewart, Carter Holtman, Channing Tan
// 12/3/2024
// Minesweeper Clone
#include <Fl/Fl.H>
#include "Board.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include <type_traits>
using namespace std;

int main() {

    int numOfMines;
    int boardSize;
    int difficulty;

    // Prompt the user to choose their difficulty
    while (true) {
        cout << "Please Enter The Number For Your Difficulty Level:\n1.Beginner (9x9)\n2.Intermediate (12x12)\n3.Expert (16x16)\n4.Extreme (25x25)\n";        
        cin >> difficulty;

        // Beginner 9x9
        if (difficulty == 1) {
            boardSize = 9;
            numOfMines = 10;
            break;
        }

        // Intermediate 12x12
        if (difficulty == 2) {
            boardSize = 12;
            numOfMines = 20;
            break;
        }

        // Expert 16x16
        if (difficulty == 3) {
            boardSize = 16;
            numOfMines = 40;
            break;
        }

        // Extreme 25x25
        if (difficulty == 4) {
            boardSize = 25;
            numOfMines = 99;
            break;
        }
    }

    // Create the board and open the gui
    Board board = Board(800, 800, boardSize, numOfMines);
    board.printBoard();
    board.end();
    board.show();
    return Fl::run();
}
