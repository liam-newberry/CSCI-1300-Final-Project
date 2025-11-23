#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <string>

using namespace std;

class HelperMethods {
public:
    static bool isValidIntChoice(string s, int low, int high);
    static void invalidInput();
    static void clearTerminal();
    static void printHeading(string heading);
    static void clearPrintHeading(string heading);
};

#endif