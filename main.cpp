#include <Fl/Fl.H>
#include "cell.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include <type_traits>
using namespace std;

int main() {
    Cell wow = Cell(100,100,50,50);
    
    
    return Fl::run();
}
