#include "Enemy.h"
#include "SeekBehavior.h"

Enemy::Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor) :
	Character::Character(x, y, name, speed, maxHealth)
{
	m_targetActor = targetActor;
}

void Enemy::start()
{
	Character::start();
	SeekBehavior* seekBehavior = new SeekBehavior(m_targetActor, 200);

}
