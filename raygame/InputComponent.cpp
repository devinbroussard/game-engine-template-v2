#include "InputComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MoveComponent.h"

InputComponent::InputComponent(Actor* owner) :
	Component::Component("Input Component") {
	m_forwardDirection = { 0, 0 };
}

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	//Get the direction of the individual axis
	float xDirection = -RAYLIB_H::IsKeyDown(KEY_A) + RAYLIB_H::IsKeyDown(KEY_D);
	float yDirection = RAYLIB_H::IsKeyDown(KEY_S) - RAYLIB_H::IsKeyDown(KEY_W);

	m_forwardDirection = MathLibrary::Vector2(xDirection, yDirection);

	//Return a new vector representing the move direction
	return m_forwardDirection;
}

void InputComponent::update(float deltaTime)
{ }
