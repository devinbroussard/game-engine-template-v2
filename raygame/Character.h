#pragma once
#include "Actor.h"
#include <Vector2.h>


class Character :
	public Actor
{
public:
	Character(float x, float y, const char* name, float speed, int maxHealth);
	~Character();

	void start();
	void update(float deltaTime);
	void draw();

private:
	int m_speed;
	int m_maxHealth;
	float m_firingCooldown;
};


