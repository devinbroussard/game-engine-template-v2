#include "HealthComponent.h"

HealthComponent::HealthComponent(int maxHealth, Actor* owner) :
	Component::Component(owner, "Health Component")
{
	m_maxHealth = maxHealth;
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
