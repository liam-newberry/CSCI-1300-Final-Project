#include "HelperMethods.h"
#include "EscapeColors.h"

#include <string>
#include <iostream>

using namespace std;

// check if an input is number between low and high
bool HelperMethods::isValidIntChoice(string s, int low, int high) {
    try {
        int x = stoi(s); // convert the string to int
        return x >= low && x <= high; // return input is in range of options
    } catch (const invalid_argument) { // if non number input to stoi
        return false;
    }
}

void HelperMethods::invalidInput() { 
    cout << endl
         << EscapeColors::colorString("Invalid input", EscapeColors::RED) 
         << endl << endl; // This makes the error code red
}

void HelperMethods::clearTerminal() {
    system("clear");
}

void HelperMethods::printHeading(string heading) {
    const int LENGTH = 100;

    string decoration = string(LENGTH, '='); // makes a new string with '=' char 30 times
    decoration = EscapeColors::colorString(decoration, EscapeColors::CYAN);

    int leftPaddingSize = int((LENGTH - heading.size()) / 2);
    string leftPadding = string(leftPaddingSize, ' ');

    cout << endl << decoration << endl << leftPadding
         << EscapeColors::colorString(heading, EscapeColors::MAGENTA)
         << endl << decoration << endl << endl;
}

void HelperMethods::clearPrintHeading(string heading) {
    clearTerminal();
    printHeading(heading);
}