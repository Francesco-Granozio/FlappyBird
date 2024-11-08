#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "GameData.h"

class GameState : public State
{
public:
	GameState(std::shared_ptr<GameData> data);

	void init() override;
	void handleInput() override;
	void update(float dt) override;
	void draw(float dt) override;
	void pause() override;
	void resume() override;

private:
	std::shared_ptr<GameData> m_Data;
	sf::Sprite m_Background;

};

