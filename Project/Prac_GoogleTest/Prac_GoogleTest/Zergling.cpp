#include <iostream>

class Zergling
{
public :
	Zergling()
	{
		hp = 80;
		mp = 200;
	}
	void attack()
	{
		hp += 1;
		mp -= 10;
	}
	void move()
	{
		hp -= 10;
		mp += 5;
	}
	void status()
	{
		std::cout << "hp: " << hp << std::endl
			      << "mp: " << mp << std::endl;
	}
private:
	int hp;
	int mp;
};