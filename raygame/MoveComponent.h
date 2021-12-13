#pragma once
#include "Component.h"
#include <Vector2.h>
#include "Transform2D.h"

class MoveComponent :
	public Component
{
public:
	MoveComponent(Actor* owner, const char* name = "MoveComponent") : Component::Component(name) { m_maxSpeed = 0; }

	/// <summary>
	/// Gets the current speed and directino of this actor
	/// </summary>
	/// <returns></returns>
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	/// <summary>
	/// Set the current speed and direction of this actor
	/// </summary>
	/// <param name="velocity"></param>
	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }

	/// <summary>
	/// Get the maximum magnitude of this actors velocity vector
	/// </summary>
	/// <returns></returns>
	float getMaxSpeed() { return m_maxSpeed; }
	/// <summary>
	/// Set the maximum magnitude of this actors velocity vector
	/// </summary>
	/// <param name="maxSpeed"></param>
	void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }

	void update(float deltaTime) override;

private:
	MathLibrary::Vector2 m_velocity;
	float m_maxSpeed;
};

