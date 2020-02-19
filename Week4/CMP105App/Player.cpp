#include "Player.h"

Player::Player() {
	speed = 100;
}

void Player::update(float dt) {
	
}

void Player::handleInput(float dt) {
	bool moving = false;
	movement = sf::Vector2f(0, 0);
	if (input->isKeyDown(sf::Keyboard::Up)) {
		movement.y -= speed;
		moving = true;
	}
	if (input->isKeyDown(sf::Keyboard::Down)) {
		movement.y += speed;
		moving = true;
	}
	if (input->isKeyDown(sf::Keyboard::Left)) {
		movement.x -= speed;
		moving = true;
	}
	if (input->isKeyDown(sf::Keyboard::Right)) {
		movement.x += speed;
		moving = true;
	}
	setPosition(getPosition().x + (movement.x * dt), getPosition().y + (movement.y * dt));
	
}