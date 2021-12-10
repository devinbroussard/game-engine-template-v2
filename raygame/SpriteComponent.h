#pragma once
#include "Component.h"
#include <raylib.h>
class Actor;
class Transform2D;

class SpriteComponent :
	public Component
{
public:
	SpriteComponent(const char* path, Actor* owner);
	~SpriteComponent() {}

	int getWidth() { return m_texture.width; }
	int getHeight() { return m_texture.height; }

	void draw() override;

private:
	int setWidth(int width) { m_texture.width = width; }
	int setHeight(int height) { m_texture.height = height; }

	Texture2D m_texture;
};

