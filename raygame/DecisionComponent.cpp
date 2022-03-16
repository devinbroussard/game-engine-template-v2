#include "DecisionComponent.h"
#include "Decision.h"
#include "Agent.h"

DecisionComponent::DecisionComponent(Decision* root)
	: Component() {
	m_root = root;
	m_owner = nullptr;
}

void DecisionComponent::start() {
	//Returns the owner as an agent
	m_owner = dynamic_cast<Agent*>(getOwner());
}

void DecisionComponent::update(float deltaTime) {
	//If the owner doesn't return null...
	if (m_owner) {
		//Tell the root to make a decision
		m_root->makeDecision(m_owner, deltaTime);
	}
	//Throws an exception, informing the user than the owner was null
	else throw std::exception("Owner was null. Decision component can only be attached to agents.");
}
