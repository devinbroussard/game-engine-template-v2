#include "Agent.h"
#include "WanderBehavior.h"
#include "SeekBehavior.h"
#include "FleeBehavior.h"

void Agent::start()
{
	WanderBehavior* wanderBehavior = new WanderBehavior(40, 1000);
	m_steeringBehaviors.addItem((SteeringBehavior*)wanderBehavior);
	

}
