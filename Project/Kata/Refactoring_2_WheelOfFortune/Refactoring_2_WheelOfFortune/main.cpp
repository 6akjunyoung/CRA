#include "wheel.cpp"

int main()
{
	vector<string> strs;
	int map[5][50] = { 0 };
	string userdata = "";
	int n = 0;

	freopen_s(new FILE*, "input1.txt", "r", stdin);
	cin >> n;

	//ют╥б
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		strs.push_back(temp);
	}
	cin >> userdata;

	Wheel app;
	int sum = app.getScore(strs, userdata);

	cout << "$" << sum << endl;

	return 0;
}