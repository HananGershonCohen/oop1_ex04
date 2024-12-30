#include "Painter.h"
#include <iostream>

void Painter::run()
{

    std::cout << "Enter width and height\n";
    // First width, then height!
    unsigned int boardHeight, boardWidth;
    std::cin >> boardWidth >> boardHeight;
  
    unsigned int heightPixel = boardHeight * m_PixelSize;
    unsigned int widthPixel = boardWidth * m_PixelSize;
    m_toolBar.setToolbarWidht(widthPixel);
    m_toolBar.updateVecButten();

    // set size board for GamWindow.
    m_gameWindow.setRow(boardHeight);
    m_gameWindow.setCol(boardWidth);



    // create new window in the requested size
    auto window = sf::RenderWindow(sf::VideoMode(widthPixel, heightPixel + m_toolbarHeight), "SFML: Hello Hanan");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
             // close window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // action.
            if (event.type == sf::Event::MouseButtonReleased)
            {
                auto location = window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });

                // if press into "Toolbar"
                if (m_toolBar.pressIntoolbar(location)) 
                {
                    handlePress(window, location);
                }
            }

            window.clear();
            m_toolBar.draw(window); // draw "Toolbar"
            m_gameWindow.draw(window); // draw "gameWindow"
            window.display();
        }

    }
}

//--------- private_function -------


void Painter::handlePress(sf::RenderWindow& window, sf::Vector2f& location)
{
    while (window.isOpen())
    {
        // check what was the user press ?
        char c = m_toolBar.getCharPress(location);
        if (nedd2save(c))
        {
            // save Function.
            save();
            std::cout << "saving... \n \n";
            return;
        }
        else if (need2clear(c))
        {
            // clear all
            std::cout << "clearing All... \n ";
            clearing();
            return;
        }
        else if (nedd2add(c))
        {
            AddingObjects(window, location, c);
        }
    }

}

bool Painter::nedd2add(char c) const
{
    return (c == '!' || c == '/' || c == 'D' || c == '@' || c == '#' || c == 'E');
}

void Painter::AddingObjects(sf::RenderWindow& window, sf::Vector2f& location, char c)
{


    sf::Event event;
    while (window.waitEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return;
        }
        if (event.type == sf::Event::MouseButtonReleased)
        {
           
            location = window.mapPixelToCoords(
                { event.mouseButton.x, event.mouseButton.y });

            // if -> this new location are on "GameWindoa" 
            if (!m_toolBar.pressIntoolbar(location))
            {
                m_gameWindow.handleNewClick(location, c);

                window.clear();
                m_toolBar.draw(window);
                m_gameWindow.draw(window);
                window.display();
            }

            else if (m_toolBar.pressIntoolbar(location))
            {
                return;
            }
        }

        else
            continue;
    }
}

void Painter::save() 
{
     m_gameWindow.save();
}

