// File created by: Liam Newberry & Lyle Stone

#include "EscapeColors.h"

using namespace std;

// helper function to split a color string into start and end escape sequences
void EscapeColors::split(string color, string items[2]) {
    if (color == "") return;

    int i = 0;
    while (true) {
        if (color[i] == ' ') {
            items[0] = color.substr(0,i);
            items[1] = color.substr(i+1);
            return;
        }
        i++;
    }
}

// color a string with a certain escape color
string EscapeColors::colorString(string s, string color) {
    string items[2];
    split(color, items);
    return items[0] + s + items[1];
}

// color an integer with a certain escape color
string EscapeColors::colorString(int s, string color) {
    string items[2];
    split(color, items);
    return items[0] + to_string(s) + items[1];
}

// color a string with a certain color index
string EscapeColors::colorString(string s, int color_index) {
    return colorString(s, COLORS[color_index]);
}

// color an integer with a certain color index
string EscapeColors::colorString(int s, int color_index) {
    return colorString(s, COLORS[color_index]);
}

// define the escape color constants
const string EscapeColors::BLACK   = "\033[30m \033[0m";
const string EscapeColors::RED     = "\033[31m \033[0m";
const string EscapeColors::GREEN   = "\033[32m \033[0m";
const string EscapeColors::YELLOW  = "\033[33m \033[0m";
const string EscapeColors::BLUE    = "\033[34m \033[0m";
const string EscapeColors::MAGENTA = "\033[35m \033[0m";
const string EscapeColors::CYAN    = "\033[36m \033[0m";
const string EscapeColors::WHITE   = "\033[37m \033[0m";

// define the array of color constants
const string EscapeColors::COLORS[8] = {EscapeColors::BLACK,
                                        EscapeColors::RED,
                                        EscapeColors::GREEN,
                                        EscapeColors::YELLOW,
                                        EscapeColors::BLUE,
                                        EscapeColors::MAGENTA,
                                        EscapeColors::CYAN,
                                        EscapeColors::WHITE};