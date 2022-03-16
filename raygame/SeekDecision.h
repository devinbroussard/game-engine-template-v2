#pragma once
#include "Decision.h"
class SeekDecision :
	public Decision {
public:
	void makeDecision(Agent* agent, float deltaTime);
};

