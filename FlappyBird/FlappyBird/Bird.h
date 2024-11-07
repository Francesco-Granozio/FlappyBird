#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <filesystem>
#include <iostream>

class Bird {
private:
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;

    float m_VelocityY = 0;
    float m_Gravity = 0.5f;
    float m_InitalX = 100;
    float m_InitialY = 300;

public:
    Bird(const std::filesystem::path& file) {

        if (!m_Texture.loadFromFile(file.string())) {
            std::cout << "Cannot load Bird img!\n";
        }

        m_Sprite.setTexture(m_Texture);
        m_Sprite.setPosition(m_InitalX, m_InitialY);

        m_Sprite.setScale(0.1f, 0.1f);
    }

    void update() {
        m_VelocityY += m_Gravity;  
        m_Sprite.move(0, m_VelocityY);  
    }

    void jump() {
        m_VelocityY = -10;
    }

    void reset() {

        m_Sprite.setPosition(m_InitalX, m_InitialY);
        m_VelocityY = 0;  
    }

    const sf::Sprite& getSprite() const {
        return m_Sprite;
    }
};
