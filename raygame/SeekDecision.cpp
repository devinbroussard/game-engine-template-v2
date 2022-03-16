#include "SeekDecision.h"
#include "SeekBehavior.h"
#include "Enemy.h"
#include "WanderBehavior.h"

void SeekDecision::makeDecision(Agent* agent, float deltaTime) {
	SeekBehavior* seek = agent->getComponent<SeekBehavior>();
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();
	Enemy* enemy = dynamic_cast<Enemy*>(agent);

	if (seek) seek->setForce(50);
	if (wander) wander->setForce(0);

	if (enemy) enemy->setIsAggressive(true);
}
