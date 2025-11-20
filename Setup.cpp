#include <iostream>
#include <iomanip>
#include <vector>

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

// get the player's color; used every time they're name is displayed
void getPlayerColor(Player& player, string taken) {
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
            if (player.color == taken) {
                cout << EscapeColors::colorString("Color already taken", EscapeColors::RED) 
                 << endl << endl; // This makes the error code red
            } else {
                player.name = EscapeColors::colorString(player.name, player.color);
                break;
            }
        } else {
            cout << EscapeColors::colorString("Invalid input", EscapeColors::RED) 
                 << endl << endl; // This makes the error code red
        }
    }
}

// get players' choice of character
void getCharacterChoice(Player& player) {
    vector<Character> characters = makeCharacters();

    string input;
    int intInput;

    cout << "\n\n\n";

    while (true) { // this is used to make the input safe if the input is invalid
        printHeaders();
        for (int i = 0; i < characters.size(); i++) {
            characters[i].print();
            cout << endl;
        }

        cout << endl << player.name << ", pick your character 1-5: ";
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

        cout << endl << player.name << ", pick your path 1 or 2: ";
        cin >> input;

        if (isValidIntChoice(input, 1, 2)) {
            player.path = input == "1" ? "Training Fellowship" : "Direct Lab Assignment";
            break;
        } else {
            cout << EscapeColors::colorString("Invalid input", EscapeColors::RED) 
                 << endl << endl; // This makes the error code red
        }
    }
}

void getAdvisorChoice(Player& player) {
    vector<Advisor> advisors = makeAdvisors();

    string input;
    int intInput;

    cout << "\n\n\n";

    while (true) { // this is used to make the input safe if the input is invalid
        for (int i = 0; i < advisors.size(); i++) {
            cout << left << setw(25) << EscapeColors::colorString(advisors[i].name, EscapeColors::MAGENTA) + ": "
                 << advisors[i].description << endl;
        }

        cout << endl << player.name << ", pick your advisor 1-5: ";
        cin >> input;

        if (isValidIntChoice(input, 1, 5)) {
            player.advisor = advisors[stoi(input) - 1];
            break;
        } else {
            cout << EscapeColors::colorString("Invalid input", EscapeColors::RED) 
                 << endl << endl; // This makes the error code red
        }
    }
}

void evaluatePathChoice(Player& player) {
    if (player.path == "Training Fellowship") {
        player.character.changeDiscoveryPoints(-5000);
        player.character.changeAccuracy(500);
        player.character.changeEfficiency(500);
        player.character.changeInsight(1000);

        getAdvisorChoice(player);
    } else if (player.path == "Direct Lab Assignment") {
        player.character.changeDiscoveryPoints(5000);
        player.character.changeAccuracy(200);
        player.character.changeEfficiency(200);
        player.character.changeInsight(200);
    }
}

// set player names and characters
void intialize_players(Player& player1, Player& player2) {
    getPlayerNames(player1, player2);

    getPlayerColor(player1, "");
    getPlayerColor(player2, player1.color);

    getCharacterChoice(player1);
    getCharacterChoice(player2);

    getPathChoice(player1);
    getPathChoice(player2);

    evaluatePathChoice(player1);
    evaluatePathChoice(player2);
}