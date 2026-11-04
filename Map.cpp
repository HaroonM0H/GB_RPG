#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>


Map::Map(const sf::Texture& texture, sf::Vector2f startPos)
{
	int tileHeight = 40;
	int tileWidth = 48;

	int columms = texture.getSize().x / tileHeight;
	int rows = texture.getSize().y / tileWidth;


}



void Map::update() {
	std::cout << "Level was rendered" << std::endl;
}

void Map::draw(sf::RenderWindow& window) const
{

}
