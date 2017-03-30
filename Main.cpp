/*
	Justin Hadden
	12-3-2016
*/

#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include "Fighter.h"

using namespace std;

void computerTurn(Fighter &fighterOne, Fighter &fighterTwo, int rand)
{
	int roll = (rand % 20) + 1;
	if (roll > 16) {
		cout << fighterOne.name << " takes a BIG SWING!!" << endl;
		fighterOne.bigSwing(fighterTwo, roll);
		if (fighterTwo.health > 0)
		{
			cout << fighterOne.name << " hit " << fighterTwo.name << " for " << roll * 2 << " damage down to " << fighterTwo.health << " health!\n";
			cout << "-------------------\n\n";
		}
		else
		{
			cout << fighterOne.name << " beat " << fighterTwo.name << " to death and " << fighterTwo.name << " is now dead!\n";
			cout << "-------------------\n\n";
		}
	}
	else if (roll > 3)
	{
		cout << fighterOne.name << " takes a swing!" << endl;
		fighterOne.swing(fighterTwo, roll);
		if (fighterTwo.health > 0)
		{
			cout << fighterOne.name << " hit " << fighterTwo.name << " for " << roll << " damage down to " << fighterTwo.health << " health!\n";
			cout << "-------------------\n\n";
		}
		else
		{
			cout << fighterOne.name << " beat " << fighterTwo.name << " to death and " << fighterTwo.name << " is now dead!\n";
			cout << "-------------------\n\n";
		}
	}
	else
	{
		fighterOne.rest(fighterOne);
		cout << fighterOne.name << " rests and heals up to " << fighterOne.health << " health.\n";
		cout << "-------------------\n\n";
	}
}

void playerTurn(Fighter &fighterOne, Fighter &fighterTwo, int rand)
{
	int selectMove;

	cout << "Your moves: " << endl;
	cout << "1. Swing (Guarenteed hit between 5-20)\n2. Big Swing! (50% chance to miss but could do massive damage)\n3. Rest (80% chance to heal for 20 health)\n";
	cout << "Which move would you like to use? (1/2/3): ";
	cin >> selectMove;
	cout << "-------------------\n\n";

	int roll = (rand % 20) + 1;
	while (selectMove > 3 || selectMove < 1)
	{
		if (selectMove == 300)
		{
			fighterOne.health = 0;
			cout << fighterTwo.name << " beat " << fighterOne.name << " to death and " << fighterOne.name << " is now dead!\n";
			cout << "-------------------\n\n";
			break;
		}
		else
		{
			cout << "Please select one of the three moves: ";
			cin >> selectMove;
		}
	}
	if (selectMove == 2)
	{
		if (roll <= 10)
		{
			cout << fighterTwo.name << " takes a BIG SWING and a BIG MISS!\n";
			cout << "-------------------\n\n";
		}
		else
		{
			if (roll < 15)
			{
				roll = 15;
			}
			if (roll == 20)
			{
				fighterTwo.playerBigSwing(fighterOne, 34);
				cout << fighterTwo.name << " landed a CRITICAL BIG SWING and erased " << fighterOne.name << " from the face of the earth!" << endl;
				cout << "-------------------\n\n";
			}
			else
			{
				cout << fighterTwo.name << " takes a BIG SWING!!" << endl;
				fighterTwo.playerBigSwing(fighterOne, roll);
				if (fighterOne.health > 0)
				{
					cout << fighterTwo.name << " hit " << fighterOne.name << " for " << roll * 3 << " damage down to " << fighterOne.health << " health!\n";
					cout << "-------------------\n\n";
				}
				else
				{
					cout << fighterTwo.name << " beat " << fighterOne.name << " to death and " << fighterOne.name << " is now dead!\n";
					cout << "-------------------\n\n";
				}
			}
		}
	}
	else if (selectMove == 1)
	{
		cout << fighterTwo.name << " takes a swing!!" << endl;
		fighterTwo.swing(fighterOne, roll);
		if (roll < 5)
		{
			roll = 5;
		}
		if (fighterOne.health > 0)
		{
			cout << fighterTwo.name << " hit " << fighterOne.name << " for " << roll << " damage down to " << fighterOne.health << " health!\n";
			cout << "-------------------\n\n";
		}
		else
		{
			cout << fighterTwo.name << " beat " << fighterOne.name << " to death and " << fighterOne.name << " is now dead!\n";
			cout << "-------------------\n\n";
		}
	}
	else
	{
		if (roll < 4)
		{
			cout << fighterOne.name << " is relentless and wont let " << fighterTwo.name << " rest!\n";
			cout << "-------------------\n\n";
		}
		else
		{
			fighterTwo.rest(fighterTwo);
			cout << fighterTwo.name << " rests and heals up to " << fighterTwo.health << " health.\n";
			cout << "-------------------\n\n";
		}
	}
}

void gameLoop(Fighter &fighterOne, Fighter &fighterTwo)
{
	srand(time(0));
	int turnCount = 0;
	while (fighterOne.health > 0 && fighterTwo.health > 0)
	{
		int randomNumber = rand();
		if ((turnCount % 2) > 0)
		{
			computerTurn(fighterOne, fighterTwo, randomNumber);
		}
		else
		{
			playerTurn(fighterOne, fighterTwo, randomNumber);
		}
		++turnCount;
	}
}

string fighterLoop(vector<string> fighters, Fighter &fighterTwo)
{
	string beatenBy;
	vector<string>::iterator iter;
	for (iter = fighters.begin(); iter < fighters.end(); ++iter)
	{
		cout << "-------------------\n\n";
		cout << fighterTwo.name << " has " << fighterTwo.health << " health as ";
		Fighter fighterOne(100, *iter);
		cout << "-------------------\n\n";

		gameLoop(fighterOne, fighterTwo);

		if (fighterOne.health <= 0)
		{
			cout << fighterOne.name << " is dead! " << fighterTwo.name << " wins the fight!\n";
		}
		else if (fighterTwo.health <= 0)
		{
			cout << fighterTwo.name << " is dead! " << fighterOne.name << " wins!!!!\n\n";
			beatenBy = fighterOne.name;
			iter = fighters.end() - 1;
		}
	}
	return beatenBy;
}

void winner(const Fighter &fighterTwo, const string &beatenBy)
{
	if (fighterTwo.health <= 0)
	{
		cout << "Looks like " << fighterTwo.name << " couldn't handle " << beatenBy << "." << endl;
		cout << "Better luck next time!\n" << endl;
	}
	else
	{
		cout << "Congratulations! " << fighterTwo.name << " has beaten all 6 fighters and is victorious!\n" << endl;
	}
}

int main()
{
	string beatenBy;

	vector<string> fighters;
	fighters.push_back("Moe");
	fighters.push_back("Larry");
	fighters.push_back("Curly");
	fighters.push_back("Genji");
	fighters.push_back("Optimus Prime");
	fighters.push_back("Thor");

	string fgtName;
	cout << "---Welcome to the arena!---\n\n---Do you think your fighter has what it---------\n---takes to defeat all 6 of our best fighters?---\n\n";
	cout << "What is the name of your fighter?: ";
	cin >> fgtName;

	cout << "\n";

	Fighter fighterTwo(100, fgtName);

	beatenBy = fighterLoop(fighters, fighterTwo);

	winner(fighterTwo, beatenBy);

	system("pause");
	return 0;
}
