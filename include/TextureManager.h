#pragma once
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	TextureManager() = default;
	void setTexture(sf::Texture&, char);
	sf::Texture getTexture(char);

private:
	sf::Texture m_guardTex;
	sf::Texture m_doorTex;
	sf::Texture m_robotTex;
	sf::Texture m_wallTex;
};

