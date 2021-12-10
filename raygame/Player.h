#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player(float x, float y, const char* name, float speed, int maxHealth);
	~Player() {};

	void start() override;
};

