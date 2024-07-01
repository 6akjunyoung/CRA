#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "IGame.h"

using std::string;
using std::list;
using std::vector;

class GameOrigin : public IGame {
public:
    GameOrigin();

    string createRockQuestion(int index);
    bool isPlayable();
    bool add(string playerName);

    int howManyPlayers();
    void rolling(int roll);

    bool wasCorrectlyAnswered();
    bool wrongAnswer();


private:
    vector<string> players;

    int places[6];
    int purses[6];

    bool inPenaltyBox[6];

    list<string> popQuestions;
    list<string> scienceQuestions;
    list<string> sportsQuestions;
    list<string> rockQuestions;

    int currentPlayer;
    bool isGettingOutOfPenaltyBox;

    void askQuestion();
    string currentCategory();
    bool didPlayerWin();
};
