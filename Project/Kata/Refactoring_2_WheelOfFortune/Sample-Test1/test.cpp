#include <iostream>
#include <vector>
#include "pch.h"
#include "../Refactoring_2_WheelOfFortune/Wheel.cpp"

using namespace std;

class WheelTest : public testing::Test {
protected:
	void SetUp() override
	{
		/*std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		clearerr(stdin);*/
	}

	int getSumFrom(const char* testfile)
	{
		vector<string> strs;
		string userdata = "";
		int n = 0;

		FILE* stream;
		if (freopen_s(&stream, testfile, "r", stdin) != 0) {
			perror("freopen_s failed for input1.txt");
			return -1;
		}

		cin >> n;

		//ют╥б
		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			strs.push_back(temp);
		}
		cin >> userdata;

		fclose(stream);

		Wheel app;
		return app.getScore(strs, userdata);
	}
};

TEST_F(WheelTest, Input1) {
	EXPECT_EQ(6500, getSumFrom("../Refactoring_2_WheelOfFortune/input1.txt"));
}

TEST_F(WheelTest, Input2) {
	EXPECT_EQ(9500, getSumFrom("../Refactoring_2_WheelOfFortune/input2.txt"));
}