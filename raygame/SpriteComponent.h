#pragma once
#include "Component.h"
#include <raylib.h>
#include <Matrix3.h>
class Transform2D;

class SpriteComponent :
	public Component
{
public:
	SpriteComponent(const char* path, const char* name = "SpriteComponent");
	SpriteComponent(Texture2D* texture, const  char* name = "SpriteComponent");
	~SpriteComponent() override;

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

	void draw() override;

private:
	Texture2D* m_texture;
	int m_width;
	int m_height;
};

