#include "SteeringComponent.h"

SteeringComponent::SteeringComponent()
{
	m_force = { 0,0 }; //Sets force to be nothing
	m_target = nullptr; //Assigns target to be nullptr
}

SteeringComponent::SteeringComponent(Actor* target) {
	m_force = { 0, 0 }; //Sets force to be nothing
	m_target = target; //Assigns the target variable a target
}


