#pragma once
#include "Component.h"
#include <Vector2.h>
#include <raylib.h>

class InputComponent :
	public Component
{
public:
	InputComponent(Actor* owner);

	MathLibrary::Vector2 getMoveAxis();
	void update(float deltaTime) override;

};

