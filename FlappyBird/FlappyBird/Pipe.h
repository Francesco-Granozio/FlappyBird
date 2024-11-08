#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

class Pipe
{
public:
	Pipe(std::shared_ptr<GameData> data);

	void spawnBottomPipe();
	void spawnTopPipe();
	void spawnInvisiblePipe();
	void spawnScoringPipe();
	void movePipes(float dt);
	void drawPipes();
	void randomisePipeOffset();

	const std::vector<sf::Sprite>& getSprites() const;
	std::vector<sf::Sprite>& getScoringSprites();

private:
	std::shared_ptr<GameData> m_Data;
	std::vector<sf::Sprite> m_PipeSprites;
	std::vector<sf::Sprite> m_ScoringPipes;

	int m_LandHeight;
	int m_PipeSpawnYOffset;

};