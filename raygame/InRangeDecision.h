#pragma once
#include "BooleanDecision.h"

class InRangeDecision :
	public BooleanDecision {
public:
	InRangeDecision(Decision* isFalse = nullptr, Decision* isTrue = nullptr)
		: BooleanDecision(isFalse, isTrue) {}

	//Checks to see if the given agent is in range of this decision's owner
	bool checkCondition(Agent* agent, float deltaTime) override; 
};

