#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <filesystem>
#include <iostream>

class Background {
private:
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;

public:
    Background(const std::filesystem::path& file) {
        if (!m_Texture.loadFromFile(file.string())) {
            std::cout << "Cannot load background img!\n";
        }

        m_Sprite.setTexture(m_Texture);
    }

    sf::Sprite& getSprite() {
        return m_Sprite;
    }
};
