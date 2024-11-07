#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class Background {
private:
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;

public:
    Background() {
        if (!m_Texture.loadFromFile("assets/images/background.png")) {
            std::cout << "Cannot load background img!\n";
        }

        m_Sprite.setTexture(m_Texture);
    }

    sf::Sprite& getSprite() {
        return m_Sprite;
    }
};
