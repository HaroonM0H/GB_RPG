#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>


Map::Map(const sf::Texture& texture, sf::Vector2f startPos)
{
	int tileHeight = 24;
	int tileWidth = 24;

	int columns = texture.getSize().x / tileHeight;
	int rows = texture.getSize().y / tileWidth;

	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {

			int tileID = textureTiles[row][column];

			int textureColumn = tileID % 2;
			int textureRow = tileID / 2;

			sf::IntRect textureRect(
				{ textureColumn * tileWidth, textureRow * tileHeight },
				{ tileWidth, tileHeight }
			);

			sf::Sprite tile(texture, textureRect);
			tile.setScale({ 2.0f, 2.0f });

			tile.setPosition({
				startPos.x + column * tileWidth * 2,
				startPos.y + row * tileHeight * 2
			});
			
			m_Map.push_back(tile);
		}

	}


}



void Map::update() {
	std::cout << "Level was rendered" << std::endl;
}

void Map::draw(sf::RenderWindow& window) const
{
	for (const sf::Sprite& tile : m_Map) {
		window.draw(tile);
	}
}
