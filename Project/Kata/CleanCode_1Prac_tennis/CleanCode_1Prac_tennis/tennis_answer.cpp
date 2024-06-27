#include <string>
using std::string;

class Tennis {
public:
    const string tennis_score(int p1Score, int p2Score) {
        this->p1Score = p1Score;
        this->p2Score = p2Score;

        if (isDeuce()) return "Deuce";
        if (isSamePoint()) return getScoreMessage(p1Score) + "-All";

        if (isAdvantageForPlayer1()) return "Advantage player1";
        if (isAdvantageForPlayer2()) return "Advantage player2";

        if (isWinForPlayer1()) return "Win for player1";
        if (isWinForPlayer2()) return "Win for player2";

        return getScoreMessage(p1Score) + string("-") + getScoreMessage(p2Score);
    }

    bool isDeuce()
    {
        return p1Score >= 3 && p2Score >= 3 && p1Score == p2Score;
    }

    bool isSamePoint()
    {
        return p1Score == p2Score;
    }

    bool isAdvantageForPlayer1()
    {
        return p1Score >= 3 && p2Score >= 3 && p1Score == p2Score + 1;
    }

    bool isAdvantageForPlayer2()
    {
        return p1Score >= 3 && p2Score >= 3 && p2Score == p1Score + 1;
    }

    bool isWinForPlayer1()
    {
        return p1Score >= 4 && p1Score >= p2Score + 2;
    }

    bool isWinForPlayer2()
    {
        return p2Score >= 4 && p2Score >= p1Score + 2;
    }

    string getScoreMessage(int score) {
        if (score == 0) return "Love";
        if (score == 1) return "Fifteen";
        if (score == 2) return "Thirty";
        if (score == 3) return "Forty";
    }

private:
    int p1Score;
    int p2Score;
};