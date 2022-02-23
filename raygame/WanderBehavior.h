#pragma once
#include "Component.h"
#include <Vector2.h>

class WanderBehavior :
	public Component {
public:
	WanderBehavior(float radius, float distance);
	~WanderBehavior() {};

	void setRadius(float radius) { m_radius = radius; }
	void setDistance(float distance) { m_distance = distance; }

	void update(float deltaTime) override;

private:
	float m_radius;
	float m_distance;
	float m_force;
	MathLibrary::Vector2 m_angle;
};

