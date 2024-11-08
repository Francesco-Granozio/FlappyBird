#include "InputManager.h"


bool InputManager::isSpriteClicked(sf::Sprite obj, sf::Mouse::Button button, const sf::RenderWindow& window) {

	if (sf::Mouse::isButtonPressed(button)) {

		sf::IntRect tmpRect(obj.getPosition().x, obj.getPosition().y, 
			obj.getGlobalBounds().width, obj.getGlobalBounds().height);

		if (tmpRect.contains(sf::Mouse::getPosition(window))) {

			return true;
		}
	}
	return false;
}


sf::Vector2i InputManager::getMousePosition(const sf::RenderWindow& window) {

	return sf::Mouse::getPosition(window);
}
