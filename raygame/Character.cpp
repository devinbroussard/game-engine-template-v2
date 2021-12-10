#include "Character.h"
#include "HealthComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"

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
	HealthComponent* healthComponent = new HealthComponent(m_maxHealth, this);
	addComponent(healthComponent);
	MoveComponent* moveComponent = new MoveComponent(this, 0.1f);
	addComponent(moveComponent);
	SpriteComponent* spriteComponent = new SpriteComponent("Sprites/player.png", this);
	addComponent(spriteComponent);
}

void Character::update(float deltaTime)
{
	Actor::update(deltaTime);
}

void Character::draw()
{
	Actor::draw();
}
