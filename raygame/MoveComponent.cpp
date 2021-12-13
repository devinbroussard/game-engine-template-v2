#include "MoveComponent.h"
#include "Actor.h"
#include "Component.h"
#include "Character.h"

void MoveComponent::update(float deltaTime)
{
	MathLibrary::Vector2 oldPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 forward = getOwner()->getTransform()->getForward();

	//Add the new velocity to the old posiiton to get the new position
	MathLibrary::Vector2 newPosition = MathLibrary::Vector2((oldPosition.x + (m_velocity.x * deltaTime * forward.x)),
		(oldPosition.y + (m_maxSpeed * deltaTime * forward.y)));

	getOwner()->getTransform()->setLocalPosition(newPosition);
}