#include <iostream>
#include "pch.h"
#include "../Prac_GoogleTest/cal.cpp"
#include "../Prac_GoogleTest/Zergling.cpp"
#include "../Prac_GoogleTest/Calculator.cpp"
#include "../Prac_GoogleTest/GameMachine.cpp"
#include "../Prac_GoogleTest/Phone.cpp"
#include "../Prac_GoogleTest/Socket.cpp"
#include "../Prac_GoogleTest/splitAndSum.cpp"

using namespace std;

TEST(TestCaseName, TestBasic1)
{
	EXPECT_EQ(1, 1);
	EXPECT_LT(1, 2);
	EXPECT_LE(1, 2);
	EXPECT_LE(1, 1);
	EXPECT_GT(2, 1);
	EXPECT_GE(2, 1);
	EXPECT_GE(1, 1);
	EXPECT_NE(true, false);
}
TEST(TestCaseName, TestName1) {
	Cal cal;
	EXPECT_EQ(21, cal.getSum(1, 20));
	EXPECT_EQ(21, cal.getSum(1, 20));
	EXPECT_EQ(21, cal.getSum(1, 20));
	EXPECT_EQ(21, cal.getSum(1, 20));
	EXPECT_TRUE(true);
}
TEST(TestCaseName, TestName2) {
	Cal cal;
	EXPECT_EQ(6, cal.getSum(1, 5));
	EXPECT_TRUE(true);
}
TEST(TestCaseName, TestName3) {
	Zergling objZergling;

	objZergling.status();
	
	std::cout << std::endl;

	objZergling.attack();
	objZergling.status();

	std::cout << std::endl;

	objZergling.move();
	objZergling.status();
}

TEST(TestCaseName, TestName4) {
	Calculator objCalculator;

	objCalculator.plus(100, 2);
	objCalculator.printResult();

	objCalculator.minus(100, 2);
	objCalculator.printResult();

	objCalculator.divide(100, 2);
	objCalculator.printResult();

	objCalculator.multiple(100, 2);
	objCalculator.printResult();
}

TEST(TestCaseName, TestName5) {
	GameMachine objGameMachine;
	EXPECT_EQ(0, objGameMachine.checkCoin());

	EXPECT_FALSE(objGameMachine.playGame());
	EXPECT_FALSE(objGameMachine.inputCoin(6));
	EXPECT_FALSE(objGameMachine.inputCoin(-1));

	EXPECT_TRUE(objGameMachine.inputCoin(5));
	EXPECT_TRUE(objGameMachine.inputCoin(5));
	EXPECT_FALSE(objGameMachine.inputCoin(1));
	EXPECT_EQ(10, objGameMachine.checkCoin());

	for (int i = 10; i > 0; i--)
	{
		EXPECT_EQ(i, objGameMachine.checkCoin());
		EXPECT_TRUE(objGameMachine.playGame());
	}

	EXPECT_EQ(0, objGameMachine.checkCoin());

	EXPECT_FALSE(objGameMachine.playGame());
}

TEST(TestCaseName, TestName6) {
	Phone* a = new Phone();
	Phone* b = new SmartPhone();
	// SmartPhone* c = new Phone();
	SmartPhone* d = new SmartPhone();

	a->call();
	b->call();
	d->call();

	a->virtualcall();
	b->virtualcall();
	d->virtualcall();

	phonecall(makePhone("smart"));
	phonecall(makePhone("brick"));
}

TEST(TestCaseName, TestName7)
{
	AirContioner objAirConditioner;

	objAirConditioner.cool(SocketFactory::generateSocket("samsang"));
	objAirConditioner.cool(SocketFactory::generateSocket("dansang"));
}

TEST(TestCaseName, TestName8)
{
	EXPECT_EQ(130, splitAndSum("100-10-20"));
	EXPECT_EQ(40, splitAndSum("10-10-20"));
	EXPECT_EQ(22, splitAndSum("1-1-20"));
	EXPECT_EQ(4, splitAndSum("1-1-2"));
	EXPECT_EQ(30, splitAndSum("0-10-20"));
	EXPECT_EQ(220, splitAndSum("10-10-200"));
}

TEST(TestCaseName, TestName9)
{
	Cal cal;

	EXPECT_EQ(cal.getCalcResult("25+61=86"), "PASS");
	EXPECT_EQ(cal.getCalcResult("12345+12345=24690"), "PASS");
	EXPECT_EQ(cal.getCalcResult("5++5=10"), "ERROR");
	EXPECT_EQ(cal.getCalcResult("10000+1=10002"), "FAIL");
}