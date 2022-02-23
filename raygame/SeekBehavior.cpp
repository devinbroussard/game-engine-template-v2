#include "SeekBehavior.h"
#include "Transform2D.h"
#include "Actor.h"
#include <Vector2.h>
#include "MoveComponent.h"

SeekBehavior::SeekBehavior(Actor* target) {
	m_target = target;
	m_force = 200;
}

void SeekBehavior::update(float deltaTime)
{
	MathLibrary::Vector2 direction =
		(getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()).getNormalized() * m_force;

	MoveComponent* moveComponent = dynamic_cast<MoveComponent*>(getOwner()->getComponent("MoveComponent"));

	MathLibrary::Vector2 newVelocity = direction - moveComponent->getVelocity();
	
	moveComponent->setVelocity(moveComponent->getVelocity() + newVelocity * deltaTime);
}
