#include "MoveComponent.h"
#include "Actor.h"
#include "Component.h"
#include "Character.h"
#include "Engine.h"

MoveComponent::MoveComponent(float maxSpeed, const char* name) : Component::Component(name)
{
	m_maxSpeed = maxSpeed;
	m_velocity = MathLibrary::Vector2(0, 0);
}

void MoveComponent::update(float deltaTime)
{
	float xEnd = Engine::getScreenWidth() + 5;
	float yEnd = Engine::getScreenHeight() + 5;

	if (getOwner()->getTransform()->getWorldPosition().x > Engine::getScreenWidth() + 5)
		getOwner()->getTransform()->setWorldPostion({ 0, getOwner()->getTransform()->getWorldPosition().y });
	if (getOwner()->getTransform()->getWorldPosition().x < -10)
		getOwner()->getTransform()->setWorldPostion({ xEnd, getOwner()->getTransform()->getWorldPosition().y });
	if (getOwner()->getTransform()->getWorldPosition().y > Engine::getScreenHeight() + 5)
		getOwner()->getTransform()->setWorldPostion({ getOwner()->getTransform()->getWorldPosition().x, -5 });
	if (getOwner()->getTransform()->getWorldPosition().y < -10)
		getOwner()->getTransform()->setWorldPostion({ getOwner()->getTransform()->getWorldPosition().x, yEnd });

	if (m_velocity.getMagnitude() > m_maxSpeed) {
		m_velocity = m_velocity.getNormalized() * m_maxSpeed;
	}

	MathLibrary::Vector2 oldPosition = getOwner()->getTransform()->getLocalPosition();

	//Add the new velocity to the old posiiton to get the new position
	MathLibrary::Vector2 newPosition = MathLibrary::Vector2((oldPosition.x + (m_velocity.x * deltaTime)),
		(oldPosition.y + (m_velocity.y * deltaTime)));

	if (getVelocity().getMagnitude() > 20)
		getOwner()->getTransform()->setForward(getVelocity());

	if (newPosition.getMagnitude() > 0)
		getOwner()->getTransform()->setLocalPosition(newPosition);
}