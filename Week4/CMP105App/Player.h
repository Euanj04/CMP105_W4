#pragma once
#include "Framework/GameObject.h"
class Player :
	public GameObject
{
public:
	float speed;
	sf::Vector2f movement;
	Player();
	void handleInput(float dt);
	void update(float dt);
};

