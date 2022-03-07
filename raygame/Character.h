#pragma once
#include "Agent.h"
#include <Vector2.h>
class MoveComponent;

class Character :
	public Agent
{
public:
	Character(float x, float y, const char* name, float speed, int maxHealth, float maxForce);
	~Character();

	void setVelocity(float x, float y);
	float getSpeed() { return m_speed; }
	void setSpeed(float speed) { m_speed = speed; }

	MoveComponent* getMoveComponent() { return m_moveComponent; }


	void start();
	void update(float deltaTime);
	void draw();

private:
	MathLibrary::Vector2 m_velocity;
	MoveComponent* m_moveComponent;

	float m_speed;
	int m_maxHealth;
	float m_firingCooldown;

};


