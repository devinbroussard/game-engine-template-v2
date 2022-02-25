#include "FleeBehavior.h"
#include "Transform2D.h"
#include "Actor.h"
#include <Vector2.h>
#include "MoveComponent.h"

FleeBehavior::FleeBehavior(Actor* target)
{
	m_target = target;
	m_force = 200;
}

void FleeBehavior::update(float deltaTime)
{
	MathLibrary::Vector2 direction =
		(getOwner()->getTransform()->getWorldPosition() - getTarget()->getTransform()->getWorldPosition()).getNormalized() * m_force;

	MoveComponent* moveComponent = getOwner()->getComponent<MoveComponent>();

	MathLibrary::Vector2 newVelocity = direction - moveComponent->getVelocity();

	moveComponent->setVelocity(moveComponent->getVelocity() + newVelocity * deltaTime);
}
