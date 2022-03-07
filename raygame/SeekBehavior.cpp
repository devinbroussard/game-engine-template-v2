#include "SeekBehavior.h"
#include "Transform2D.h"
#include "Actor.h"
#include <Vector2.h>
#include "MoveComponent.h"

SeekBehavior::SeekBehavior(Actor* target, float force) 
	: SteeringComponent(target) {
	m_target = target;
	m_seekForce = force;
}

MathLibrary::Vector2 SeekBehavior::calculateForce(float deltaTime)
{
	MathLibrary::Vector2 direction =
		(getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()).getNormalized() * m_seekForce;

	MoveComponent* moveComponent = getOwner()->getComponent<MoveComponent>();

	MathLibrary::Vector2 newVelocity = direction - moveComponent->getVelocity();

	//moveComponent->setVelocity(moveComponent->getVelocity() + newVelocity * deltaTime);
	return newVelocity; //Returns the velocity
}

void SeekBehavior::update(float deltaTime)
{

}
