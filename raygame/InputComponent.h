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

private:
	MathLibrary::Vector2 m_forwardDirection;

	RAYLIB_H::KeyboardKey m_forward = RAYLIB_H::KeyboardKey::KEY_W;
	RAYLIB_H::KeyboardKey m_left = RAYLIB_H::KeyboardKey::KEY_A;
	RAYLIB_H::KeyboardKey m_back = RAYLIB_H::KeyboardKey::KEY_S;
	RAYLIB_H::KeyboardKey m_right = RAYLIB_H::KeyboardKey::KEY_D;
};

