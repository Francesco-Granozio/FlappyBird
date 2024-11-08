#pragma once

#include <SFML/Graphics.hpp>

class InputManager
{
public:
	InputManager() {}
	~InputManager() {}
	bool isSpriteClicked(sf::Sprite obj, sf::Mouse::Button button, const sf::RenderWindow& window);
	sf::Vector2i getMousePosition(const sf::RenderWindow& window);
};

