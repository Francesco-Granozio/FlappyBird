#include "Land.h"
#include "Definitions.h"

Land::Land(std::shared_ptr<GameData> data) 
: m_Data(data) {

	sf::Sprite sprite(this->m_Data->assetsManager.getTexture("Land"));
	sf::Sprite sprite2(this->m_Data->assetsManager.getTexture("Land"));

	sprite.setPosition(0, this->m_Data->window.getSize().y - sprite.getLocalBounds().height);
	sprite2.setPosition(sprite.getLocalBounds().width, this->m_Data->window.getSize().y - sprite2.getLocalBounds().height);

	m_LandSprites.push_back(sprite);
	m_LandSprites.push_back(sprite2);
}

void Land::moveLand(float dt) {

	for (unsigned short int i = 0; i < m_LandSprites.size(); i++)
	{
		const sf::Vector2f position = m_LandSprites[i].getPosition();
		float movement = PIPE_MOVEMENT_SPEED * dt;

		m_LandSprites[i].move(-movement, 0.0f);

		if (m_LandSprites[i].getPosition().x < 0 - m_LandSprites[i].getLocalBounds().width)
		{
			const sf::Vector2f position(m_Data->window.getSize().x, m_LandSprites[i].getPosition().y);

			m_LandSprites[i].setPosition(position);
		}
	}
}

void Land::drawLand(){

	for (const sf::Sprite& landSprite : m_LandSprites) {

		this->m_Data->window.draw(landSprite);
	}
}

const std::vector<sf::Sprite>& Land::getSprites() const {

	return m_LandSprites;
}
