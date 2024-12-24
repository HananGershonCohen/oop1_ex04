#include "Button.h"

Button::Button()
{
	m_texture.loadFromFile("guard.jpg");
	m_position = { 10, 10 };

}

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(create());
}

sf::Sprite Button::create() const
{
	auto newObject = sf::Sprite();
	newObject.setPosition(m_position);
	newObject.setTexture(m_texture);
	newObject.setScale(0.25, 0.25);
	return newObject;
}
