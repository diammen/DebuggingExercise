#include <iostream>
#include "Zergling.h"

void Zergling::setStats(int unitAtk, int unitHP)
{
	attack = unitAtk;
	health = unitHP;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}

bool Zergling::isAlive()
{
	if (health <= 0)
	{
		return false;
	}
	return true;
}