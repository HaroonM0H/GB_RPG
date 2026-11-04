#pragma once
#include <SFML/Graphics.hpp>

class Map {
public:
	Map(const sf::Texture& texture, sf::Vector2f startPos);
	void update();
	void draw(sf::RenderWindow& window) const;
private:
	std::vector<sf::Sprite> m_Map; //changed to array better for tileset
	
	int textureTiles[3][3] = {
		{0, 2, 3},
		{0, 2, 3},
		{2, 3, 2}
	};
	
};