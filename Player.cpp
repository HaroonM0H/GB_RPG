#include <SFML/Graphics.hpp>
#include "Player.h"

Player::Player(const sf::Texture& texture, sf::Vector2f startPos)
    : m_sprite(texture, sf::IntRect({ 0, 0 }, { 16, 16 }))
{
    m_sprite.setPosition(startPos);
    m_sprite.setOrigin({ 8.0f, 8.0f });
    m_sprite.setScale({ 3.0f, 3.0f });
}

void Player::handleInput()
{
    sf::Vector2f direction{ 0.f, 0.f };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
        direction.y -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) 
        direction.y += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
        direction.x -= 1.f;
        m_sprite.setTextureRect(sf::IntRect({ 32,0 }, { 16,16 }));
    }
        

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
        direction.x += 1.f;




    m_velocity = direction;
}

void Player::update(float deltaTime)
{
    m_sprite.move(m_velocity * m_speed * deltaTime);

}

void Player::draw(sf::RenderWindow& window) const
{
    window.draw(m_sprite);
}