#include <vector>
#include <stdexcept>

using namespace std;

class Plus
{
public:
    vector<int> getIncrementNumbers(const vector<int>& numbers)
    {
        vector<int> result = numbers;

        for (auto& num : result)
        {
            if (num >= 10 || num == 4) throw invalid_argument("Must not be 4 or 10 or over 10");

            num++;

            if (num == 10) num = 0;
            if (num == 4) num = 5;
        }

        return result;
    }
};