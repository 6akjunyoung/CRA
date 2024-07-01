#include <string>
#include <list>

using namespace std;

namespace CATEGORY
{
    static constexpr int NUMBER_POP = 0;
    static constexpr int NUMBER_SCIENCE = 1;
    static constexpr int NUMBER_SPORTS = 2;
    static constexpr int NUMBER_ROCK = 3;
    static constexpr int NUMBER_COUNT = 4;

    const string STRING[NUMBER_COUNT] = {
        "Pop", "Science", "Sports", "Rock",
    };
}

class QuestionManager
{
public:
    QuestionManager()
    {
        for (int i = 0; i < MAX_QUESTION_NUM; i++) {
            for (int j = 0; j < CATEGORY::NUMBER_COUNT; j++)
            {
                questions[j].push_back(createQuestion(CATEGORY::STRING[j], i));
            }
        }
    }

    int getCategoryNumber(int location)
    {
        return (location % CATEGORY::NUMBER_COUNT);
    }

    string getCategory(int categoryNumber)
    {
        return CATEGORY::STRING[categoryNumber];
    }

    string popQuestion(int categoryNumber)
    {
        string question = questions[categoryNumber].front();

        questions[categoryNumber].pop_front();

        return question;
    }

private:
    const int MAX_QUESTION_NUM = 50;
    list<string> questions[CATEGORY::NUMBER_COUNT];

    string createQuestion(string category, int index)
    {
        return category + " Question " + to_string(index);
    }
};