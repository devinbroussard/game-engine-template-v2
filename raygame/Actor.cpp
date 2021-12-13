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
    m_componentCount = 0;
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
    Actor* owner = component->getOwner();
    if (owner) return nullptr;

    component->assignOwner(this);
    Component** tempArray = new Component* [m_componentCount + 1];
    
    int j = 0;
    for (int i = 0; i < m_componentCount; i++)
    {
        tempArray[i] = m_components[i];
        j++;
    }

    //Set the last value in the new array to be the actor we want to add
    tempArray[j] = component;

    if (m_componentCount > 1)
        //Set old array to hold the values of the new array
        delete[] m_components;
    else if (m_componentCount == 1)
        delete m_components;

    m_componentCount++;
    m_components = tempArray;

	return component;
}

bool Actor::removeComponent(Component* component)
{
    if (!component) return false;
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
        delete[] m_components;
        m_components = newArray;
        m_componentCount--;
        delete component; 
    }
    else 
        delete[] newArray;

    //Return whether or not the removal was successful
    return componentRemoved;
}

bool Actor::removeComponent(const char* name)
{
    if (!name) return false;
    bool componentRemoved = false;
    Component* componentToDelete = nullptr;

    //Create a new array with a size one less than our old array
    Component** newArray = new Component * [m_componentCount - 1];
  
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        if (strcmp(m_components[i]->getName(), name) == 0)
        {
            newArray[j] = m_components[i];
            j++;
        }
        else
        {
            componentToDelete = m_components[i];
            componentRemoved = true;
        }
    }
    //Set the old array to the new array
    if (componentRemoved)
    {
        delete[] m_components;
        m_components = newArray;
        m_componentCount--;
        delete componentToDelete;
    }
    else 
        delete[] newArray;
    //Return whether or not the removal was successful
    return componentRemoved;
}

Component* Actor::getComponent(const char* name)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (strcmp(m_components[i]->getName(), name) == 0)
            return m_components[i];
    }
    return nullptr;
}

void Actor::update(float deltaTime)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        m_components[i]->update(deltaTime);
    }
}

void Actor::draw()
{
    for (int i = 0; i < m_componentCount; i++)
    {
        m_components[i]->draw();
    }
}

void Actor::end()
{
    m_started = false;
}

void Actor::onDestroy()
{
    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->onDestroy();

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