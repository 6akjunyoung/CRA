#include "Sort.cpp"

class SortMachine
{
public:
	void insert(int num)
	{
		numbers.push_back(num);
	}
	void clear(void)
	{
		numbers.clear();
	}

	void show(void)
	{
		for (int value : numbers)
		{
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}

	void sort(ISort* sort)
	{
		sort->sort(numbers);
	}

private:
	std::vector<int> numbers;
};
