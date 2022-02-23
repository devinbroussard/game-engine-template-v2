#pragma once
class Transform2D;
class Collider;
class Component;

class Actor
{
public:
    Actor();
    ~Actor();

    /// <param componentName="x">Position on the x axis</param>
    /// <param componentName="y">Position on the y axis</param>
    /// <param componentName="componentName">The componentName of this actor.</param>
    Actor(float x, float y, const char* name);

    /// <summary>
    /// </summary>
    /// <returns>If the actors start function has been called.</returns>
    bool getStarted() { return m_started; }

    /// <returns> The transform attached to this actor.</returns>
    Transform2D* getTransform() { return m_transform; }

    /// <summary>
    /// Gets the collider attached to this actor
    /// </summary>
    Collider* getCollider() { return m_collider; }

    /// <summary>
    /// Sets this actors collider
    /// </summary>
    /// <param componentName="collider">The new collider to attach to the actor</param>
    void setCollider(Collider* collider) { m_collider = collider; }

    /// <summary>
    /// Gets the componentName of this actor
    /// </summary>
    /// <returns></returns>
    const char* getName() { return m_name; }

    /// <summary>
    /// Sets the actor's componentName
    /// </summary>
    /// <param componentName="componentName"></param>
    /// <returns></returns>
    const char* setName(const char* name) { m_name = name; }

    /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    virtual void start();

    /// <summary>
    /// Called every frame
    /// </summary>
    /// <param componentName="deltaTime">The time that has passed from the previous frame to the current</param>
    virtual void update(float deltaTime);

    /// <summary>
    /// Called every loop to update on screen visuals
    /// </summary>
    virtual void draw();

    /// <summary>
    /// Called when this actor is removed from the scene
    /// </summary>
    virtual void end();

    /// <summary>
    /// Called when this actor is destroyed 
    /// </summary>
    virtual void onDestroy();

    /// <summary>
    /// Checks if a collision occured between this actor and another
    /// </summary>
    /// <param componentName="other">The actor to check collision against</param>
    virtual bool checkForCollision(Actor* other);

    /// <summary>
    /// Called when a collision between this actor and another occurs. 
    /// </summary>
    /// <param componentName="other">The actor this actor collided with.</param>
    virtual void onCollision(Actor* other);

    /// <summary>
    /// Adds a component to the actor's components array
    /// </summary>
    /// <param componentName="component"></param>
    /// <returns></returns>
    Component* addComponent(Component* component);
    
    template<typename T>
    T* addComponent();

    /// <summary>
    /// Removes a component from the actor's components array if the component pointer matches the given pointer
    /// </summary>
    /// <param componentName="component">The component pointer that you want to remove</param>
    /// <returns>Whether or not the component was removed from the array</returns>
    bool removeComponent(Component* component);

    /// <summary>
    /// Removes a component from the actor's component array if the compent's componentName matches the given componentName
    /// </summary>
    /// <param componentName="componentName">The componentName of the component pointer you wish to delete</param>
    /// <returns>Whether or no thte component was removed from the array</returns>
    template<typename T>
    bool removeComponent();

    /// <summary>
    /// Creates a component pointer from the pointer in the actor's array that matches the componentName given
    /// </summary>
    /// <param componentName="componentName">The componentName of the component you wish to get</param>
    template<typename T>
    T* getComponent();


protected:
    const char* m_name;

private:
    bool m_started;
    Transform2D* m_transform;
    Collider* m_collider;
    Component** m_components;
    unsigned int m_componentCount;
};

template<typename T>
inline T* Actor::addComponent()
{
    T* component = new T();

    Actor* owner = component->getOwner();
    if (owner) return nullptr;

    component->assignOwner(this);
    Component** tempArray = new Component * [m_componentCount + 1];

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

    return (T*)component;
}

template<typename T>
inline bool Actor::removeComponent()
{
    bool componentRemoved = false;
    //Create a new array with a size one less than our old array
    Component** newArray = new Component * [m_componentCount - 1];
    T* temp;
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        T* temp = dynamic_cast<T*>(m_components[i]);

        if (!temp)
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
        delete temp;
    }
    else
        delete[] newArray;

    //Return whether or not the removal was successful
    return componentRemoved;
}

template<typename T>
inline T* Actor::getComponent()
{
    //For each component in the components array...
    for (int i = 0; i < m_componentCount; i++) {
        //...try casting the component as the given type...
        T* temp = dynamic_cast<T*>(m_components[i]);
        //...and if successful...
        if (temp)
            //...return the component

            return (T*)m_components[i];
    }

    //Returns nulllptr if no component matched
    return nullptr;
}
