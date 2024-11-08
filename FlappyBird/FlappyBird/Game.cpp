#include "Game.h"

Game::Game(int width, int height, const char* title) {

	m_Data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	m_Data->stateStack.addState(std::make_unique<MainMenuState>(this->m_Data), true);
	//this->run();
}

void Game::run()
{
	float newTime, frameTime, interpolation;

	float currentTime = this->m_Clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->m_Data->window.isOpen())
	{
		this->m_Data->stateStack.processStateChanges();

		newTime = this->m_Clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
		{
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->m_Data->stateStack.getActiveState()->handleInput();
			this->m_Data->stateStack.getActiveState()->update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->m_Data->stateStack.getActiveState()->draw(interpolation);
	}
}