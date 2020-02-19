#pragma once
#include "Framework/GameObject.h"
#include "SFML/Graphics/RenderWindow.hpp"
class Enemy :
	public GameObject
{
public:
	Enemy();
	void handleInput(float dt);
	void update(float dt);

	void setWindow(sf::RenderWindow* win) { window = win; };

	sf::Vector2f movement;
protected:
	sf::RenderWindow* window;
};

