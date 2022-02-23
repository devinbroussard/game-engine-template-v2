#pragma once
#include "Actor.h"
class Agent :
	public Actor {
public:
	Agent();
	~Agent();

	//Returns the target variable
	Actor* getTarget() { return m_target; } 

private:
	//An actor that the agent will seek or flee from
	Actor* m_target;
};

