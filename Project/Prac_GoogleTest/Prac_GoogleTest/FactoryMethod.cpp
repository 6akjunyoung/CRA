#include <iostream>

#define interface struct

using namespace std;

interface Doll
{
public:
	virtual void speak() = 0;
};

class RedDoll : public Doll
{
public:
	RedDoll(string msg) : msg(msg) { }

	void speak() override
	{
		cout << "RedRed" << endl;
		cout << msg << endl;
	}
private:
	string msg;
};

class BlueDoll : public Doll
{
public:
	BlueDoll(string msg) : msg(msg) { }

	void speak() override
	{
		cout << "BlueBlue" << endl;
		cout << msg << endl;
	}
private:
	string msg;
};


interface SuperFactory
{
public:
	virtual Doll* makeDoll(string name) = 0;
};

class SwissFactory : public SuperFactory
{
public:
	Doll* makeDoll(string name) override
	{
		if ("red") return new RedDoll("RED");
		if ("blue") return new BlueDoll("BLUE");
		return nullptr;
	}
};

class KoreanFactory : public SuperFactory
{
public:
	Doll* makeDoll(string name) override
	{
		if ("red") return new RedDoll("»¡°­");
		if ("blue") return new BlueDoll("ÆÄ¶û");
		return nullptr;
	}
};