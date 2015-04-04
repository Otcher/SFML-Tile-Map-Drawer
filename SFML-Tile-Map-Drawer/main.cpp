#include <SFML/Graphics.hpp>

#include "map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 768), "Tile Map Drawer");
	
	Map m;
	m.Load("test.map");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(m);
		window.display();

	}

	return 0;
}