#include "Toolbar.h"

ToolBar::ToolBar()
{
}

void ToolBar::draw(sf::RenderWindow& window) const
{
	auto background = sf::RectangleShape(sf::Vector2f(window.getSize().x, toolbarHeight));
	background.setFillColor(sf::Color::Green);
	window.draw(background);

}

