#include "InputComponent.h"
#include "Actor.h"
#include "Transform2D.h"

InputComponent::InputComponent(Actor* owner) :
	Component::Component("Input Component")
{}

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	float xDirection = -RAYLIB_H::IsKeyDown(KEY_A) + RAYLIB_H::IsKeyDown(KEY_D);
	float yDirection = RAYLIB_H::IsKeyDown(KEY_S) - RAYLIB_H::IsKeyDown(KEY_W);

	return MathLibrary::Vector2(xDirection, yDirection);
}

void InputComponent::update(float deltaTime)
{
	getOwner()->getTransform()->setForward(getMoveAxis());
}
