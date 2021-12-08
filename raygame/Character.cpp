#include "Character.h"
#include "HealthComponent.h"
#include "MoveComponent.h"

Character::Character(float x, float y, const char* name, float speed, int maxHealth) :
	Actor::Actor(x, y, name)
{
	m_speed = speed;
	m_firingCooldown = 0.3f;
	m_maxHealth = maxHealth;
}

Character::~Character()
{
}

void Character::start()
{
	HealthComponent* healthComponent = new HealthComponent(m_maxHealth);
	addComponent(healthComponent);
	MoveComponent* moveComponent = new MoveComponent(this, 4);
}

void Character::update(float deltaTime)
{
}
