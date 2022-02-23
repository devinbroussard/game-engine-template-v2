#pragma once
#include "Component.h"
class FleeBehavior :
	public Component {
public:
	FleeBehavior(Actor* m_target);
	~FleeBehavior() {}//Deallocates memory 

	void setTarget(Actor* target) { m_target = target; }
	Actor* getTarget() const { return m_target; }

	void setForce(float force) { m_force = force; }

	void update(float deltaTime) override;

private:
	Actor* m_target;
	float m_force;
};

