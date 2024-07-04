#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../GoogleTest_withGmock/Plus.cpp"

#include <vector>

using namespace testing;
using namespace std;

class PlusTestFixture : public Test
{
protected:
    void diagnostic(vector<int> input, vector<int> expected)
    {
        Plus plus;
        EXPECT_THAT(plus.getIncrementNumbers(input), ContainerEq(expected));
    }
};

TEST_F(PlusTestFixture, CalContainerTest1) {
    vector<int> arr = { 1,2,3,2 };
    vector<int> expected = { 2,3,5,3 };

    diagnostic(arr, expected);
}

TEST_F(PlusTestFixture, CalContainerTest2) {
    vector<int> arr = { 9,9,3,3 };
    vector<int> expected = { 0,0,5,5 };

    diagnostic(arr, expected);
}
