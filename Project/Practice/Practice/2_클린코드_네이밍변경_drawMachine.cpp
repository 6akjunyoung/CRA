#include<iostream>
#include<vector>
using namespace std;

#if 0
struct xyInfo {
	int x;
	int y;
};

class xyManager {
public:
	void add(xyInfo data) {
		vstDot.push_back(data);
	}

	void drawButton() {
		for (xyInfo o : vstDot) {
			cout << o.x << " " << o.y << endl;
		}
	}

private:
	vector<xyInfo> arr;
};
#else
struct COORDINATE {
	int x;
	int y;
};

class DotDrawer {
public:
	void AddDots(COORDINATE stDot) {
		vstDotList.push_back(stDot);
	}

	void DrawDots() {
		for (COORDINATE stDot : vstDotList) {
			cout << stDot.x << " " << stDot.y << endl;
		}
	}

private:
	vector<COORDINATE> vstDotList;
};
#endif

int main()
{


	return 0;
}