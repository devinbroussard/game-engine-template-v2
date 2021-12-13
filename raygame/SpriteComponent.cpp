#include "SpriteComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include <cmath>

SpriteComponent::SpriteComponent(const char* path, const char* name) :
	Component::Component(name)
{
	m_texture = &RAYLIB_H::LoadTexture(path);
}

SpriteComponent::SpriteComponent(Texture2D* texture, const char* name) :
	Component::Component(name)
{
	m_texture = texture;
}

SpriteComponent::~SpriteComponent()
{
	delete m_texture;
	RAYLIB_H::UnloadTexture(*m_texture);
}

void SpriteComponent::draw()

{
	//Scale
	m_width = getOwner()->getTransform()->getScale().x;
	m_height = getOwner()->getTransform()->getScale().y;

	m_texture->width = m_width;
	m_texture->height = m_height;

	//Position
	MathLibrary::Vector2 up = { getOwner()->getTransform()->getGlobalMatrix()->m01, getOwner()->getTransform()->getGlobalMatrix()->m11 };
	MathLibrary::Vector2 forward = getOwner()->getTransform()->getForward();
	MathLibrary::Vector2 position = getOwner()->getTransform()->getWorldPosition();

	position = position - (forward * getWidth() / 2);
	position = position - (up * getHeight() / 2);
	RAYLIB_H::Vector2 rayPos = { position.x, position.y };

	//Rotation
	float rotation = atan2(getOwner()->getTransform()->getGlobalMatrix()->m10, getOwner()->getTransform()->getGlobalMatrix()->m00);

	RAYLIB_H::DrawTextureEx(*m_texture, rayPos, (float)(rotation * 180.0f / PI), 1, WHITE);
}
