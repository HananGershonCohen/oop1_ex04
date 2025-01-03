#include "Image.h"

Image::Image(const sf::Texture& texture, const sf::Vector2f& location)
	:m_texture{ texture }, m_position{ location }
{
}

sf::Sprite Image::getSprite() const
{
	auto newObject = sf::Sprite();
	newObject.setPosition(m_position);
	newObject.setTexture(m_texture);
	newObject.setScale(0.1f, 0.1f);
	return newObject;
}

char Image::getchar() const
{
	TextureManager textures;
	return textures.getChar(m_texture);
}

sf::Texture Image::getTexture() const 
{
	return m_texture;
}

// ����� �� ����� �������
sf::Vector2f Image::getPosition() const 
{
	return m_position;
}