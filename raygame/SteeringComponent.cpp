#include "SteeringComponent.h"

SteeringComponent::SteeringComponent(Actor* target) {
	m_force = { 0, 0 }; //Sets m_force to be nothing
	m_target = target; //Assigns the target variable a target
}


