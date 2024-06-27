#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
	int y;
	int x;
};

class Wheel
{
public:
    int getScore(vector<string> strs, string userdata)
    {
		int sum = 0;
		int continuousCnt = 0;

		for (int i = 0; i < 26; i++) {

			char userdatavalue = userdata[i];
			vector<Axis> matchingPoints = getMatchingPoints(strs, userdatavalue);

			if (matchingPoints.size() == 0) {
				continuousCnt = 0;
				memset(secondChance, 0, sizeof(secondChance));
				continue;
			}

			continuousCnt++;

			sum += get2000dollars(matchingPoints);
			sum += get1000dollars(matchingPoints);
			sum += get100dollars(matchingPoints.size(), continuousCnt);

			flipCharacters(strs, matchingPoints);
		}

		return sum;
    }
	void flipCharacters(std::vector<std::string>& strs, vector<Axis> points)
	{
		for (auto axis : points)
		{
			strs[axis.y][axis.x] = '_';
		}
	}
	vector<Axis> getMatchingPoints(std::vector<std::string>& strs, char userdatavalue)
	{
		vector<Axis> matchingPoints;
		
		for (int y = 0; y < strs.size(); y++) {
			for (int x = 0; x < strs[y].size(); x++) {
				if (strs[y][x] != userdatavalue) continue;
				matchingPoints.push_back({ y, x });
			}
		}

		return matchingPoints;
	}
	int getMatchingCnt(std::vector<std::string>& strs, char userdatavalue)
	{
		int passCnt = 0;

		for (int y = 0; y < strs.size(); y++) {
			for (int x = 0; x < strs[y].size(); x++) {
				if (strs[y][x] != userdatavalue) continue;
				passCnt++;
			}
		}
		return passCnt;
	}
	int get100dollars(int passCnt, char conCnt)
	{
		return (conCnt * 100) * passCnt;
	}

	int get1000dollars(vector<Axis> points)
	{
		int dollar = 0;

		for (auto axis : points)
		{
			if (firstChance[axis.y] == true) continue;
			firstChance[axis.y] = true;

			if (axis.x != 0) continue;
			dollar += 1000;
			secondChance[axis.y] = true;
		}

		return dollar;
	}

	int get2000dollars(vector<Axis> points)
	{
		int dollar = 0;

		for (auto axis : points)
		{
			if (false == secondChance[axis.y]) continue;

			dollar += 2000;
			secondChance[axis.y] = false;
		}

		memset(secondChance, 0, sizeof(secondChance));

		return dollar;
	}

private:
	bool firstChance[5] = { };
	bool secondChance[5] = {  };
};

#if 0 // before
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Wheel {
public:
	int getValue(vector<string> strs, int map[5][50], string userdata) {

		int conCnt = 0;
		int ffirst[5] = { 0 };

		int sum = 0;
		int chance[5] = { -1, -1, -1, -1, -1 };

		//�ϳ��� ó��
		//26���� for ���鼭 ���� �����ڰ� �ϳ��� �õ��� �ϴ� ��
		for (int i = 0; i < 26; i++) {

			//1. 2000 �޷� ������ ������� �˻�
			for (int y = 0; y < strs.size(); y++) {
				if (chance[y] != -1) {
					for (int x = 0; x < strs[chance[y]].size(); x++) {
						if (map[chance[y]][x] == 0 && strs[chance[y]][x] == userdata[i]) {
							//ȹ�� ������ 2000�޷��� ��´�.
							sum += 2000;
							break;
						}
					}
					chance[y] = -1;
				}
			}

			int flag = 0;
			int passCnt = 0;

			//2�� for ���鼭 ���� ���ڿ��� �ϳ��� �˻��ؼ�
			//���������ڰ� ���� ���ڰ� �����ϴ��� �˻�
			for (int y = 0; y < strs.size(); y++) {
				for (int x = 0; x < strs[y].size(); x++) {
					if (map[y][x] == 1) continue;

					//���� ���������ڰ� ��û�� ���ڰ�, 
					//���乮�ڿ��� �����ϴٸ�
					if (strs[y][x] == userdata[i]) {

						//Let's First �������� Ȯ���Ѵ�.
						if (ffirst[y] == 0 && x == 0) {
							sum += 1000;
							ffirst[y] = 1;
							chance[y] = y;
						}
						else if (ffirst[y] == 0 && x != 0) {
							ffirst[y] = 1;
						}

						//used�迭
						map[y][x] = 1;

						//�ش� ���ڸ� _�� �ٲ������.
						strs[y][x] = '_';
						flag = 1;

						//������ ���� ������ Counting�Ѵ�.
						passCnt++;
					}
				}
			}

			if (flag == 1) {
				conCnt++;
				sum += (conCnt * 100) * passCnt;
			}
			else {
				conCnt = 0;
				for (int i = 0; i < 5; i++) chance[i] = -1;
			}
		}

		return sum;
	}
};
#endif