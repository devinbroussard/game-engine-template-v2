#include "Component.h"

Component::Component()
{
	m_owner = nullptr;
	m_name = "Null";
	m_started = false;
}

Component::Component(Actor* actor, const char* name)
{
	m_owner = actor;
	m_name = name;
	m_started = false;
}

Component::~Component()
{
}

