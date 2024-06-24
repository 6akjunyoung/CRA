#include<iostream>
#include<vector>

using namespace std;

/*
로버트C마틴
긴게? 짧은게?
모호하기 어려운 짧은 것 보다는
차라리 이해하기 쉬운 긴게 낫다

코딩컨벤션 = 코딩스타일 가이드
C++ - google style guide for C++
C++ - 스토롭스토롭 = Core C++

<Piority>
회사 코딩컨벤션
*/

#include<iostream>
#include<vector>
using namespace std;

#if 0
void run(vector<int>& theVector) {
	for (int t = 0; t < theVector.size(); t++) {
		if (theVector[t] == 0) continue;
		theVector[t] = theVector[t] - 1;
	}
}
#else
void updateHotelRoomLife(vector<int>& rooms) {
    for (int t = 0; t < rooms.size(); t++) {
        if (rooms[t] == 0) continue;
        rooms[t] = rooms[t] - 1;
    }
}
#endif

int main()
{


    return 0;
}