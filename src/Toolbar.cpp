#include "Toolbar.h"
#include <iostream>
#include <fstream>
#include <string>
#include "TextureManager.h"

ToolBar::ToolBar() : m_toolbarWidht(0) {}

void ToolBar::updateVecButten()
{
	std::string nameFile = "Toolbar.txt";
	std::ifstream file(nameFile);

	if (!file.is_open()) {
		std::cerr << "Error: Unable to open the file!" << std::endl;
		return;
	}
	
	int counter = 0;
	char ch;
	TextureManager tempTexture; // יצירת אובייקט קבוע
	unsigned int widht;

    while (file.get(ch)) 
	{
        // קריאת תו-תו עד סוף הקובץ
    
        widht = (m_toolbarWidht / 8) * counter;
        Button button(tempTexture.getTexture(ch), sf::Vector2f(widht, 0.f)); 
        m_buttensVec.push_back(button);
    
        counter++;
    }
    
    // Add buttons for 'E', 'S', and 'C'
    for (char specialChar : {'E', 'S', 'C'})
	{
        widht = (m_toolbarWidht / 8) * counter;
        Button button(tempTexture.getTexture(specialChar), sf::Vector2f(widht, 0.f));
        m_buttensVec.push_back(button);
    
        counter++;
    }
    
}

void ToolBar::draw(sf::RenderWindow& window) const
{
	auto background = sf::RectangleShape(sf::Vector2f(window.getSize().x, m_toolbarHeight));
	background.setFillColor(sf::Color::Green);
	window.draw(background);

	for (auto i = size_t(0); i < m_buttensVec.size(); ++i) 
	{
		m_buttensVec[i].draw(window);
	}
}

void ToolBar::setToolbarWidht(unsigned int toolbarWidht)
{
	m_toolbarWidht = toolbarWidht;
}

bool ToolBar::pressIntoolbar(const sf::Vector2f& location)
{
	if (location.x < 0 || location.x > m_toolbarWidht)
		return false;
	if (location.y < 0 || location.y > m_toolbarHeight)
		return false;

	return true;
}

//?????????????????????
char ToolBar::getCharPress(const sf::Vector2f& location)
{
	for (auto i = size_t(0); i < m_buttensVec.size(); i++)
	{
		if (m_buttensVec[i].create().getGlobalBounds().contains(location))
		{
			// return m_buttensVec[i].
		}
	}

	return 0;
}

