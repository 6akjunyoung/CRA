#include <iostream>
#include "pch.h"
#include "../Prac_GoogleTest/cal.cpp"

using namespace std;

class OddEvenTest : public testing::Test
{
public:
protected:
    void SetUp() override
    {
        cout << "::::::::::::::: Start OddEvenTest :::::::::::::::" << endl;
    }
    void TearDown() override
    {
        cout << "::::::::::::::: End   OddEvenTest :::::::::::::::" << endl << endl;
    }

    void makeRand(vector<int>& v, int num)
    {
        v.clear();
        for (int i = 0; i < num; i++)
        {
            v.push_back(rand() % 10);
        }
    }

    void printVector(vector<int>& v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void printVector(vector<string>& v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

TEST_F(OddEvenTest, BasicTest)
{
    vector<int> testvector;

    makeRand(testvector, 20);
    printVector(testvector);

    Cal cal;
    vector<string>& answer = cal.changeox(testvector);

    printVector(answer);
}