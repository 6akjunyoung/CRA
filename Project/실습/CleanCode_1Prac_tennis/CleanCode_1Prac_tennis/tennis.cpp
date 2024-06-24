#include <string>
using std::string;

class Tennis {
public:
    const string getTennisScore(int p1Score, int p2Score) {

        if (true == _isImpossibleToExpressInScore(p1Score, p2Score))
        {
            return _getSituation(p1Score, p2Score);
        }

        return _getScore(p1Score, p2Score);

    }

private:
    const string _getScore(int p1Score, int p2Score)
    {
        const string scoreInString[4] = { "Love", "Fifteen", "Thirty", "Forty" };

        string score = "";

        score += scoreInString[p1Score];
        score += "-";
        if (p1Score == p2Score)
        {
            score += "All";
        }
        else
        {
            score += scoreInString[p2Score];
        }

        return score;
    }

    const string _getSituation(int p1Score, int p2Score)
    {
        string higherPlayer = (p1Score > p2Score) ? "player1" : "player2";
        int diffScore = (higherPlayer == "player1") ? (p1Score - p2Score) : (p2Score - p1Score);
        string score = "";

        if (diffScore == 0)
        {
            return "Deuce";
        }
        
        if (diffScore <= 1)
        {
            return "Advantage " + higherPlayer;
        }

        return "Win for " + higherPlayer;
    }

    bool _isImpossibleToExpressInScore(int p1Score, int p2Score)
    {
        return ((p1Score > 3) || (p2Score > 3));
    }
};
