#include "Pipe.h"

Pipe::Pipe(std::shared_ptr<GameData> data)
	: m_Data(data),
	m_LandHeight(data->assetsManager.getTexture("Land").getSize().y),
	m_PipeSpawnYOffset(0) {

}

void Pipe::spawnBottomPipe()
{
	sf::Sprite sprite(this->m_Data->assetsManager.getTexture("Pipe Up"));

	sprite.setPosition(this->m_Data->window.getSize().x,
		this->m_Data->window.getSize().y - sprite.getLocalBounds().height - m_PipeSpawnYOffset);

	m_PipeSprites.push_back(sprite);
}


void Pipe::spawnTopPipe()
{
	sf::Sprite sprite(this->m_Data->assetsManager.getTexture("Pipe Down"));

	sprite.setPosition(this->m_Data->window.getSize().x, -m_PipeSpawnYOffset);

	m_PipeSprites.push_back(sprite);
}


void Pipe::spawnInvisiblePipe()
{
	sf::Sprite sprite(this->m_Data->assetsManager.getTexture("Pipe Down"));

	sprite.setPosition(this->m_Data->window.getSize().x, -m_PipeSpawnYOffset);
	sprite.setColor(sf::Color(0, 0, 0, 0));

	m_PipeSprites.push_back(sprite);
}


void Pipe::spawnScoringPipe()
{

}


void Pipe::movePipes(float dt)
{
	for (int i = 0; i < m_PipeSprites.size(); i++)
	{
		if (m_PipeSprites[i].getPosition().x < 0 - m_PipeSprites[i].getLocalBounds().width)
		{
			m_PipeSprites.erase(m_PipeSprites.begin() + i);
		}
		else
		{
			float movement = PIPE_MOVEMENT_SPEED * dt;

			m_PipeSprites[i].move(-movement, 0);
		}
	}

	
}


void Pipe::drawPipes()
{

	for (const sf::Sprite& pipeSprite : m_PipeSprites) {

		this->m_Data->window.draw(pipeSprite);
	}
}


void Pipe::randomisePipeOffset()
{
	m_PipeSpawnYOffset = rand() % (m_LandHeight + 1);
}


const std::vector<sf::Sprite>& Pipe::getSprites() const {

	return m_PipeSprites;
}



std::vector<sf::Sprite>& Pipe::getScoringSprites() {

	return m_ScoringPipes;
}
