#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");
	goomTexture.loadFromFile("gfx/Goomba.png");
	koopTexture.loadFromFile("gfx/Koopa.png");

	player.setInput(input);
	player.setTexture(&texture);
	player.setSize(sf::Vector2f(100, 100));
	player.setPosition(100, 100);

	goomba.setWindow(window);
	goomba.setTexture(&goomTexture);
	goomba.setSize(sf::Vector2f(100, 100));
	goomba.setPosition(500, 500);
	goomba.setOrigin(goomba.getSize().x / 2, goomba.getSize().y / 2);

	koopa.setWindow(window);
	koopa.setTexture(&koopTexture);
	koopa.setSize(sf::Vector2f(100, 150));
	koopa.setPosition(300, 100);
	koopa.setOrigin(koopa.getSize().x / 2, koopa.getSize().y / 2);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);

	goomba.update(dt);

	koopa.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(player);

	window->draw(goomba);

	window->draw(koopa);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}