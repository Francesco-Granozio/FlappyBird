#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <filesystem>
#include <iostream>
#include "Constants.h"

class PipePair {
private:
    sf::Sprite m_TopPipeSprite;
    sf::Sprite m_BottomPipeSprite;
    sf::Texture m_TopPipeTexture;
    sf::Texture m_BottomPipeTexture;

    float m_XPosition;  // Posizione orizzontale della coppia di pipe
    float m_YPosition;  // Posizione verticale del tubo superiore
    bool m_Scored = false;     // Contata nel punteggio

public:
    PipePair(const std::filesystem::path& topPipeImage, const std::filesystem::path& bottomPipeImage,
        float xPosition, float yPosition) {

        // Verifica il caricamento della texture per il tubo superiore
        if (!m_TopPipeTexture.loadFromFile(topPipeImage.string())) {
            std::cout << "Errore nel caricamento dell'immagine del tubo superiore! Percorso: " << topPipeImage.string() << std::endl;
        }

        // Verifica il caricamento della texture per il tubo inferiore
        if (!m_BottomPipeTexture.loadFromFile(bottomPipeImage.string())) {
            std::cout << "Errore nel caricamento dell'immagine del tubo inferiore! Percorso: " << bottomPipeImage.string() << std::endl;
        }

        m_TopPipeSprite.setTexture(m_TopPipeTexture);
        m_BottomPipeSprite.setTexture(m_BottomPipeTexture);

        m_TopPipeSprite.setScale(0.1f, 0.1f); // Scala la pipe (esempio)
        m_BottomPipeSprite.setScale(0.1f, 0.1f);

        m_XPosition = xPosition;
        m_YPosition = yPosition;

        // Posizioniamo il tubo superiore alla coordinata Y
        m_TopPipeSprite.setPosition(m_XPosition, m_YPosition);

        // Posizioniamo il tubo inferiore a una certa distanza (ad esempio 200 pixel sotto il tubo superiore)
        m_BottomPipeSprite.setPosition(m_XPosition, m_YPosition + OPENING_HEIGHT + m_TopPipeTexture.getSize().y);
    }


    void update() {
        m_XPosition += -4.0f;  // Sposta le pipe orizzontalmente
        m_TopPipeSprite.setPosition(m_XPosition, m_YPosition);
        m_BottomPipeSprite.setPosition(m_XPosition, m_YPosition + OPENING_HEIGHT + m_TopPipeTexture.getSize().y);
    }

    bool isOffScreen() const {
        return m_XPosition + m_TopPipeTexture.getSize().x < 0;  // Se le pipe sono fuori dallo schermo
    }

    const sf::Sprite& getTopPipeSprite() const {
        return m_TopPipeSprite;
    }

    const sf::Sprite& getBottomPipeSprite() const {
        return m_BottomPipeSprite;
    }

    float getXPosition() const {
        return m_XPosition;
    }

    float getYPosition() const {
        return m_YPosition;
    }

    void setScored(bool scored) {
        m_Scored = scored;
    }

    bool isScored() const {
        return m_Scored;
    }

    bool hasPassed(const sf::Sprite& bird) {
        if (!m_Scored && bird.getPosition().x > m_XPosition + m_TopPipeTexture.getSize().x) {
            m_Scored = true;
            return true;
        }
        return false;
    }
};
