#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player(const sf::Texture& texture, sf::Vector2f startPos);
    void handleInput();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;

private:
    sf::Sprite   m_sprite;
    sf::Vector2f m_velocity{ 0.f, 0.f };
    float        m_speed = 150.f;
};