#pragma once
#include "Decision.h"

//A decision that has two children attached
class BooleanDecision :
	public Decision
{
public:
	//Takes in a left or right child and sets them to be the children of this decision
	BooleanDecision(Decision* leftChild = nullptr, Decision* rightChild = nullptr);

	//Cehcks the condition and transitions to a differnet decision based onthe return value
	virtual void makeDecision(Agent* agent, float deltaTime) override;
	//Checks to see if a certain condition ahs been met and returns the result
	virtual bool checkCondition(Agent* agent, float deltaTime) { return false; }

private:
	Decision* m_isFalse; //
	Decision* m_isTrue;
};

