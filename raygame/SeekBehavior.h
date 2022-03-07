#pragma once
#include "SteeringComponent.h"
class MoveComponent;

class SeekBehavior  : 
	public SteeringComponent {
public:
	SeekBehavior(Actor* m_target, float seekForce); //Assigns a value to the m_target variable
	~SeekBehavior() {}//Deallocates memory 

	void setTarget(Actor* target) { m_target = target; } //Changes the m_target variable
	Actor* getTarget() const { return m_target;} //Returns the m_target variable

	void setForce(float force) { m_seekForce = force; } //Changes the m_seekForce variable
	float getForce() { return m_seekForce; } //Returns the current value of the m_seekForce variable

	MathLibrary::Vector2 calculateForce(float deltaTime) override;

private:
	Actor* m_target; //The actor that the owner will seek
	float m_seekForce; //The seekForce scalar that is applied when seeking a target
};

