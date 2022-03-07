#include "Character.h"
#include "HealthComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"

Character::Character(float x, float y, const char* name, float speed, int maxHealth, float maxForce) :
	Agent(x, y, name, maxForce, speed)
{
	m_speed = speed;
	m_firingCooldown = 0.3f;
	m_maxHealth = maxHealth;
}

Character::~Character()
{
}

void Character::setVelocity(float x, float y)
{
}

/// <summary>
/// Adds all of the character's components to its components array
/// </summary>
void Character::start()
{
	HealthComponent* healthComponent = dynamic_cast<HealthComponent*>(addComponent(new HealthComponent(m_maxHealth, this)));
	SpriteComponent* spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Sprites/player.png")));

	Actor::start();
}

/// <summary>
/// Called every frame
/// </summary>
/// <param name="deltaTime">The amount of time that has passed between frames</param>
void Character::update(float deltaTime)
{
	Agent::update(deltaTime);
	Actor::update(deltaTime);
}

/// <summary>
/// Called every frame
/// </summary>
void Character::draw()
{
	Actor::draw();
}
