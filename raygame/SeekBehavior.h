#pragma once
#include "Component.h"
class MoveComponent;
class Agent;

class SeekBehavior  : 
	public Component {
public:
	SeekBehavior(Actor* m_target); //Assigns a value to the m_target variable
	~SeekBehavior() {}//Deallocates memory 

	void setTarget(Actor* target) { m_target = target; } //Changes the m_target variable
	Actor* getTarget() const { return m_target;} //Returns the m_target variable

	void setForce(float force) { m_force = force; } //Changes the m_force variable

	void update(float deltaTime) override; //Called every frame to change the owner's velocity

private:
	Actor* m_target; //The actor that the owner will seek
	float m_force; //The force that is applied to the owner every second
};

