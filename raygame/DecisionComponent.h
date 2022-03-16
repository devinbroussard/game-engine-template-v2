#pragma once
#include "Component.h"

class Agent;
class Decision;

//An object that can be attached to different actors and make decisions for them
class DecisionComponent :
	public Component {
public:
	DecisionComponent(Decision* root); //Called when this object is created

	virtual void start() override; //Initializes the owner variable
	void update(float deltaTime) override; //Loops through the decision tree

private:
	Decision* m_root; //The first decision in this decision tree
	Agent* m_owner; //Used to return the owner of this component as an agent
};

