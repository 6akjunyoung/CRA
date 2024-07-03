#include "pch.h"

#include <iostream>
#include <stdexcept>

using namespace std;

class AvoidException : public logic_error
{

};

int sum(int a, int b)
{
	if (a < 0)
	{
		throw invalid_argument("a 음수");
	}
	if (b < 0)
	{
		throw invalid_argument("b 음수");
	}
	if (a > 100 || b > 100)
	{
		throw out_of_range("100이하 허용");
	}

	return a + b;
}
TEST(TestException, TestTryCatch)
{
	try
	{
		cout << sum(-1, 4) << endl;
	}
	catch (invalid_argument& e)
	{
		cout << "invalid argument" << endl;
	}
	catch (out_of_range& e)
	{
		cout << "Out of range" << endl;
	}
	catch (...)
	{
		cout << "모든 Error" << endl;
	}
}