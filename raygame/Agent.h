#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include <Vector2.h>

class MoveComponent;
class SteeringBehavior;

class Agent :
	public Actor {
public:
	Agent();
	~Agent();

	//Returns the target variable
	Actor* getTarget() { return m_target; } 
	MathLibrary::Vector2 getForce() { return m_force; }
	void setForce(MathLibrary::Vector2 force) { m_force = force; }

	void start() override;
	void update(float deltaTime) override;
	void onAddComponent(Component* component);

private:
	DynamicArray<SteeringBehavior*> m_steeringBehaviors;
	//An actor that the agent will seek or flee from
	Actor* m_target;
	float m_maxForce;
	float m_maxVelocity;
	MoveComponent* m_moveComponent;
	MathLibrary::Vector2 m_force;
};

