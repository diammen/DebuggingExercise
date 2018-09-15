// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Marine.h"
#include "Zergling.h"

using std::cout;
using std::endl;

using namespace std::chrono_literals;
using namespace std::this_thread;

// Is there a zergling Alive
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	int counter = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		if (swarmArr[i].health == 0)
		{
			counter++;
		}
	}
	if (counter >= arrSize)
	{
		return false;
	}
	return true;
}

// Is there a Marine Alive?
bool marineAlive(Marine * squadArr, size_t arrSize)
{
	int counter = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		if (squadArr[i].health == 0)
		{
			counter++;
		}
	}
	if (counter >= arrSize)
	{
		return false;
	}
	return true;
}

int main()
{
	Marine squad[10];
	Zergling swarm[10];

	int squadSize = 10;
	int squadCount = squadSize;
	int squadTarget = 0;

	int swarmSize = 15;

	int unitAtk = 10;
	int unitHP = 10;
	int swarmAtk = 1;
	int swarmHP = 1;


	// Set stats for each faction
	for (int i = 0; i < squadSize; ++i)
	{
		squad[i].attack = unitAtk;
		squad[i].health = unitHP;
	}
	for (int i = 0; i < swarmSize; ++i)
	{
		swarm[i].setStats(swarmAtk, swarmHP);
	}

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad, squadSize) && zerglingAlive(swarm, swarmSize)) // If anyone is left alive to fight . . .
	{
		if (marineAlive(squad, squadSize)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squadSize; i++) // go through the squad
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad[i].attack << " damage. " << endl;
				int damage = squad[i].attack;
				swarm[squadTarget].takeDamage(damage);
				sleep_for(0.5s);
				if (!swarm[i].isAlive()) // if the zergling dies, it is marked as such
				{
					cout << "The zergling target dies" << endl;
					squadTarget++;
				}
			}
		}
		sleep_for(1.5s);
		if (zerglingAlive(swarm, swarmSize)) // if there's at least one zergling alive
		{
			for (size_t i = 0; i < squadSize; i++) // loop through zerglings
			{
				cout << "A zergling attacks for " << swarm[i].attack << " damage." << endl;
				squad[i].takeDamage(swarm[i].attack);
				sleep_for(0.5s);
				if (!squad[i].isAlive())
				{
					squadCount--;
					cout << "The marine succumbs to his wounds." << endl;
					cout << "There are " << squadCount << " marines left." << endl;
				}
			}
		}
	}
	sleep_for(1s);
	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad, squadSize))
	{
		cout << "The Marines win." << endl;
	}
	else
	{
		cout << "The Zerg win." << endl;
	}
	sleep_for(1.5s);
	return 0;
}