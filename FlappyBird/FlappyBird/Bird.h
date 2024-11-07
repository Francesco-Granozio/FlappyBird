#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Bird {
private:
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;

    float m_valocityY = 0;
    float m_Gravity = 0.5f;

public:
    Bird() {

        if (!m_Texture.loadFromFile("assets/images/flappybird.png")) {
            std::cout << "Cannot load Bird img!\n";
        }

        m_Sprite.setTexture(m_Texture);
        m_Sprite.setPosition(100, 300);

        m_Sprite.setScale(0.1f, 0.1f);
    }

    void update() {
        m_valocityY += m_Gravity;  
        m_Sprite.move(0, m_valocityY);  
    }

    void jump() {
        m_valocityY = -10;
    }

    const sf::Sprite& getSprite() const {
        return m_Sprite;
    }
};
