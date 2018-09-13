#include "Marine.h"



Marine::Marine()
{
	health = 50;
}


Marine::~Marine()
{
}

int Entity::attack()
{
	return 10;
}

void Entity::takeDamage(int damage)
{
	health -= damage;
}

// Is there a Marine Alive?
bool marineAlive(Marine * squadArr, size_t arrSize)
{
	return false;
}