#pragma once
#include "Component.h"
class FollowComponent :
	public Component
{
public:
	FollowComponent(Actor* owner, const char* name, Actor* targetActor);

	void update(float deltaTime) override;

private:
	Actor* m_targetActor;
};

