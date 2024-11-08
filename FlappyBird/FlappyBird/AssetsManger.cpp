#include "AssetsManger.h"


void AssetsManager::loadTexture(const char* textureName, const char* fileName) {

	sf::Texture tmpTexture;

	if (tmpTexture.loadFromFile(fileName)) {

		this->m_Textures[textureName] = tmpTexture;
	}
}

sf::Texture& AssetsManager::getTexture(const char* textureName) {

	return this->m_Textures[textureName];
}

void AssetsManager::loadFont(const char* fontName, const char* fileName) {

	sf::Font tmpFont;

	if (tmpFont.loadFromFile(fileName)) {

		this->m_Fonts[fontName] = tmpFont;
	}
}

sf::Font& AssetsManager::getFont(const char* fontName) {

	return this->m_Fonts[fontName];

}