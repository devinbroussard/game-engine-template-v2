#include "FleeBehavior.h"
#include "Transform2D.h"
#include "Actor.h"
#include <Vector2.h>
#include "MoveComponent.h"
#include "SteeringComponent.h"

FleeBehavior::FleeBehavior(Actor* target, float fleeForce)
	: SteeringComponent(target) {
	m_target = target;
	m_fleeForce = fleeForce;
}

MathLibrary::Vector2 FleeBehavior::calculateForce(float deltaTime) {
	MathLibrary::Vector2 direction =
		(getOwner()->getTransform()->getWorldPosition() - getTarget()->getTransform()->getWorldPosition()).getNormalized() * m_fleeForce;

	MoveComponent* moveComponent = getOwner()->getComponent<MoveComponent>();

	MathLibrary::Vector2 newVelocity = direction - moveComponent->getVelocity();

	//moveComponent->setVelocity(moveComponent->getVelocity() + newVelocity * deltaTime);

	return newVelocity;
}