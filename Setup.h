#include <string>

#include "Player.h"

using namespace std;

void getPlayerNames(Player& player1, Player& player2);
bool isValidIntChoice(string s, int low, int high);
void getPlayerColor(Player& player, string taken);
void getCharacterChoice(Player& player);
void getPathChoice(Player& player);
void getAdvisorChoice(Player& player);
void evaluatePathChoice(Player& player);
void intialize_players(Player& player1, Player& player2);