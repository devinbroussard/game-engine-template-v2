#include "MoveComponent.h"
#include "Actor.h"
#include "Component.h"
#include "Character.h"

MoveComponent::MoveComponent(Actor* owner, float maxSpeed) :
	Component::Component(owner, "Move Component")
{
	m_maxSpeed = maxSpeed;
}

void MoveComponent::update(float deltaTime)
{
	MathLibrary::Vector2 position = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 movement = MathLibrary::Vector2((position.x + (m_maxSpeed * deltaTime * getOwner()->getTransform()->getForward().x)),(position.y + (m_maxSpeed * deltaTime * getOwner()->getTransform()->getForward().y)));

	getOwner()->getTransform()->setLocalPosition(movement);
}