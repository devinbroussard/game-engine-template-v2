#include "Scene.h"
#include "Transform2D.h"
#include "DynamicArray.h"

Scene::Scene()
{
    m_actorCount = 0;
    m_actors = DynamicArray<Actor*>();
    m_world = new MathLibrary::Matrix3();
}

MathLibrary::Matrix3* Scene::getWorld()
{
    return m_world;
}

void Scene::addUIElement(Actor* actor)
{
    m_UIElements.addItem(actor);

    //Adds all children of the UI to the scene
    for (int i = 0; i < actor->getTransform()->getChildCount(); i++)
    {
        m_UIElements.addItem(actor->getTransform()->getChildren()[i]->getOwner());
    }
}

bool Scene::removeUIElement(int index)
{
    Actor* item = m_UIElements.getItem(index);
    return m_UIElements.removeItem(item);
}

bool Scene::removeUIElement(Actor* actor)
{
    return m_UIElements.removeItem(actor);
}

void Scene::addActor(Actor* actor)
{
    m_actors.addItem(actor);

    //Adds all children of the actor to the scene
    for (int i = 0; i < actor->getTransform()->getChildCount(); i++)
    {
        m_actors.addItem(actor->getTransform()->getChildren()[i]->getOwner());
    }
}

bool Scene::removeActor(int index)
{
    Actor* item = m_actors.getItem(index);
    return m_actors.removeItem(item);
}

bool Scene::removeActor(Actor* actor)
{
    return m_actors.removeItem(actor);
}

void Scene::start()
{
    m_started = true;
}

void Scene::update(float deltaTime)
{
    //Updates all actors
    for (int i = 0; i < m_actors.getLength(); i++)
    {
        if (!m_actors.getItem(i)->getStarted())
            m_actors.getItem(i)->start();

        m_actors.getItem(i)->update(deltaTime);
    }

    //Checks collision for all actors
    for (int i = 0; i < m_actors.getLength(); i++)
    {
        for (int j = 0; j < m_actors.getLength(); j++)
        {
            if (m_actors.getItem(i)->checkForCollision(m_actors.getItem(j)) && j != i && m_actors.getItem(j)->getStarted())
                m_actors.getItem(i)->onCollision(m_actors.getItem(j));
        }
    }
}

void Scene::updateUI(float deltaTime)
{
    //Calls update for all actors in UI array
    for (int i = 0; i < m_UIElements.getLength(); i++)
    {
        if (!m_UIElements.getItem(i)->getStarted())
            m_UIElements.getItem(i)->start();

        m_UIElements.getItem(i)->update(deltaTime);
    }
}

void Scene::draw()
{
    //Calls draw for all actors in the array
    for (int i = 0; i < m_actors.getLength(); i++)
    {
        m_actors.getItem(i)->draw();
    }
}

void Scene::drawUI()
{
    //Calls draw for all actors in UI array
    for (int i = 0; i < m_UIElements.getLength(); i++)
    {
        m_UIElements.getItem(i)->draw();
    }
}

void Scene::end()
{
    //Calls end for all actors in the array
    for (int i = 0; i < m_actors.getLength(); i++)
    {
        if (m_actors.getItem(i)->getStarted())
            m_actors.getItem(i)->end();
    }

    m_started = false;
}