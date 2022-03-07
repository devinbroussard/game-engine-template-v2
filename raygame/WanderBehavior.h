#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>

class WanderBehavior :
	public SteeringComponent {
public:
	WanderBehavior(float radius, float distance, float wanderForce); //Sets the variables of the behavior to the values given
	~WanderBehavior() {};

	void setRadius(float radius) { m_radius = radius; }
	float getRadius() { return m_radius; }
	void setDistance(float distance) { m_distance = distance; }
	float getDistance() { return m_distance; }
	void setForce(float wanderForce) { m_wanderForce = wanderForce; }
	float getForce() { return m_wanderForce; }

	MathLibrary::Vector2 calculateForce(float deltaTime) override;

private:
	float m_radius;
	float m_distance;
	float m_wanderForce;
	MathLibrary::Vector2 m_angle;
};

