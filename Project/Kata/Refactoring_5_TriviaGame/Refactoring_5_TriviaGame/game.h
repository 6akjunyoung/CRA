#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <queue>

#include "IGame.h"
#include "Player.cpp"
#include "Comment.h"
#include "question.cpp"

using std::string;
using std::list;
using std::vector;


/*
Game
 - 
감옥 관리자
 - 조건 검사
 - 조건이 되면 탈출
 - 감옥에 들어갈 수 있도록
Player
 - 나의 코인
 - 위치
 - 감옥인지
Question
 - 카드
 - 위치에 따른 카드 주제
 */

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

class Game : public IGame {
public:
    Game()
        : isGameStarted{ false }, currentPlayer{ nullptr }
    {}

    bool add(string playerName);

    void rolling(int roll);

    bool wasCorrectlyAnswered();
    bool wrongAnswer();

private:
    queue<Player> players;
    bool isGameStarted;
    Player* currentPlayer;
    Comment comment;
    QuestionManager questionManager;

    list<string> questions[GAME_CATEGORY::NUMBER_COUNT];

    void askQuestion();
    void correctAnswer();
    void nextTurn();
    void attemptEscapeFromJail(int roll);
    bool hasChanceToEscapeFromJail(int roll);
};
