#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>

using namespace std;
using namespace testing;

TEST(TestCaseName, TestName) {

    int* p1 = nullptr;
    int* p2 = new int();

    EXPECT_THAT(p1, IsNull());
}

TEST(TestCaseName, TestName1) {
    vector<int> arr = { 1, 3, 5, 7, 9 };

    EXPECT_THAT(arr, Contains(5));
}