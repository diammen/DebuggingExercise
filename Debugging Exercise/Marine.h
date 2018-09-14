#pragma once
#include "Entity.h"

class Marine : public Entity
{
public:
	void setStats(int unitAtk, int unitHP);
	void takeDamage(int damage);
	bool isAlive();
};

