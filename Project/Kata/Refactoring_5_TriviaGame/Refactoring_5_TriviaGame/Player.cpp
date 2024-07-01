#include <iostream>

using namespace std;

class Player
{
public:
    Player(string name)
        :name{ name }, location{ 0 }, coin{ 0 }, inJail{ false } {
    }

    bool isInJail()
    {
        return inJail;
    }

    void ExitJail()
    {
        inJail = false;
    }

    void EnterJail()
    {
        inJail = true;
    }

    void plusOneCoin()
    {
        coin++;
    }

    int getLocation()
    {
        return location;
    }

    void moveToNextLocation(int roll)
    {
        location = ((location + roll) % 12);
    }

    int getCoin()
    {
        return coin;
    }

    bool isWinner()
    {
        return (getCoin() >= 6);
    }

    const string getName()
    {
        return name;
    }

private:
    string name;
    int location;
    int coin;
    bool inJail;
};