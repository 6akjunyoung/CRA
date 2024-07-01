#include "game.h"
#include <iostream>

using namespace std;

Game::Game() : currentPlayer{ -1 }, players{}
{
    for (int i = 0; i < MAX_QUESTION_NUM; i++) {
        for (int j = 0; j < GAME_CATEGORY::NUMBER_COUNT; j++)
        {
            questions[j].push_back(createQuestion(GAME_CATEGORY::STRING_CATEGORY[j], i));
        }
    }
}

string Game::createQuestion(string category, int index)
{
    string indexStr = category + " Question " + to_string(index);
    return indexStr;
}

bool Game::add(string playerName)
{
    PLAYER player(playerName);
    players.push_back(player);

    cout << playerName << " was added" << endl;
    cout << "They are player number " << players.size() << endl;
    return true;
}

void Game::rolling(int roll)
{
    nextTurn(roll);

    attemptEscapeFromJail(roll);
    if (true == isInJail())
    {
        return;
    }

    moveToNextPlace(roll);

    askQuestion();
}

void Game::attemptEscapeFromJail(int roll)
{
    if (false == isInJail())
    {
        return;
    }

    if (true == isChanceToEscapeFromJail(roll))
    {
        cout << players[currentPlayer].name << " is getting out of the penalty box" << endl;
        escapeFromJail();
    }
    else
    {
        cout << players[currentPlayer].name << " is not getting out of the penalty box" << endl;
    }
}

void Game::moveToNextPlace(int roll)
{
    players[currentPlayer].places = (players[currentPlayer].places + roll) % 12;

    cout << players[currentPlayer].name << "'s new location is " << players[currentPlayer].places << endl;
}

void Game::askQuestion()
{
    int categoryNumber = getCurrentCategoryNumber();
    auto& question = questions[categoryNumber];

    cout << "The category is " << GAME_CATEGORY::STRING_CATEGORY[categoryNumber] << endl;
    cout << question.front() << endl;
    question.pop_front();
}

int Game::getCurrentCategoryNumber()
{
    return (players[currentPlayer].places % 4);
}

bool Game::wasCorrectlyAnswered()
{
    if (true == isInJail())
    {
        return true;
    }

    correctAnswer();

    return isGameRemaining(currentPlayer);
}

bool Game::wrongAnswer()
{
    if (true == isInJail()) {
        return true;
    }

    incorrectAnswer();

    return true;
}

bool Game::isGameRemaining(int turn)
{
    return (players[turn].purses < 6);
}

void Game::getOneCoin()
{
    players[currentPlayer].purses++;
    cout << players[currentPlayer].name << " now has "
        << players[currentPlayer].purses << " Gold Coins." << endl;
}

void Game::nextTurn(int roll)
{
    currentPlayer++;
    currentPlayer %= players.size();

    cout << players[currentPlayer].name << " is the current player" << endl;
    cout << "They have rolled a " << roll << endl;
}

void Game::correctAnswer()
{
    cout << "Answer was correct!!!!" << endl;

    getOneCoin();
}

void Game::incorrectAnswer()
{
    cout << "Question was incorrectly answered" << endl;
    cout << players[currentPlayer].name + " was sent to the penalty box" << endl;

    goToJail();
}

bool Game::isChanceToEscapeFromJail(int roll)
{
    return (roll % 2 != 0);
}

bool Game::isInJail()
{
    return players[currentPlayer].inJail;
}

void Game::escapeFromJail()
{
    players[currentPlayer].inJail = false;
}

void Game::goToJail()
{
    players[currentPlayer].inJail = true;
}
