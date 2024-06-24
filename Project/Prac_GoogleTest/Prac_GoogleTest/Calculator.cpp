#include <iostream>

class Calculator
{
public:
	void plus(int a, int b)
	{
		result = a + b;
	}
	void minus(int a, int b)
	{
		result = a - b;
	}
	void divide(int a, int b)
	{
		result = a / b;
	}
	void multiple(int a, int b)
	{
		result = a* b;
	}
	void printResult()
	{
		std::cout << result << std::endl;
	}
private:
	int result;
};