#include <iostream>
#include "Entity.h"

void Entity::setStats(int unitAtk, int unitHP)
{
	attack = unitAtk;
	health = unitHP;
}

bool Entity::isAlive()
{
	return false;
}

void Entity::takeDamage(int damage)
{
	health -= damage;
}