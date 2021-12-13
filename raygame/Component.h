#pragma once

class Actor;

class Component
{
public:
	Component();

	Component(const char*);

	virtual ~Component();
	


	/// <summary>
	/// Returns the actor that owns the component
	/// </summary>
	/// <returns></returns>
	/// 
	Actor* getOwner() { return m_owner; }

	/// <summary>
	/// Assigns the owner of this component if it doesn't already have one
	/// </summary>
	/// <param name="owner">The new owner of this component</param>
	void assignOwner(Actor* owner) { if (!getOwner()) m_owner = owner; }

	/// <summary>
	/// Returns the component's name
	/// </summary>
	const char* getName() { return m_name; }

	/// <summary>
	/// Returns whether or not the component has been started
	/// </summary>
	bool getStarted() { return m_started; }

	//Functions called by actor class:
	/// <summary>
	/// Called whenever the component is added onto its owner
	/// </summary>
	virtual void start() { m_started = true; }

	/// <summary>
	/// Called every frame by the owner
	/// </summary>
	/// <param name="deltaTime">The time that has passed between frames</param>
	virtual void update(float deltaTime) {}

	/// <summary>
	/// Called every frame by the owner
	/// </summary>
	virtual void draw() {}

	/// <summary>
	/// Called whenver the owner's end function is called
	/// </summary>
	virtual void end() {}

	/// <summary>
	/// Called whenever the owner collides with another actor
	/// </summary>
	/// <param name="actor"></param>
	virtual void onCollision(Actor* actor) {}

	/// <summary>
	/// Called whenever the component is deleted
	/// </summary>
	virtual void onDestroy() {};

private:
	/// <summary>
	/// The Actor that owns this component
	/// </summary>
	Actor* m_owner;

	/// <summary>
	/// The name of the component
	/// </summary>
	const char* m_name;

	/// <summary>
	/// Stores whether or not the start function has been called
	/// </summary>
	bool m_started;
};

