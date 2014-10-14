#include <iostream>
#include <string>
using namespace std;

class unit
{
	protected:
	int Health;
	int AForce;
	public:
	void getdamage(int x)
	{
		Health-=x;
	}
	bool IsAlive()
	{
	return (Health>0);	
	}
	unit(int InHealth, int InAForce):Health(InHealth),AForce(InAForce)
	{}
};
class Dragon: public unit
{
	int Answer;
	string Color;
	public:
	string GetQuest()
	{
		
	}
	bool checkanswer(int InAnswer)
	{
		return (InAnswer==Answer);
	}
	Dragon(InHealth, InAForce, InColor):unit(InHealth, InAForce), Color(InColor)
	{}
};
class Hero: public unit
{
	int score;
	string name;
	void attack(Dragon)
	Hero(health, afroce, name)
};
int main()
{
	
}
