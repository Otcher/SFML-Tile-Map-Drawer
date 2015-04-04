#include <iostream>
#include <sstream>
#include <fstream>

#include "map.h"

Map::Map()
{
	this->tileImageTexture = new sf::Image();
	this->texture = new sf::Texture();
}

void Map::Load(std::string mapfilename)
{
	std::ifstream mapFile("Graphics/" + mapfilename);
	std::string temp;

	std::getline(mapFile, this->tileSet);
	std::getline(mapFile, temp);
	this->tileWidth = std::stoi(temp, nullptr);
	std::getline(mapFile, temp);
	this->tileHeight = std::stoi(temp, nullptr);
	std::getline(mapFile, temp);
	this->map_width = std::stoi(temp, nullptr);
	std::getline(mapFile, temp);
	this->map_height = std::stoi(temp, nullptr);

	this->mapData = new int[this->map_width * this->map_height];

	for (int y = 0; y < this->map_height; y++)
	{
		for (int x = 0; x < this->map_width; x++)
		{
			char temp;
			mapFile >> this->mapData[x + y * this->map_width] >> temp;
		}
	}
	mapFile.close();

	this->texture->create(this->map_width * this->tileWidth, this->map_height * this->tileHeight);

	this->tileImageTexture->loadFromFile("Graphics/" + this->tileSet);
	sf::Image tile1, tile2, tile3, tile4, tile5;

	tile1.create(32, 32);
	tile2.create(32, 32);
	tile3.create(32, 32);
	tile4.create(32, 32);
	tile5.create(32, 32);

	tile1.copy(*this->tileImageTexture, 0, 0, sf::IntRect(0, 0, this->tileWidth, this->tileHeight), true);
	tile2.copy(*this->tileImageTexture, 0, 0, sf::IntRect(this->tileWidth, 0, this->tileWidth, this->tileHeight), true);
	tile3.copy(*this->tileImageTexture, 0, 0, sf::IntRect(0, this->tileHeight, this->tileWidth, this->tileHeight), true);
	tile4.copy(*this->tileImageTexture, 0, 0, sf::IntRect(this->tileWidth, this->tileHeight, this->tileWidth, this->tileHeight), true);
	tile5.copy(*this->tileImageTexture, 0, 0, sf::IntRect(0, 2 * this->tileHeight, this->tileWidth, this->tileHeight), true);

	for (int y = 0; y < this->map_height; y += 1)
	{
		for (int x = 0; x < this->map_width; x += 1)
		{
			switch (this->mapData[x + y * this->map_width])
			{
			case 0:
				break;
			case 1:
				this->texture->update(tile1, x * 32, y * 32);
				break;
			case 2:
				this->texture->update(tile2, x * 32, y * 32);
				break;
			case 3:
				this->texture->update(tile3, x * 32, y * 32);
				break;
			case 4:
				this->texture->update(tile4, x * 32, y * 32);
				break;
			case 5:
				this->texture->update(tile5, x * 32, y * 32);
				break;
			}
		}
	}
	this->setTexture(*this->texture);

}

Map::~Map()
{
	delete this->texture;
	delete this->tileImageTexture;
	delete this->mapData;
}