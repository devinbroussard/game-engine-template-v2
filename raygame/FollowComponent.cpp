#include "FollowComponent.h"
#include "Actor.h"
#include <Vector2.h>
#include "Transform2D.h"

FollowComponent::FollowComponent(Actor* owner, const char* name, Actor* targetActor) :
	Component::Component(                                                                                                                                                            name)
{
	m_targetActor = targetActor;
}

void FollowComponent::update(float deltaTime)
{
	MathLibrary::Vector2 targetDirection = (m_targetActor->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()).getNormalized();

	getOwner()->getTransform()->setForward(targetDirection);
}
