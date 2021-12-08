#pragma once
#include "Component.h"
#include <Vector2.h>
#include "Transform2D.h"

class MoveComponent :
	public Component
{
public:
	MoveComponent(Actor* owner, float maxSpeed);

	MathLibrary::Vector2 getVelocity() { return m_velocity; }
	float getMaxSpeed() { return m_maxSpeed; }
	void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }
	MathLibrary::Vector2 getDirection() { return m_direction; }
	MathLibrary::Vector2 setDirection(MathLibrary::Vector2 direction) { m_direction = direction; }

	void update(float deltaTime) override;

private:
	MathLibrary::Vector2 m_velocity;
	MathLibrary::Vector2 m_direction;
	float m_maxSpeed;
};

