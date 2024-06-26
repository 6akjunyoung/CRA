#include<iostream>
#include<vector>
#include<string>
using std::cout;
using std::string;
using std::vector;

bool isEmpty(string text)
{
	return text.empty();
}

vector<string> split(string text)
{
	vector<string> values;

	text += "-";

	int a = 0, b = 0;
	while (1) {
		b = text.find("-", a);
		if (b == -1) break;
		string temp = text.substr(a, b - a);
		values.push_back(temp);
		a = b + 1;
	}
	return values;
}

vector<int> stringToInt(const vector<string>& vstring)
{
	vector<int> vinteger;
	for (auto value : vstring)
	{
		vinteger.push_back(stoi(value));
	}
	return vinteger;
}

int getSum(const vector<int>& values)
{
	int result = 0;
	for (auto value : values)
	{
		result += value;
	}
	return result;
}

int splitAndSum(string text)
{
	int result = 0;
	if (true == isEmpty(text))
	{
		return 0;
	}

	vector<string> valuesInString;
	vector<int> values;

	valuesInString = split(text);
	values = stringToInt(valuesInString);

	result = getSum(values);

	return result;
}
