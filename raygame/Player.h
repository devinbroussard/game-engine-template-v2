#pragma once
#include "Character.h"
class InputComponent;

class Player :
	public Character
{
public:
	Player(float x, float y, const char* name, float speed, int maxHealth, float maxForce);
	~Player() {};

	void start() override;
	void update(float deltaTime) override;
private:
	InputComponent* m_inputComponent;
};

