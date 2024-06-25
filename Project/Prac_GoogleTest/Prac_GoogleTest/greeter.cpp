#include <string>
#define interface struct
using namespace std;

interface Greeter
{
	virtual string Greet() = 0;
};

class NormalGreeter : public Greeter{
public:
	virtual string Greet() {
		return "Hello.";
	}
};

class FormalGreeter : public Greeter
{
public:
	string Greet() override
	{
		return "Good evening, sir.";
	}
};

class CasualGreeter : public Greeter
{
public:
	string Greet() override
	{
		return "Sup bro?";
	}
};

class IntimateGreeter : public Greeter
{
public:
	string Greet() override
	{
		return "Hello Darling!";
	}
};

class GreeterMachine
{
public:
	string Greet()
	{
		return greeter->Greet();
	}

	void setFormality(Greeter* greeter)
	{
		this->greeter = greeter;
	}

private:
	Greeter* greeter;
};