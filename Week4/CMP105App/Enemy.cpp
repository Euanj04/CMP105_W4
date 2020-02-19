#include "Enemy.h"

Enemy::Enemy() {
	movement = sf::Vector2f(50, 50);
}

void Enemy::handleInput(float dt) {
	//enemy acts without user input
}

void Enemy::update(float dt) {
	velocity = movement * dt;
	setPosition(getPosition().x + velocity.x, getPosition().y + velocity.y);
	if (getPosition().x > window->getSize().x - getOrigin().x) {
		setPosition(window->getSize().x - getOrigin().x, getPosition().y);
		movement.x *= -1;
	}
	if (getPosition().x < getOrigin().x) {
		setPosition(getOrigin().x, getPosition().y);
		movement.x *= -1;
	}
	if (getPosition().y > window->getSize().y - getOrigin().y) {
		setPosition(getPosition().x, window->getSize().y - getOrigin().y);
		movement.y *= -1;
	}
	if (getPosition().y < getOrigin().y) {
		setPosition(getPosition().x, getOrigin().y);
		movement.y *= -1;
	}
}