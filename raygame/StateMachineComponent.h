#pragma once
#include "Component.h"
class SeekBehavior;
class WanderBehavior;
class FleeBehavior;

enum State {
	IDLE,
	WANDER,
	SEEK,
	FLEE
};

class StateMachineComponent :
	public Component {
public:
	StateMachineComponent();
	~StateMachineComponent() {}

	State getCurrentState() { return m_currentState; } 
	void setCurrentState(State state) { m_currentState = state; }

	void start() override;
	void update(float deltaTime) override;

private:
	State m_currentState;
	SeekBehavior* m_seekComponent;
	WanderBehavior* m_wanderComponent;
	FleeBehavior* m_fleeComponent;
	float m_wanderForce;
	float m_seekForce;
	float m_fleeForce;
	float m_seekRange = 200;
};

