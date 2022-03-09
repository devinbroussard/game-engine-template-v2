#include "Enemy.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"
#include "StateMachineComponent.h"
#include "FleeBehavior.h"

Enemy::Enemy(float x, float y, const char* name, float speed, int maxHealth, float maxForce, Actor* targetActor) :
	Character::Character(x, y, name, speed, maxHealth, maxForce)
{
	m_targetActor = targetActor;
}

void Enemy::start()
{
	Character::start();
	SeekBehavior* seekBehavior = new SeekBehavior(m_targetActor, 100);
	addComponent(seekBehavior);
	onAddComponent(seekBehavior);

	WanderBehavior* wanderBehavior = new WanderBehavior(10, 100, 80);
	addComponent(wanderBehavior);
	onAddComponent(wanderBehavior);

	FleeBehavior* fleeBehavior = new FleeBehavior(m_targetActor, 200);
	addComponent(fleeBehavior);
	onAddComponent(fleeBehavior);

	StateMachineComponent* stateMachineComponent = new StateMachineComponent();
	addComponent(stateMachineComponent);
}
