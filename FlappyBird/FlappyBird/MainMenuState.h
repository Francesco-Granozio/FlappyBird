#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "GameData.h"

class MainMenuState : public State
{
public:
	MainMenuState(std::shared_ptr<GameData> data);

	void init() override;
	void handleInput() override;
	void update(float dt) override;
	void draw(float dt) override;
	void pause() override;
	void resume() override;

private:
	std::shared_ptr<GameData> m_Data;

	sf::Sprite m_Background;
	sf::Sprite m_Title;
	sf::Sprite m_PlayButton;
};

