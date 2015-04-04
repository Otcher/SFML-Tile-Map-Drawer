#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Map  : public sf::Sprite
{
public:
	Map();

	void Load(std::string mapfilename);

	void Render(sf::RenderWindow* window);

	~Map();

protected:
	std::string tileSet;
	int map_width;
	int map_height;
	int tileWidth;
	int tileHeight;
	int* mapData;

private:
	sf::Image* tileImageTexture;
	sf::Texture* texture;
};