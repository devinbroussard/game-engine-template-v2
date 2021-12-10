#include "SpriteComponent.h"
#include "Actor.h"
#include "Transform2D.h"

SpriteComponent::SpriteComponent(const char* path, Actor* owner) :
	Component::Component("Sprite Component", owner)
{
	m_texture = RAYLIB_H::LoadTexture(path);
}

void SpriteComponent::draw(Transform2D transform)
{
	RAYLIB_H::DrawTexture(m_texture, transform.getWorldPosition().x, transform.getWorldPosition().y, WHITE);
}
