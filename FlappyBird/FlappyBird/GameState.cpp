#include "GameState.h"

GameState::GameState(std::shared_ptr<GameData> data) 
	: m_Data(data)
{
}


void GameState::init()
{
	this->m_Data->assetsManager.loadTexture("Game Background", GAME_BG_FILEPATH);
	m_Background.setTexture(this->m_Data->assetsManager.getTexture("Game Background"));
	this->m_Data->assetsManager.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
	this->m_Data->assetsManager.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
	this->m_Data->assetsManager.loadTexture("Land", LAND_FILEPATH);

	m_Pipe = new Pipe(this->m_Data);
	m_Land = new Land(this->m_Data);
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

		if (this->m_Data->inputManager.isSpriteClicked(this->m_Background, sf::Mouse::Left, this->m_Data->window))
		{
			
		}
	}
}


void GameState::update(float dt)
{
	m_Pipe->movePipes(dt);
	m_Land->moveLand(dt);

	if (this->m_Clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
	{
		m_Pipe->randomisePipeOffset();

		m_Pipe->spawnInvisiblePipe();
		m_Pipe->spawnBottomPipe();
		m_Pipe->spawnTopPipe();

		m_Clock.restart();
	}
}


void GameState::draw(float dt)
{
	this->m_Data->window.clear(sf::Color::Red);

	this->m_Data->window.draw(this->m_Background);
	this->m_Pipe->drawPipes();
	this->m_Land->drawLand();


	this->m_Data->window.display();
}


void GameState::pause()
{
}


void GameState::resume()
{
}
