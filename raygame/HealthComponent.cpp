#include "HealthComponent.h"

HealthComponent::HealthComponent(int maxHealth, Actor* owner) :
	Component::Component("Health Component")
{
	m_maxHealth = maxHealth;
	m_currentHealth = maxHealth;
	m_damageCooldown = 2;
	m_timeSinceDamage = 0;
}

HealthComponent::~HealthComponent()
{
}

void HealthComponent::start()
{
	m_currentHealth = m_maxHealth;
	m_timeSinceDamage = 10;
}

void HealthComponent::update(float deltaTime)
{
	m_timeSinceDamage += deltaTime;

	if (m_currentHealth <= 0)
		getOwner()->end();
}

void HealthComponent::onCollision(Actor* actor)
{
	if (actor->getName() == "Enemy")
	{
		m_currentHealth--;
		m_timeSinceDamage = 0;
	}
}
