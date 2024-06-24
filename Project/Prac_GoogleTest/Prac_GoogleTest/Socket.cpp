#include <iostream>
#define interface struct

using namespace std;

interface Socket
{
	virtual void plug() = 0;
	virtual void unplug() = 0;
};

class Dansang : public Socket
{
public:
	void plug() override
	{
		zizic();
	}
	void unplug() override
	{
		babac();
	}

private:
	void zizic()
	{
		cout << "ZIZIC" << endl;
	}

	void babac()
	{
		cout << "BABAC" << endl;
	}
};

class Samsang : public Socket
{
public:
	void plug() override
	{
		onon();
	}
	void unplug() override
	{
		offoff();
	}
private:
	void onon()
	{
		cout << "onon" << endl;
	}
	void offoff()
	{
		cout << "offoff" << endl;
	}
};

class SocketFactory
{
public:
	static::Socket* generateSocket(string name)
	{
		if (name == "dansang") return new Dansang();
		if (name == "samsang") return new Samsang();
		return nullptr;
	}
};

class AirContioner
{
public:
	void cool(Socket* socket)
	{
		socket->plug();
		cout << "시원하다" << endl;
		socket->unplug();
	}
};
