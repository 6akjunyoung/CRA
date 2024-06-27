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

		//하나씩 처리
		//26글자 for 돌면서 퀴즈 참석자가 하나씩 시도를 하는 것
		for (int i = 0; i < 26; i++) {

			//1. 2000 달러 찬스를 얻었는지 검사
			for (int y = 0; y < strs.size(); y++) {
				if (chance[y] != -1) {
					for (int x = 0; x < strs[chance[y]].size(); x++) {
						if (map[chance[y]][x] == 0 && strs[chance[y]][x] == userdata[i]) {
							//획득 성공시 2000달러를 얻는다.
							sum += 2000;
							break;
						}
					}
					chance[y] = -1;
				}
			}

			int flag = 0;
			int passCnt = 0;

			//2중 for 돌면서 정답 문자열을 하나씩 검사해서
			//퀴즈참가자가 던진 문자가 존재하는지 검사
			for (int y = 0; y < strs.size(); y++) {
				for (int x = 0; x < strs[y].size(); x++) {
					if (map[y][x] == 1) continue;

					//만약 퀴즈참석자가 요청한 문자가, 
					//정답문자열과 동일하다면
					if (strs[y][x] == userdata[i]) {

						//Let's First 점수인지 확인한다.
						if (ffirst[y] == 0 && x == 0) {
							sum += 1000;
							ffirst[y] = 1;
							chance[y] = y;
						}
						else if (ffirst[y] == 0 && x != 0) {
							ffirst[y] = 1;
						}

						//used배열
						map[y][x] = 1;

						//해당 문자를 _로 바꿔버린다.
						strs[y][x] = '_';
						flag = 1;

						//동일한 문자 개수를 Counting한다.
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