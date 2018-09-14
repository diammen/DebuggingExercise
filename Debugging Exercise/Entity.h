#pragma once
class Entity
{
public:

	int attack;
	int health;

	virtual void setStats(int attack, int health);
	virtual void takeDamage(int damage);
	virtual bool isAlive();


};

