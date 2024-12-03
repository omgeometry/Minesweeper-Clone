#include <Fl/Fl.H>
#include "Board.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include <type_traits>
using namespace std;

int main() {
    Board board = Board(800, 800, 10,10);
    board.printBoard();
    board.end();
    board.show();
    return Fl::run();
}
