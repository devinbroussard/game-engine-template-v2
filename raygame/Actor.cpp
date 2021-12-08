#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

void Actor::start()
{
    m_started = true;
}

void Actor::onCollision(Actor* other)
{
}

Component* Actor::addComponent(Component* component)
{
    if (component->getOwner != nullptr)
        return nullptr;

    Component** tempArray = new Component* [m_componentCount + 1];
    
    int j = 0;
    for (int i = 0; i < m_componentCount; i++)
    {
        tempArray[i] = m_components[i];
        j++;
    }

    tempArray[j] = component;
    m_componentCount + 1;
    m_components = tempArray;

	return component;
}

bool Actor::removeComponent(Component* component)
{
    if (component->getOwner != nullptr)
        return false;

    bool componentRemoved = false;
    //Create a new array with a size one less than our old array
    Component** newArray = new Component* [m_componentCount - 1];

    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        if (component != m_components[i])
        {
            newArray[j] = m_components[i];
            j++;
        }
        else
        {
            componentRemoved = true;
        }
    }
    //Set the old array to the new array
    if (componentRemoved)
    {
        m_components = newArray;
        m_componentCount--;
    }
    //Return whether or not the removal was successful
    return componentRemoved;
}

Component* Actor::getComponent(const char* name)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (m_components[i]->getName() == name)
            return m_components[i];
    }
    return nullptr;
}

void Actor::update(float deltaTime)
{
}

void Actor::draw()
{
}

void Actor::end()
{
    m_started = false;
}

void Actor::onDestroy()
{
    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}