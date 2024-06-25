#include "pch.h"
#include "../Prac_GoogleTest/cal.cpp"
#include "../Prac_GoogleTest/Zergling.cpp"
#include "../Prac_GoogleTest/Calculator.cpp"
#include "../Prac_GoogleTest/GameMachine.cpp"
#include "../Prac_GoogleTest/Phone.cpp"
#include "../Prac_GoogleTest/Socket.cpp"

class TestCaseName
{
};
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
