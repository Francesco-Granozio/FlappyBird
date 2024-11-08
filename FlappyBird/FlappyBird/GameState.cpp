#include "GameState.h"

GameState::GameState(std::shared_ptr<GameData> data) 
	: m_Data(data)
{
}


void GameState::init()
{
	this->m_Data->assetsManger.loadTexture("Game Background", GAME_BG_FILEPATH);
	m_Background.setTexture(this->m_Data->assetsManger.getTexture("Game Background"));
}


void GameState::handleInput()
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


void GameState::update(float dt)
{
}


void GameState::draw(float dt)
{
	this->m_Data->window.clear(sf::Color::Red);

	this->m_Data->window.draw(this->m_Background);


	this->m_Data->window.display();
}


void GameState::pause()
{
}


void GameState::resume()
{
}
