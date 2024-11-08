#pragma once

#include "MainMenuState.h"
#include <iostream>


MainMenuState::MainMenuState(std::shared_ptr<GameData> data) : m_Data(data)
{

}

void MainMenuState::init()
{
	this->m_Data->assetsManger.loadTexture("Main Menu Background", MAIN_MENU_BG_FILEPATH);
	this->m_Data->assetsManger.loadTexture("Game Title", GAME_TITLE_FILEPATH);
	this->m_Data->assetsManger.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);

	m_Background.setTexture(this->m_Data->assetsManger.getTexture("Main Menu Background"));
	m_Background.setScale(0.5f, 0.5f);

	m_Title.setTexture(this->m_Data->assetsManger.getTexture("Game Title"));
	m_Title.setScale(0.5f, 0.5f);

	m_PlayButton.setTexture(this->m_Data->assetsManger.getTexture("Play Button"));
	m_PlayButton.setScale(0.5f, 0.5f);

	m_Title.setPosition((static_cast<float>(SCREEN_WIDTH) / 2) - (m_Title.getGlobalBounds().width / 2), m_Title.getGlobalBounds().height / 2);
	m_PlayButton.setPosition((static_cast<float>(SCREEN_WIDTH) / 2) - (m_PlayButton.getGlobalBounds().width / 2), (static_cast<float>(SCREEN_HEIGHT) / 2) - (m_PlayButton.getGlobalBounds().height / 2));
}

void MainMenuState::handleInput()
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

void MainMenuState::update(float dt)
{

}

void MainMenuState::draw(float dt)
{
	this->m_Data->window.clear(sf::Color::Red);

	this->m_Data->window.draw(this->m_Background);
	this->m_Data->window.draw(this->m_Title);
	this->m_Data->window.draw(this->m_PlayButton);

	this->m_Data->window.display();
}


void MainMenuState::pause()
{
}


void MainMenuState::resume()
{
}
