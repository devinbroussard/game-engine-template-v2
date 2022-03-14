#include "BooleanDecision.h"

BooleanDecision::BooleanDecision(Decision* leftChild, Decision* rightChild) {
	m_isFalse = leftChild;
	m_isTrue = rightChild;
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
