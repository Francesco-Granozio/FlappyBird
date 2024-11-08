#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "StateStack.h"
#include "AssetsManger.h"
#include "InputManager.h"
#include "Definitions.h"
#include "MainMenuState.h"
#include "GameData.h"

class MainMenuState;

class Game {

public:

	Game(int width, int height, const char* title);
	void run();

private:

	const float dt = 1.0f / 60.0f;
	sf::Clock m_Clock;
	std::shared_ptr<GameData> m_Data = std::make_shared<GameData>();

};

