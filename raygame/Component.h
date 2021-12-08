#pragma once

class Actor;

class Component
{
public:
	Component();
	Component(Actor*, const char*);
	virtual ~Component();
	
	Actor* getOwner() { return m_owner; }
	const char* getName() { return m_name; }

	virtual void start() { m_started = true; }
	virtual void update(float deltaTime) {}
	virtual void draw() {}
	virtual void end() {}
	virtual void onCollision(Actor* actor) {}

private:
	Actor* m_owner;
	const char* m_name;
	bool m_started;
};

