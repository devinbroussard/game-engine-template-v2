#include "IdleDecision.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"
#include "FleeBehavior.h"
#include "Agent.h"

void IdleDecision::makeDecision(Agent* agent, float deltaTime) {
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();
	if (wander) wander->setForce(0);

	SeekBehavior* seek = agent->getComponent<SeekBehavior>();
	if (seek) seek->setForce(0);

	FleeBehavior* flee = agent->getComponent<FleeBehavior>();
	if (flee) flee->setForce(0);
}
