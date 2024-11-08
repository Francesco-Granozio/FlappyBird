#include "GameOverState.h"
#include "Definitions.h"

GameOverState::GameOverState(std::shared_ptr<GameData> data)
    : m_Data(data)
{

}


void GameOverState::init()
{

    this->m_Data->assetsManger.loadTexture("Game Over Background", GAME_OVER_BG_FILEPATH);

    m_Background.setTexture(this->m_Data->assetsManger.getTexture("Game Over Background"));

}

void GameOverState::handleInput()
{
    sf::Event event;

    while (this->m_Data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->m_Data->window.close();
        }

        
    }
}


void GameOverState::update(float dt)
{

}


void GameOverState::draw(float dt)
{
    this->m_Data->window.clear(sf::Color::Red);
    this->m_Data->window.draw(this->m_Background);
    this->m_Data->window.display();
}


void GameOverState::pause()
{

}


void GameOverState::resume()
{

}
