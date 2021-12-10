#include "Player.h"
#include "InputComponent.h"

Player::Player(float x, float y, const char* name, float speed, int maxHealth) :
	Character::Character(x, y, name, speed, maxHealth)
{
}

void Player::start()
{
	Character::start();
	InputComponent* inputComponent = new InputComponent(this);
	addComponent(inputComponent);
}
