#include "pch.h"
#include "../Refactoring_5_TriviaGame/game_origin.cpp"
#include "../Refactoring_5_TriviaGame/game.cpp"
#include "../Refactoring_5_TriviaGame/Comment.cpp"

class ParameterizedTestFixture : public testing::TestWithParam<int>
{
public:
    string playGame(IGame& robjGame, int seed)
    {
        std::ostringstream oss;
        auto oldCoutStreamBuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

;       bool notAWinner;

        robjGame.add("Chet");
        robjGame.add("Pat");
        robjGame.add("Sue");

        srand(seed);

        do {
            int roll = rand() % 6 + 1;
            robjGame.rolling(roll);
        
            if (rand() % 9 == 7) {
                notAWinner = robjGame.wrongAnswer();
            }
            else {
                notAWinner = robjGame.wasCorrectlyAnswered();
            }
        } while (notAWinner);

        std::cout.rdbuf(oldCoutStreamBuf);
        return oss.str();
    }
};

TEST_F(ParameterizedTestFixture, goldenMaster_sample) {
    int seed = 1;
    GameOrigin objGameOrigin;
    Game objGameRefactor;

    string expected = playGame(objGameOrigin, seed);
    string actual = playGame(objGameRefactor, seed);

    EXPECT_EQ(expected, actual);
}


INSTANTIATE_TEST_CASE_P
(
    goldenMaster,
    ParameterizedTestFixture,
    testing::Values
    (
        1, 50, 100, 777
    )
);

TEST_P(ParameterizedTestFixture, goldenMaster) {
    int seed = GetParam();
    GameOrigin objGameOrigin;
    Game objGameRefactor;

    string expected = playGame(objGameOrigin, seed);
    string actual = playGame(objGameRefactor, seed);

    // cout << actual;

    EXPECT_EQ(expected, actual);
}