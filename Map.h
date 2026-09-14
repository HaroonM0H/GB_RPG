#pragma once
#include <SFML/Graphics.hpp>

class Map {
public:
	Map(const sf::Texture& texture, sf::Vector2f startPos);
	void update();
	void draw(sf::RenderWindow& window) const;
private:
	sf::Sprite m_Map;
};