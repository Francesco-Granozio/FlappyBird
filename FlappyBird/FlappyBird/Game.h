#pragma once

#include <iostream>
#include <filesystem>
#include <thread>
#include <chrono>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Bird.h"
#include "Background.h"

using namespace std::chrono_literals;

class Game {

private:
    sf::RenderWindow m_Window; 
    Bird m_Bird;              
    Background m_Background;   
    bool m_GameOver;           
    float m_Score;        
    sf::Font m_GameOverFont;

public:
    Game()
        : m_Window(sf::VideoMode(360, 640), "Flappy Bird Clone"),
        m_Bird(std::filesystem::path("assets/images/flappybird.png")),
        m_Background(std::filesystem::path("assets/images/background.png")),
        m_GameOver(false), m_Score(0) {

        m_Window.setFramerateLimit(60); 

        if (!m_GameOverFont.loadFromFile("assets/fonts/AlikeAngular-Regular.ttf")) {
            std::cout << "Error loading font\n";
        }
    }

    void run() {
        while (m_Window.isOpen()) {
            handleEvents();
            update();
            render();
        }
    }

private:
    void handleEvents() {
        sf::Event event;
        while (m_Window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                m_Window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space && !m_GameOver) {
                    m_Bird.jump(); 
                }

                if (m_GameOver && event.key.code == sf::Keyboard::Enter) {
                    restartGame(); 
                }
            }
        }
    }

    void update() {

        if (!m_GameOver) {
            m_Bird.update(); 
        }

        if (m_Bird.getSprite().getPosition().y > m_Window.getSize().y) {
            m_GameOver = true;
        }
    }

    void render() {
        m_Window.clear();

        m_Window.draw(m_Background.getSprite());
        m_Window.draw(m_Bird.getSprite());

        if (m_GameOver) {

            sf::Text gameOverText;
            gameOverText.setFont(m_GameOverFont);
            gameOverText.setString("Game Over\nScore: " + std::to_string((int)m_Score));
            gameOverText.setCharacterSize(30);
            gameOverText.setFillColor(sf::Color::Black);
            gameOverText.setPosition(100, 250); 

            m_Window.draw(gameOverText);
        }

        m_Window.display();
    }


    void restartGame() {

        std::this_thread::sleep_for(1s);
        m_Bird.reset();  
        m_Score = 0;
        m_GameOver = false;
    }
};
