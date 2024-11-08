#pragma once

#include <map>
#include <SFML/Graphics.hpp>

class AssetsManger
{
public:
	AssetsManger() { }
	~AssetsManger() { }
	void loadTexture(const char* textureName, const char* fileName);
	sf::Texture& getTexture(const char* textureName);
	void loadFont(const char* fontName, const char* fileName);
	sf::Font& getFont(const char* fontName);


private:

	std::map<const char*, sf::Texture> m_Textures;
	std::map<const char*, sf::Font> m_Fonts;
};

