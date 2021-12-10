#pragma once
#include "Character.h"

class Enemy :
	public Character
{
public:
	Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor);
	~Enemy() {}

	void start() override;

private:
	Actor* m_targetActor;
};

