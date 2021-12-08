#pragma once

class Actor;

class Component
{
public:
	Component();

	Component(Actor*, const char*);

	virtual ~Component();
	


	/// <summary>
	/// Returns the actor that owns the component
	/// </summary>
	/// <returns></returns>
	Actor* getOwner() { return m_owner; }

	/// <summary>
	/// Returns the component's name
	/// </summary>
	/// <returns></returns>
	const char* getName() { return m_name; }



	/// <summary>
	/// Called whenever the component is added onto its owner
	/// </summary>
	virtual void start() { m_started = true; }

	/// <summary>
	/// Called every frame by the owner
	/// </summary>
	/// <param name="deltaTime"></param>
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

