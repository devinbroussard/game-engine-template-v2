#include "WanderDecision.h"
#include "WanderBehavior.h"
#include "SeekBehavior.h"

void WanderDecision::makeDecision(Agent* agent, float deltaTime) {
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();
	SeekBehavior* seek = agent->getComponent<SeekBehavior>();

	if (wander) wander->setForce(200);
	if (seek) seek->setForce(0);
}
