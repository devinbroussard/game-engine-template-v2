#include "Enemy.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"
#include "StateMachineComponent.h"
#include "FleeBehavior.h"
#include "Transform2D.h"
#include "IdleDecision.h"
#include "SeekDecision.h"
#include "WanderDecision.h"
#include "InRangeDecision.h"
#include "AggressiveDecision.h"
#include "DecisionComponent.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <Vector2.h>

Enemy::Enemy(float x, float y, const char* name, float speed, int maxHealth, float maxForce, Actor* targetActor) :
	Character::Character(x, y, name, speed, maxHealth, maxForce)
{
	m_targetActor = targetActor;
}

bool Enemy::getTargetInView()
{
	MathLibrary::Vector2 directionOfTarget = (m_targetActor->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getNormalized();
	float distance = (m_targetActor->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
	float coneValue = acos(MathLibrary::Vector2::dotProduct(directionOfTarget, getTransform()->getForward()));

	return (coneValue < 1);
}

bool Enemy::getTargetInRange()
{
	float distance = (m_targetActor->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
	return distance <= 100;
}

void Enemy::start()
{
	Character::start();
	SeekBehavior* seekBehavior = new SeekBehavior(m_targetActor, 100);
	addComponent(seekBehavior);
	onAddComponent(seekBehavior);

	WanderBehavior* wanderBehavior = new WanderBehavior(12, 1500, 120);
	addComponent(wanderBehavior);
	onAddComponent(wanderBehavior);

	FleeBehavior* fleeBehavior = new FleeBehavior(m_targetActor, 200);
	addComponent(fleeBehavior);
	onAddComponent(fleeBehavior);

	IdleDecision* idleDecision = new IdleDecision();
	WanderDecision* wanderDecision = new WanderDecision();
	SeekDecision* seekDecision = new SeekDecision();

	AggressiveDecision* aggressive = new AggressiveDecision(idleDecision, wanderDecision);
	InRangeDecision* inRange = new InRangeDecision(aggressive, seekDecision);

	addComponent(new DecisionComponent(inRange));
	

	/*StateMachineComponent* stateMachineComponent = new StateMachineComponent();
	addComponent(stateMachineComponent);*/
}
