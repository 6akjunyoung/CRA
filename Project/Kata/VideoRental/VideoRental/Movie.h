#pragma once
#include <string>

using std::string;

class Movie
{
public:
	static const int CHILDRENS = 2;
	static const int NEW_RELEASE = 1;
	static const int REGULAR = 0;

	Movie(const string& title, int price_code)
		: title(title),
		category(price_code)
	{
	}

	int getCategory();
	void setCategory(int price_code);
	string getTitle();

private:
	string title;
	int category;
};
