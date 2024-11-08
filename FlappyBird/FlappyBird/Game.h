#pragma once

#include <iostream>
#include <filesystem>
#include <thread>
#include <chrono>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Bird.h"
#include "Background.h"
#include "PipePair.h"  
#include "Constants.h"

using namespace std::chrono_literals;

class Game {

private:
    sf::RenderWindow m_Window;
    Bird m_Bird;
    Background m_Background;
    bool m_GameOver;
    float m_Score;
    sf::Font m_GameOverFont;
    std::vector<PipePair> m_Pipes; 
    float m_PipeSpawnTimer;   // timer per spawnare nuove pipe

public:
    Game(): m_Window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE),
        m_Bird(std::filesystem::path(BIRD_TEXTURE)),
        m_Background(std::filesystem::path(BACKGROUND_TEXTURE)),
        m_GameOver(false), m_Score(0), m_PipeSpawnTimer(0) {

        m_Window.setFramerateLimit(60);

        if (!m_GameOverFont.loadFromFile(FONT)) {
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
            // Aggiorna il movimento dell'uccello
            m_Bird.update();

            // Aggiungi la logica per spawnare nuove pipe
            m_PipeSpawnTimer += 1.0f;
            if (m_PipeSpawnTimer >= 100) { // Spawn una nuova pipe ogni 100 frame
                spawnPipe();
                m_PipeSpawnTimer = 0; // Reset timer
            }

            // Aggiorna la posizione delle pipe esistenti
            for (auto& pipe : m_Pipes) {
                pipe.update();  // Muovi le pipe verso sinistra
            }

            // Rimuovi le pipe fuori dallo schermo
            m_Pipes.erase(std::remove_if(m_Pipes.begin(), m_Pipes.end(),
                [](const PipePair& pipe) { return pipe.isOffScreen(); }), m_Pipes.end());
        }

        // Controlla se l'uccello è uscito dallo schermo (game over)
        if (m_Bird.getSprite().getPosition().y > m_Window.getSize().y) {
            m_GameOver = true;
        }
    }


    void render() {
        m_Window.clear();

        m_Window.draw(m_Background.getSprite());
        m_Window.draw(m_Bird.getSprite());

        // Disegna le pipe
        for (auto& pipe : m_Pipes) {
            m_Window.draw(pipe.getTopPipeSprite());
            m_Window.draw(pipe.getBottomPipeSprite());
        }

        if (m_GameOver) {
            sf::Text gameOverText;
            gameOverText.setFont(m_GameOverFont);
            gameOverText.setString("Game Over\nScore: " + std::to_string((int)m_Score));
            gameOverText.setCharacterSize(25);
            gameOverText.setFillColor(sf::Color::Black);
            gameOverText.setPosition(100, 250);

            sf::Text restartText;
            restartText.setFont(m_GameOverFont);
            restartText.setString("Press Enter to Restart");
            restartText.setCharacterSize(20);
            restartText.setFillColor(sf::Color::Black);
            restartText.setPosition(80, 350);

            m_Window.draw(gameOverText);
            m_Window.draw(restartText);
        }

        m_Window.display();
    }

    void spawnPipe() {
        // Calcoliamo una posizione casuale per il tubo superiore (tra 100 e 300)
        float pipeY = rand() % 200 + 100;  // Random tra 100 e 300 per l'altezza del tubo superiore
        // Creiamo una nuova coppia di pipe con una posizione X fissa (ad esempio la larghezza della finestra)
        m_Pipes.push_back(PipePair(PIPEUP_TEXTURE, PIPEDOWN_TEXTURE, WINDOW_WIDTH, pipeY));
    }


    bool checkCollision(const Bird& bird, const PipePair& pipe) {
        // Controllo delle collisioni per i tubi
        if (bird.getSprite().getGlobalBounds().intersects(pipe.getTopPipeSprite().getGlobalBounds()) ||
            bird.getSprite().getGlobalBounds().intersects(pipe.getBottomPipeSprite().getGlobalBounds())) {
            return true;
        }
        return false;
    }

    void restartGame() {
        std::this_thread::sleep_for(1s);
        m_Bird.reset();
        m_Score = 0;
        m_GameOver = false;
        m_Pipes.clear();  // Pulisci le pipe
    }
};
