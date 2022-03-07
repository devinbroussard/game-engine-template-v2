#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include <Vector2.h>

class MoveComponent;
class SteeringComponent;
class MoveComponent;

class Agent :
	public Actor {
public:
	Agent(); //Sets default values to variables
	Agent(float x, float y, const char* name, float maxForce, float maxSpeed); //Sets the max force to the value given
	~Agent() {} //Deallocates memory used in agent

	MathLibrary::Vector2 getForce() { return m_force; } //Returns the current force vector
	void setForce(MathLibrary::Vector2 force) { m_force = force; } //Changes the force to the force given
	float getMaxForce() { return m_maxForce; }
	void setMaxForce(float maxForce) { m_maxForce = maxForce; }
	MoveComponent* getMoveComponent() { return m_moveComponent; } //Returns a pointer to the move component

	virtual void start() override {} //Calls the Actor's start function
	virtual void update(float deltaTime) override;  //Gets the sum of all forces acting on the agent and applies it to its velocity
	virtual void onAddComponent(Component* component) override; //Checks to see what component was added, and acts accordingly

private:
	DynamicArray<SteeringComponent*> m_steeringBehaviors; //An array holding this agent's steering behaviors
	float m_maxForce; //The magnitude that the m_wanderForce vector will be capped at
	MoveComponent* m_moveComponent; //A pointer to this agent's move component
	MathLibrary::Vector2 m_force; //The sum of all the forces acting on this agent
};

