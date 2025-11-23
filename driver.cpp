#include <iostream>
// #include <vector>

// #include "Board.h"
// #include "Tile.h"
// #include "Character.h"
#include "Player.h"
#include "Setup.h"
#include "GameLoop.h"
#include "HelperMethods.h"
// #include "EscapeColors.h"

using namespace std;

// main driver function
int main() {
    Player player1, player2;
    intialize_players(player1, player2);

    HelperMethods::clearPrintHeading("Game Begin");
    GameLoop loop(player1, player2);
    loop.runLoop();

    // Board b;
    // b.displayBoard();

    // while (!b.movePlayer(0)) {}
    // while (!b.movePlayer(1)) {}

    // b.displayBoard();

    return 0;
}