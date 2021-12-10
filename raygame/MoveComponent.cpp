#include "MoveComponent.h"
#include "Actor.h"
#include "Component.h"

MoveComponent::MoveComponent(Actor* owner, float maxSpeed) :
	Component::Component(owner, "Move Component")
{
	m_maxSpeed = maxSpeed;
}

void MoveComponent::update(float deltaTime)
{
	MathLibrary::Vector2 moveDirection = moveDirection.getNormalized();
	MathLibrary::Vector2 position = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 movement = MathLibrary::Vector2((position.x + moveDirection.x * m_maxSpeed * deltaTime),(position.y + moveDirection.y * m_maxSpeed * deltaTime));

	getOwner()->getTransform()->setLocalPosition(movement);
}