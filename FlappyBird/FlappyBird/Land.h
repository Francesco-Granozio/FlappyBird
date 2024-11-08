#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "GameData.h"

class Land
{
public:
	Land(std::shared_ptr<GameData> data);

	void moveLand(float dt);
	void drawLand();

	const std::vector<sf::Sprite>& getSprites() const;

private:
	std::shared_ptr<GameData> m_Data;
	std::vector<sf::Sprite> m_LandSprites;

};
