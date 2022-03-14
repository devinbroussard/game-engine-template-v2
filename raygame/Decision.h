#pragma once
class Agent;


//A decision that has two outcomes attached
class Decision {
public:
	//Checks the condition and transitions to a different decision based on the return value
	virtual void makeDecision(Agent* actor, float deltaTime) = 0;
	
};

