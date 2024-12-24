#include "Painter.h"




void Painter::run()
{
	std::cout << "Enter width and height\n";
    // First width, then height!
	float boardHeight, boardWidth;
    std::cin >> boardWidth >> boardHeight;
   
	float heightPixel = boardHeight * PixelSize;
	float widthPixel = boardWidth * PixelSize;



    // create new window in the requested size
    auto window = sf::RenderWindow(sf::VideoMode( widthPixel, heightPixel + toolbarHeight), "SFML: Hello Hanan");

  
  
   
    
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
