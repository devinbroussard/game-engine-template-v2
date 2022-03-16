#pragma once
#include "Decision.h"
class WanderDecision :
	public Decision {
public:
	void makeDecision(Agent* agent, float deltaTime) override;
};

