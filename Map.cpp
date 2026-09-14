#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>


Map::Map(const sf::Texture& texture, sf::Vector2f startPos)
	:m_Map(texture, sf::IntRect({ 0, 0 }, { 32, 32 }))
{
	m_Map.setPosition(startPos);
	m_Map.setOrigin({ 16.0f, 16.0f });
	m_Map.setScale({ 4.0f, 4.0f });
}

void Map::update() {
	m_Map.setTextureRect(sf::IntRect({ 32,32 }, { 40,128 }));
	std::cout << "Map was rendered";
}