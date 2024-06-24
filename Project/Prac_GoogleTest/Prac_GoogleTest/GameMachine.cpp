class GameMachine
{
public:
	GameMachine()
	{
		currentCoin = 0;
	}

	bool inputCoin(int coin)
	{
		if ((coin < 0) || (coin > 5) || (currentCoin + coin > 10))
		{
			return false;
		}

		currentCoin += coin;
		return true;
	}

	bool playGame()
	{
		if (currentCoin <= 0)
		{
			return false;
		}

		currentCoin--;

		return true;
	}

	int checkCoin()
	{
		return currentCoin;
	}
private:
	int currentCoin;
};