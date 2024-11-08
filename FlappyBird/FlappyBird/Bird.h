#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <filesystem>
#include <iostream>
#include "Constants.h"

class Bird {
private:
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;

    float m_VelocityY = 0;  // velocità verticale
    float m_Gravity = 0.5f;  // gravità
    float m_InitialX = WINDOW_WIDTH / 8;  // posizione iniziale X
    float m_InitialY = WINDOW_HEIGHT / 2; // posizione iniziale Y

public:
    Bird(const std::filesystem::path& file) {
        if (!m_Texture.loadFromFile(file.string())) {
            std::cout << "Cannot load Bird img!\n";
        }
        m_Sprite.setTexture(m_Texture);
        m_Sprite.setPosition(m_InitialX, m_InitialY);
        m_Sprite.setScale(0.1f, 0.1f);
    }

    void update() {
        m_VelocityY += m_Gravity;
        m_Sprite.move(0, m_VelocityY);

        if (m_Sprite.getPosition().y > WINDOW_HEIGHT) {  // Assumendo che l'altezza della finestra sia 640
            m_Sprite.setPosition(m_Sprite.getPosition().x, WINDOW_HEIGHT);
        }
    }

    void jump() {
        m_VelocityY = -10; // Imposta la velocità del salto
    }

    void reset() {
        m_Sprite.setPosition(m_InitialX, m_InitialY);
        m_VelocityY = 0;  // Reset velocità
    }

    const sf::Sprite& getSprite() const {
        return m_Sprite;
    }
};
