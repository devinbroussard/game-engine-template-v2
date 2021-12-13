#include "SpriteComponent.h"
#include "Actor.h"
#include "Transform2D.h"

SpriteComponent::SpriteComponent(const char* path, const char* name = "SpriteComponent") :
	Component::Component(name)
{
	m_texture = &RAYLIB_H::LoadTexture(path);
}

SpriteComponent::SpriteComponent(Texture2D* texture, const char* name)
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
	MathLibrary::Matrix3* worldMatrix = getOwner()->getTransform()->getGlobalMatrix();
	m_width = getOwner()->getTransform()->getScale().x;
	m_height = getOwner()->getTransform()->getScale().y;

	position.x = getOwner()->getTransform()->getWorldPosition().x;
	position.y = getOwner()->getTransform()->getWorldPosition().y;
	Vector2 forward = 

	RAYLIB_H::DrawTextureEx(*m_texture, position, getOwner()->getTransform()->getForward(), getOwner()->getTransform()->getScale(), WHITE);
}
