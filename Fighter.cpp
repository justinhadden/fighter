#include "Fighter.h"

Fighter::Fighter(int heal, string nam)
{
	health = heal;
	name = nam;
	cout << nam << " enters the ring!\n";
}
void Fighter::swing(Fighter &loser, int hit)
{
	int damage = hit;
	int curHealth = loser.health;
	loser.health = curHealth - damage;
}
void Fighter::bigSwing(Fighter &loser, int hit)
{
	int damage = (hit * 2);
	int curHealth = loser.health;
	loser.health = curHealth - damage;
}
void Fighter::playerBigSwing(Fighter &loser, int hit)
{
	int damage = (hit * 3);
	int curHealth = loser.health;
	loser.health = curHealth - damage;
}
void Fighter::rest(Fighter &healing)
{
	int curHealth = healing.health;
	healing.health = curHealth + 20;
}