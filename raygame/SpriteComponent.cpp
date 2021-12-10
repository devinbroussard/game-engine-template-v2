#include "SpriteComponent.h"
#include "Actor.h"
#include "Transform2D.h"

SpriteComponent::SpriteComponent(const char* path, Actor* owner) :
	Component::Component(owner, "Sprite Component")
{
	m_texture = RAYLIB_H::LoadTexture(path);
}

void SpriteComponent::draw()
{
	RAYLIB_H::DrawTexture(m_texture, getOwner()->getTransform()->getWorldPosition().x, getOwner()->getTransform()->getWorldPosition().y, WHITE);
}
