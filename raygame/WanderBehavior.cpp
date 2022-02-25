#include "WanderBehavior.h"
#include "Actor.h"
#include "Transform2D.h"
#include <Vector2.h>
#include <time.h>
#include <iostream>
#include "MoveComponent.h"

WanderBehavior::WanderBehavior(float radius, float distance)
{
	std::srand((time(NULL)));
	m_radius = radius;
	m_distance = distance;
	m_force = 50;
	m_angle = { 0, 0 };
}

void WanderBehavior::update(float deltaTime)
{

	MathLibrary::Vector2 circlePos = getOwner()->getTransform()->getWorldPosition() + (getOwner()->getTransform()->getForward() * m_distance);

	float randX = (rand() % 400) - 200;
	float randY = (rand() % 400) - 200;


	MathLibrary::Vector2 randomPnt = MathLibrary::Vector2(randX, randY).getNormalized() * m_radius; 
	randomPnt = randomPnt + circlePos;


	MathLibrary::Vector2 angle =
		(randomPnt - getOwner()->getTransform()->getWorldPosition()).getNormalized() * m_force;

	//if ((m_angle - angle).getMagnitude() < 0.5f)
	//	angle = angle + MathLibrary::Vector2(0.2f, 0.8f);

	m_angle = angle;

	MoveComponent* moveComponent = dynamic_cast<MoveComponent*>(getOwner()->getComponent<MoveComponent>());

	getOwner()->getTransform()->setForward(m_angle);

	MathLibrary::Vector2 newVelocity = m_angle - moveComponent->getVelocity();

	moveComponent->setVelocity(moveComponent->getVelocity() + newVelocity * deltaTime);
}
