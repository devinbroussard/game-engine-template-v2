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
	MoveComponent* moveComponent = new MoveComponent(1);
	m_moveComponent = moveComponent;
	addComponent(m_moveComponent);
}

Agent::Agent(float x, float y, const char* name, float maxForce, float maxSpeed)
	: Actor(x, y, name){
	m_maxForce = maxForce;
	m_force = { 0, 0 };
	MoveComponent* moveComponent = new MoveComponent(maxSpeed);
	m_moveComponent = moveComponent;;
	addComponent(m_moveComponent);
}

void Agent::update(float deltaTime) {
	for (int i = 0; i < m_steeringBehaviors.getLength(); i++) {
		m_force = m_force + m_steeringBehaviors[i]->calculateForce(deltaTime);
	}

	if (m_force.getMagnitude() > m_maxForce)
		m_force = m_force.getNormalized() * m_maxForce;

	getMoveComponent()->setVelocity(getMoveComponent()->getVelocity() + m_force * deltaTime);
}

void Agent::onAddComponent(Component* component) {

	SteeringComponent* temp = dynamic_cast<SteeringComponent*>(component);
	//...and if successful...
	if (component) {
		m_steeringBehaviors.addItem(temp);
	}
}
