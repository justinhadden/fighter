#include<iostream>
#include<string>

using namespace std;

class Fighter
{
public:
	int health;
	string name;
	void swing(Fighter &loser, int hit);
	void bigSwing(Fighter &loser, int hit);
	void playerBigSwing(Fighter &loser, int hit);
	void rest(Fighter &healing);
	Fighter(int health = 0, string = "");
};
