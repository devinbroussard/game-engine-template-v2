#include "StateMachineComponent.h"
#include "Actor.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"
#include "FleeBehavior.h"
#include "Transform2D.h"
#include <Vector2.h>

StateMachineComponent::StateMachineComponent() 
	:Component("StateMachineComponent")
{
}

void StateMachineComponent::start() {
	m_seekComponent = getOwner()->getComponent<SeekBehavior>();
	m_fleeComponent = getOwner()->getComponent<FleeBehavior>();
	m_wanderComponent = getOwner()->getComponent<WanderBehavior>();
	m_seekForce = m_seekComponent->getForce();
	m_wanderForce = m_wanderComponent->getForce();
	m_fleeForce = m_fleeComponent->getForce();
	m_currentState = IDLE;
	Component::start();
}

void StateMachineComponent::update(float deltaTime) {

	MathLibrary::Vector2 targetPos = m_seekComponent->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();

	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();
	bool targetInRange = distanceFromTarget <= m_seekRange;
	switch (m_currentState) {
	case IDLE:
		m_seekComponent->setForce(0);
		m_wanderComponent->setForce(0);
		m_fleeComponent->setForce(0);

		if (targetInRange)
			setCurrentState(SEEK);

		break;
	case WANDER:
		m_wanderComponent->setForce(m_wanderForce);
		m_seekComponent->setForce(0);
		m_fleeComponent->setForce(0);

		if (targetInRange)
			setCurrentState(SEEK);

		break;
	case SEEK:
		m_wanderComponent->setForce(0);
		m_fleeComponent->setForce(0);
		m_seekComponent->setForce(m_seekForce);

		if (!targetInRange)
			setCurrentState(WANDER);

		break;
	case FLEE:
		m_fleeComponent->setForce(m_fleeForce);
		m_seekComponent->setForce(0);
		m_wanderComponent->setForce(0);

		break;
	}
}
