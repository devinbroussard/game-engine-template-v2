#include "Enemy.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"

Enemy::Enemy(float x, float y, const char* name, float speed, int maxHealth, float maxForce, Actor* targetActor) :
	Character::Character(x, y, name, speed, maxHealth, maxForce)
{
	m_targetActor = targetActor;
}

void Enemy::start()
{
	Character::start();
	//SeekBehavior* seekBehavior = new SeekBehavior(m_targetActor, 200);
	//addComponent(seekBehavior);
	//onAddComponent(seekBehavior);

	WanderBehavior* wanderBehavior = new WanderBehavior(20, 20, 20);
	addComponent(wanderBehavior);
	onAddComponent(wanderBehavior);
}
