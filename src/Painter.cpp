#include "Painter.h"


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
  

   


    // create new window in the requested size
    auto window = sf::RenderWindow(sf::VideoMode( widthPixel, heightPixel + m_toolbarHeight), "SFML: Hello Hanan");
  


    
    while (window.isOpen())
    {

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        window.clear();
        m_toolBar.draw(window);
        window.display();
    }

}
