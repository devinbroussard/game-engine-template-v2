#pragma once
#include "Component.h"
#include <Vector2.h>

class SteeringComponent :
	public Component {
public:
	SteeringComponent(Actor* target); //Assigns a target to the m_target variable

	virtual MathLibrary::Vector2 calculateForce(float deltaTime) {} //Calculates the force that will be applied to the actor and returns it

private:
	MathLibrary::Vector2 m_force; //The force that will be applied to the player
	Actor* m_target; //The actor this component will target
};

