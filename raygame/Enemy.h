#pragma once
#include "Character.h"

class Enemy :
	public Character
{
public:
	Enemy(float x, float y, const char* name, float speed, int maxHealth, float maxForce, Actor* targetActor);
	~Enemy() {}

	bool getTargetInRange();
	bool getIsAggressive() { return m_isAggressive; }
	void setIsAggressive(bool value) { m_isAggressive = value; }

	void start() override; //Initializes any used components

private:
	bool m_isAggressive;
	Actor* m_targetActor;
};

