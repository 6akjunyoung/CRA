#include <iostream>
#include "pch.h"
#include "../Prac_GoogleTest/FactoryMethod.cpp"

using namespace std;

class RefactTestFixture : public testing::Test
{
};

TEST_F(RefactTestFixture, factorymethod)
{
	SuperFactory* fac = new KoreanFactory();
	fac->makeDoll("red")->speak();
}