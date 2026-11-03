#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>


Map::Map(const sf::Texture& texture, sf::Vector2f startPos)
	:m_Map(texture, sf::IntRect({ 0, 0 }, { 32, 32 }))
{
	m_Map.setPosition(startPos);
	m_Map.setOrigin({ 16.0f, 16.0f });
	m_Map.setScale({ 2.0f, 2.0f });

	for (int i = 0; i < texture.getSize().x / 32; i++) {
		m_Map.setTextureRect(sf::IntRect({ i * 32, i }, { 32,32 }));

	}
}



void Map::update() {
	m_Map.setTextureRect(sf::IntRect({ 32,32 }, { 40,128 }));
	std::cout << "Map was rendered";
}

void Map::draw(sf::RenderWindow& window) const
{
	window.draw(m_Map);
}
