#include <iostream>
#include "pch.h"
#include "../Prac_GoogleTest/Zegop.cpp"

using namespace std;

class PracTestFixture : public testing::Test
{
public:
	PracTestFixture()
	{

	}

protected:
	void SetUp() override
	{
		cout << "Before testing..." << endl;
	}
	void TearDown() override
	{
		cout << "After testing..." << endl;
	}

private:
};

TEST_F(PracTestFixture, ZegopBasic)
{
	Zegop z(10);
	EXPECT_EQ(z.getZegop(), 100);
}