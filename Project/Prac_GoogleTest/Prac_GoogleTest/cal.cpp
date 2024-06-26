#include <vector>
#include <string>

using namespace std;

class Cal
{
public:
	int getSum(int a, int b)
	{
		return a + b;
	}

	vector<string> changeox(vector<int> arr)
	{
		int cntEven = 0;
		int cntOdd = 0;
		vector<string>& result = *(new vector<string>());
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] % 2 == 0)
			{
				result.push_back("O");
			}
			else
			{
				result.push_back("X");
			}
		}
		return result;
	}

	string getCalcResult(const std::string& str)
	{
		bool numberexists = false;
		int plusCnt = 0;
		int equalCnt = 0;
		int plusIdx, equalIdx = 0;

		plusCnt = getCount(str, '+');
		plusIdx = getIndex(str, '+');

		equalCnt = getCount(str, '=');
		equalIdx = getIndex(str, '=');

		if ((1 != plusCnt) || (1 != equalCnt) || (false == isValid(str)))
		{
			return "ERROR";
		}

		if (!((plusIdx < equalIdx) && (plusIdx >= 1 && equalIdx >= 3 && equalIdx < str.length() - 1)))
		{
			return "ERROR";
		}

		string num1 = str.substr(0, plusIdx);
		string num2 = str.substr(plusIdx + 1, equalIdx - plusIdx - 1);
		string num3 = str.substr(equalIdx + 1);

		int n1 = stoi(num1);
		int n2 = stoi(num2);
		int n3 = stoi(num3);

		if (n1 + n2 == n3) {
			return "PASS";
		}

		return "FAIL";
	}
private:
	int getCount(const string& str, char symbol)
	{
		int count = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == symbol) {
				count++;
			}
		}
		return count;
	}

	int getIndex(const string& str, char symbol)
	{
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == symbol) {
				return i;
			}
		}
		return -1;
	}

	bool isValid(const string& str)
	{
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '+') continue;
			if (str[i] == '=') continue;
			if (('0' <= str[i]) && str[i] <= '9') continue;

			return false;
		}
		return true;
	}

};