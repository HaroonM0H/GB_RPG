#pragma once
#include <SFML/Graphics.hpp>

enum playerState {
    DOWN = 0, UP = 1, LEFT = 2, RIGHT = 3
};

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