#include "BooleanDecision.h"

BooleanDecision::BooleanDecision(Decision* falseChild, Decision* trueChild) {
	m_isFalse = falseChild;
	m_isTrue = trueChild;
}

void BooleanDecision::makeDecision(Agent* agent, float deltaTime)
{
	if (checkCondition(agent, deltaTime)) {
		if (m_isTrue) {
			m_isTrue->makeDecision(agent, deltaTime);
		}
	}
	else {
		if (m_isFalse) {
			m_isFalse->makeDecision(agent, deltaTime);
		}
	}
}
