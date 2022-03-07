#include "InputComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MoveComponent.h"

InputComponent::InputComponent(Actor* owner) :
	Component::Component("Input Component")
{}

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	//Get the direction of the individual axis
	float xDirection = -RAYLIB_H::IsKeyDown(KEY_A) + RAYLIB_H::IsKeyDown(KEY_D);
	float yDirection = RAYLIB_H::IsKeyDown(KEY_S) - RAYLIB_H::IsKeyDown(KEY_W);

	//Return a new vector representing the move direction
	return MathLibrary::Vector2(xDirection, yDirection);
}

void InputComponent::update(float deltaTime)
{
	if (getMoveAxis().getMagnitude() > 0)
		getOwner()->getTransform()->setForward(getMoveAxis());
}
