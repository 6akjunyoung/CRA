#include<iostream>
#include<vector>

using namespace std;

/*
�ι�ƮC��ƾ
���? ª����?
��ȣ�ϱ� ����� ª�� �� ���ٴ�
���� �����ϱ� ���� ��� ����

�ڵ������� = �ڵ���Ÿ�� ���̵�
C++ - google style guide for C++
C++ - ����ӽ���� = Core C++

<Piority>
ȸ�� �ڵ�������
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