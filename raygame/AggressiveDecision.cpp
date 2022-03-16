#include "AggressiveDecision.h"
#include "Enemy.h"

bool AggressiveDecision::checkCondition(Agent* agent, float deltaTime) {
	Enemy* enemy = dynamic_cast<Enemy*>(agent);

	if (enemy) return enemy->getIsAggressive();
	else return false;
}
