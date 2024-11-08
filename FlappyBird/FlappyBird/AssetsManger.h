#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class AssetsManger
{
public:
	AssetsManger() { }
	~AssetsManger() { }
	void loadTexture(std::string textureName, std::string fileName);
	sf::Texture& getTexture(std::string textureName);
	void loadFont(std::string fontName, std::string fileName);
	sf::Font& getFont(std::string fontName);


private:

	std::map<std::string, sf::Texture> m_Textures;
	std::map<std::string, sf::Font> m_Fonts;
};

