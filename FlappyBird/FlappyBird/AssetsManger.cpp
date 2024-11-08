#include "AssetsManger.h"


void AssetsManger::loadTexture(std::string textureName, std::string fileName) {

	sf::Texture tmpTexture;

	if (tmpTexture.loadFromFile(fileName)) {

		this->m_Textures[textureName] = tmpTexture;
	}
}

sf::Texture& AssetsManger::getTexture(std::string textureName) {

	return this->m_Textures[textureName];
}

void AssetsManger::loadFont(std::string fontName, std::string fileName) {

	sf::Font tmpFont;

	if (tmpFont.loadFromFile(fileName)) {

		this->m_Fonts[fontName] = tmpFont;
	}
}

sf::Font& AssetsManger::getFont(std::string fontName) {

	return this->m_Fonts[fontName];

}