#include <Fl/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <iostream>

using namespace std;
    
void press_buttons_recursively(int count) {
    //TODO: Implement
}

    // Callback for button1
static void button1_callback(Fl_Widget* widget, void* data) {
    cout << "Button 1 Callback" << endl;
    press_buttons_recursively();  // Trigger the sequence recursively
}

void button2_callback(Fl_Widget* widget, void* data) {
    cout << "Button 2 Callback" << endl;
}

int main() {
    Fl_Window win(200, 300, "Recursive Button Press");
    //Params are x, y, l, h, name
    FL_Button button1(50, 50, 100, 30, "Button 1");
    FL_Button button2(50, 100, 100, 30, "Button 2");
    FL_Button button3(50, 150, 100, 30, "Button 3");

        // Set button callback
    button1.callback(button1_callback, (void*) 0);
    button2.callback(button2_callback, (void*) 0);
    
    win.end();
    win.show();
    return Fl::run();
}   
