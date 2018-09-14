#pragma once
#include "Entity.h"

class Zergling : public Entity
{
public:

	void setStats(int attack, int health);
	void takeDamage(int damage);
	bool isAlive();

};

