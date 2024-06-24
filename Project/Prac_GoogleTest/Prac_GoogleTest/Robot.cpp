#include <iostream>
using namespace std;

class Robot {
public:
	void move() { cout << "go"; }
	void stop() { cout << "stop"; }

protected:
	int hp = 0;
};

class SpeedRobot : public Robot {
public:
	void move() { cout << "go fast"; } 
	void run() { cout << "run"; }
	void walk() { cout << "walk"; }

private:
	int modelID = 0;
};

class PowerRobot : public Robot {
public:
	void attack() { cout << "attack"; }
	void jump() { cout << "jump"; }
private:
	int mana = 0;
};