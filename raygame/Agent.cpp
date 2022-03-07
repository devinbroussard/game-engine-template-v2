#include "Agent.h"
#include "WanderBehavior.h"
#include "SeekBehavior.h"
#include "FleeBehavior.h"
#include "SteeringComponent.h"
#include "MoveComponent.h"

Agent::Agent()
	: Actor(){
	m_force = { 0, 0 };
	m_maxForce = 1;
	m_moveComponent = new MoveComponent(); 
}

Agent::Agent(float maxForce)
	: Actor(){
	m_maxForce = maxForce;
	m_force = { 0, 0 };
	m_moveComponent = new MoveComponent();
}

void Agent::onAddComponent(Component* component) {
	SteeringComponent* temp = dynamic_cast<SteeringComponent*>(component);
	//...and if successful...
	if (component) {
		m_steeringBehaviors.addItem(temp);
	}
}
