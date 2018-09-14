#include <iostream>
#include "Marine.h"

void Marine::setStats(int unitAtk, int unitHP)
{
	attack = unitAtk;
	health = unitHP;
}

void Marine::takeDamage(int damage)
{
	health -= damage;
}

bool Marine::isAlive()
{
	if (health <= 0)
	{
		return false;
	}
	return true;
}