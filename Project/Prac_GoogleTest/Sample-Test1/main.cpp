#include "pch.h"
#include <iostream>

using namespace std;

#if 01

class GlobalEnv : public testing::Environment
{
public: 
    void SetUp()
    {
        cout << "Test Ready!!" << endl;
    }

    void TearDown()
    {
        cout << "Clean Up!!" << endl;
    }
};

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    testing::AddGlobalTestEnvironment(new GlobalEnv);

    return RUN_ALL_TESTS();
}
#else
int main(int argc, char* argv[])
{
    return RUN_ALL_TESTS();
}
#endif