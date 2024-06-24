#include <iostream>
using namespace std;

class Phone
{
public:
	virtual void virtualcall()
	{
		cout << "Calling..." << endl;
	}

	void call()
	{
		cout << "Calling..." << endl;
	}
};

class SmartPhone : public Phone
{
public:
	void virtualcall() override
	{
		cout << "Smart Calling..." << endl;
	}

	void call()
	{
		cout << "Smart Calling..." << endl;
	}
};

class BrickPhone : public Phone
{
public:
	void virtualcall() override
	{
		cout << "Brick" << endl;
	}

	void call()
	{
		cout << "Brick" << endl;
	}
};

// 1. Dependency Injection (DI)
Phone* makePhone(string name)
{
	if (name == "brick") return new BrickPhone();
	if (name == "smart") return new SmartPhone();
	return nullptr;
}

// 2. Factory
void phonecall(Phone* p)
{
	p->call();
	p->virtualcall();
	cout << "전화완료" << endl;
}