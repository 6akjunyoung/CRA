#include <iostream>
#include <string>
#include "Comment.h"

using namespace std;

void Comment::exitJail(string name, bool success)
{
    if (true == success)
    {
        cout << name << " is getting out of the penalty box" << endl;
    }
    else
    {
        cout << name << " is not getting out of the penalty box" << endl;
    }
}

void Comment::enterJail(string name)
{
    cout << name + " was sent to the penalty box" << endl;
}

void Comment::answer(bool correct)
{
    if (true == correct)
    {
        cout << "Answer was correct!!!!" << endl;
    }
    else
    {
        cout << "Question was incorrectly answered" << endl;
    }
}

void Comment::showCoin(string name, int coin)
{
    cout << name << " now has " << coin << " Gold Coins." << endl;
}

void Comment::showLocation(string name, int place)
{
    cout << name << "'s new location is " << place << endl;
}

void Comment::showPlayerNumber(int playerNum)
{
    cout << "They are player number " << playerNum << endl;
}

void Comment::rollDice(int roll)
{
    cout << "They have rolled a " << roll << endl;
}

void Comment::addPlayer(std::string& name)
{
    cout << name << " was added" << endl;
}

void Comment::showCurrentPlayer(std::string& name)
{
    cout << name << " is the current player" << endl;
}

void Comment::showQuestion(std::string& question)
{
    cout << question << endl;
}

void Comment::showCategory(std::string& category)
{
    cout << "The category is " << category << endl;
}
