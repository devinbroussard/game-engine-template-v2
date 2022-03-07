#pragma once
#include "Component.h"
#include <Vector2.h>

class SteeringComponent :
	public Component {
public:
	SteeringComponent(); //Assigns default values to variables
	SteeringComponent(Actor* target); //Assigns a target to the m_target variable

	Actor* getTarget() { return m_target; } //Returns the current target
	void setTarget(Actor* target) { m_target = target; } //Changes the target to the one given

	//Calculates the force that will be applied to the actor and returns it
	virtual MathLibrary::Vector2 calculateForce(float deltaTime) abstract;

private:
	MathLibrary::Vector2 m_force = { 0, 0 }; //The force that will be applied to the player
	Actor* m_target = nullptr; //The actor this component will target
};

