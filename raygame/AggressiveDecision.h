#pragma once
#include "BooleanDecision.h"
class AggressiveDecision :
	public BooleanDecision {
public:
	AggressiveDecision(Decision* isFalse = nullptr, Decision* isTrue = nullptr)
		: BooleanDecision(isFalse, isTrue) {}

	bool checkCondition(Agent* agent, float deltaTime) override;
};

