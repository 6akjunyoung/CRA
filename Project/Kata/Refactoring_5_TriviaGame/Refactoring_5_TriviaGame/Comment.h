#pragma once
#include <string>

using namespace std;

class Comment
{
public:
    void exitJail(string name, bool success);
    void enterJail(string name);
    void answer(bool correct);
    void rollDice(int roll);
    void addPlayer(std::string& name);

    void showCoin(string name, int coin);
    void showLocation(string name, int place);
    void showPlayerNumber(int playerNum);
    void showCurrentPlayer(std::string& name);
    void showQuestion(std::string& question);
    void showCategory(std::string& category);
};