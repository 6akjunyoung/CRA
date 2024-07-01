#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "IGame.h"

using std::string;
using std::list;
using std::vector;

namespace GAME_CATEGORY
{
    enum
    {
        NUMBER_POP,
        NUMBER_SCIENCE,
        NUMBER_SPORTS,
        NUMBER_ROCK,
        NUMBER_COUNT,
    };

    const string STRING_CATEGORY[NUMBER_COUNT] = {
        "Pop", "Science", "Sports", "Rock",
    };
}

struct PLAYER
{
    string name;
    int places;
    int purses;
    bool inJail;

    PLAYER(string name)
        :name{ name }, places{ 0 }, purses{ 0 }, inJail{ false } {}
};

class Game : public IGame {
public:
    Game();

    bool add(string playerName);

    void rolling(int roll);

    bool wasCorrectlyAnswered();
    bool wrongAnswer();

private:
    vector<PLAYER> players;
    int currentPlayer;

    const int MAX_QUESTION_NUM = 50;
    list<string> questions[GAME_CATEGORY::NUMBER_COUNT];

    int getCurrentCategoryNumber();
    string createQuestion(string category, int index);
    void moveToNextPlace(int roll);
    void askQuestion();
    bool isGameRemaining(int turn);
    void correctAnswer();
    void getOneCoin();
    void nextTurn(int roll);
    void incorrectAnswer();
    void goToJail();
    bool isInJail();
    void attemptEscapeFromJail(int roll);
    void escapeFromJail();
    bool isChanceToEscapeFromJail(int roll);
};
