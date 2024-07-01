#include "game.h"
#include <iostream>

using namespace std;

bool Game::add(string playerName)
{
    Player player(playerName);
    players.push(player);

    comment.addPlayer(playerName);
    comment.showPlayerNumber(players.size());

    return true;
}

void Game::rolling(int roll)
{
    nextTurn();

    comment.rollDice(roll);

    attemptEscapeFromJail(roll);
    if (true == currentPlayer->isInJail())
    {
        return;
    }

    currentPlayer->moveToNextLocation(roll);
    comment.showLocation(currentPlayer->getName(), currentPlayer->getLocation());

    askQuestion();
}

void Game::attemptEscapeFromJail(int roll)
{
    if (false == currentPlayer->isInJail())
    {
        return;
    }

    bool isAbleToEscape = hasChanceToEscapeFromJail(roll);
    if (true == isAbleToEscape)
    {
        currentPlayer->ExitJail();
    }

    comment.exitJail(currentPlayer->getName(), isAbleToEscape);
}

void Game::askQuestion()
{
    int categoryNumber = questionManager.getCategoryNumber(currentPlayer->getLocation());
    string category = questionManager.getCategory(categoryNumber);
    string question = questionManager.popQuestion(categoryNumber);

    comment.showCategory(category);
    comment.showQuestion(question);
}

bool Game::wasCorrectlyAnswered()
{
    if (true == currentPlayer->isInJail())
    {
        return true;
    }

    correctAnswer();

    bool gameNotOver = (false == currentPlayer->isWinner());

    return gameNotOver;
}

bool Game::wrongAnswer()
{
    if (true == currentPlayer->isInJail()) {
        return true;
    }

    currentPlayer->EnterJail();

    comment.answer(false);
    comment.enterJail(currentPlayer->getName());

    return true;
}

void Game::nextTurn()
{
    if (isGameStarted == false)
    {
        isGameStarted = true;
    }
    else
    {
        players.push(*currentPlayer);
        players.pop();
    }

    currentPlayer = &players.front();

    string name = currentPlayer->getName();
    comment.showCurrentPlayer(name);
}

void Game::correctAnswer()
{
    currentPlayer->plusOneCoin();

    comment.answer(true);
    comment.showCoin(currentPlayer->getName(), currentPlayer->getCoin());
}

bool Game::hasChanceToEscapeFromJail(int roll)
{
    return (roll % 2 != 0);
}

