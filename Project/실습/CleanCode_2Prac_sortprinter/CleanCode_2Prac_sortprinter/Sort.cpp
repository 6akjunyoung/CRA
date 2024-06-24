#include <iostream>
#include <vector>
#include <algorithm>
#define interface struct

interface ISort
{
	virtual void sort(std::vector<int>& numbers) = 0;
};

class Sort : public ISort
{
public:

	virtual void sort(std::vector<int>& numbers) override
	{
		std::sort(numbers.begin(), numbers.end());
	}
};

class BubbleSort : public Sort
{
	void sort(std::vector<int>& numbers) override
	{
		int n = numbers.size();
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < n - i - 1; ++j) {
				if (numbers[j] > numbers[j + 1]) {
					std::swap(numbers[j], numbers[j + 1]);
				}
			}
		}
	}
};

class SelectionSort : public Sort
{
	void sort(std::vector<int>& numbers) override
	{
		int n = numbers.size();
		for (int i = 0; i < n - 1; ++i) {
			int minIndex = i;
			for (int j = i + 1; j < n; ++j) {
				if (numbers[j] < numbers[minIndex]) {
					minIndex = j;
				}
			}

			std::swap(numbers[i], numbers[minIndex]);
		}
	}
};

class SortFactory
{
public:
	static ISort* generate(std::string algorithm)
	{
		if ("selection" == algorithm) return new SelectionSort();
		if ("bubble" == algorithm) return new BubbleSort();
		return nullptr;
	}
};