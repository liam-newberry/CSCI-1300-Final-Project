#include <iostream>
#include <vector>

#include "Board.h"
#include "Tile.h"
#include "Character.h"
#include "Player.h"
#include "EscapeColors.h"

using namespace std;

// get players' names
void getPlayerNames(Player& player1, Player& player2) {
    cout << "Player 1 name: ";
    cin >> player1.name;

    cout << "Player 2 name: ";
    cin >> player2.name;
}

// check if character input is number between 1 and 5
bool isValidIntChoice(string s, int low, int high) {
    try {
        int x = stoi(s); // convert the string to int
        return x >= low && x <= high; // return input is in range of options
    } catch (const invalid_argument) { // if non number input to stoi
        return false;
    }
}

void getPlayerColor(Player& player) {
    string input;

    cout << "\n\n\n";

    while (true) { // this is used to make the input safe if the input is invalid
        cout << player.name << ", what color would you like?" << endl;

        for (int i = 0; i < 7; i++) {
            cout << EscapeColors::colorString(i + 1, EscapeColors::COLORS[i]) << ", ";
        }
        cout << EscapeColors::colorString(8, EscapeColors::COLORS[7]) << endl;
        cin >> input;

        if (isValidIntChoice(input, 1, 8)) {
            player.color = EscapeColors::COLORS[stoi(input) - 1];
            break;
        } else {
            cout << EscapeColors::colorString("Invalid input", EscapeColors::RED) 
                 << endl << endl; // This makes the error code red
        }
    }
}

// get players' choice of character
void getCharacterChoice(Player& player) {
    vector<Character> characters = make_characters();

    string input;
    int intInput;

    cout << "\n\n\n";

    while (true) { // this is used to make the input safe if the input is invalid
        printHeaders();
        for (int i = 0; i < characters.size(); i++) {
            characters[i].print();
            cout << endl;
        }

        cout << endl 
             << EscapeColors::colorString(player.name, player.color)
             << ", pick your character 1-5: ";
        cin >> input;

        if (isValidIntChoice(input, 1, 5)) {
            player.character = characters[stoi(input) - 1];
            break;
        } else {
            cout << EscapeColors::colorString("Invalid input", EscapeColors::RED) 
                 << endl << endl; // This makes the error code red
        }
    }
}

void getPathChoice(Player& player) {
    string input;

    cout << "\n\n\n";

    while (true) { // this is used to make the input safe if the input is invalid
        cout << "Would you like to do a " 
             << EscapeColors::colorString("Training Fellowship", EscapeColors::GREEN) << " or "
             << EscapeColors::colorString("Direct Lab Assignment", EscapeColors::GREEN) << "?" << endl;
        cout << "A " << EscapeColors::colorString("Training Fellowship", EscapeColors::GREEN)
             << " is a slower path but skills are developed earlier." << endl;
        cout << "A "
             << EscapeColors::colorString("Direct Lab Assignment", EscapeColors::GREEN)
             << " is a faster but riskier path." << endl;

        cout << endl 
             << EscapeColors::colorString(player.name, player.color)
             << ", pick your path 1 or 2: ";
        cin >> input;

        if (isValidIntChoice(input, 1, 2)) {
            player.path = input;
            break;
        } else {
            cout << EscapeColors::colorString("Invalid input", EscapeColors::RED) 
                 << endl << endl; // This makes the error code red
        }
    }
}

// set player names and characters
void intialize_players(Player& player1, Player& player2) {
    getPlayerNames(player1, player2);

    getPlayerColor(player1);
    getPlayerColor(player2);

    getCharacterChoice(player1);
    getCharacterChoice(player2);

    getPathChoice(player1);
    getPathChoice(player2);
}

// main driver function
int main() {
    Player player1, player2;
    intialize_players(player1, player2);

    // Board b;
    // b.displayBoard();

    // while (!b.movePlayer(0)) {}
    // while (!b.movePlayer(1)) {}

    // b.displayBoard();

    return 0;
}