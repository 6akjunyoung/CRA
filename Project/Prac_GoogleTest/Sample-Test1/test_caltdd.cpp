#include <iostream>
#include <vector>
#include "pch.h"
#include "../Prac_GoogleTest/Fibo.cpp"

using namespace std;
// 0 1 1 2 3 5 8

TEST(TestCaseNameCalTdd, TestCalBasic)
{
    vector<vector<int>> c = { {0,0}, {1,1}, {2,1}, {3,2} };

    for (auto v : c)
    {
        EXPECT_EQ(v[1], Fibo().fibo(v[0]));
    }
}