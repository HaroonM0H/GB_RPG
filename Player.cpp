#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

Player::Player(const sf::Texture& texture, sf::Vector2f startPos)
    : m_sprite(texture, sf::IntRect({ 0, 0 }, { 32, 32 }))
    ,currentDirection(DOWN)
    ,currentState(IDLE)
{
    m_sprite.setPosition(startPos);
    m_sprite.setOrigin({ 16.0f, 16.0f });
    m_sprite.setScale({ 3.0f, 3.0f });
}

void Player::handleInput()
{
    sf::Vector2f direction{ 0.f, 0.f };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))  {
        direction.y -= 1.f;
        currentDirection = UP;
        currentState = WALKING;
        //m_sprite.setTextureRect(sf::IntRect({ 32,0 }, { 32, 32 }));
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
        direction.y += 1.f;
        currentDirection = DOWN;
        currentState = WALKING;

    }
        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
        direction.x -= 1.f;
        currentDirection = LEFT;
        currentState = WALKING;
        //m_sprite.setTextureRect(sf::IntRect({ 64,0 }, { 32, 32 }));
    }
        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))  {
        direction.x += 1.f;       
        currentDirection = RIGHT;
        currentState = WALKING;
        //m_sprite.setTextureRect(sf::IntRect({ 96,0 }, { 32, 32 }));
        
    }
    if (direction.x == 0.f && direction.y == 0.f) {
        currentState = IDLE;
    }

    m_velocity = direction;
}

void Player::update(float deltaTime)
{
    m_sprite.move(m_velocity * m_speed * deltaTime);


    timer += deltaTime;

    int column = (int)currentDirection;
    currentFrame = (currentFrame + 1) % 4;

    if (timer >= timerMax) {
        m_sprite.setTextureRect(sf::IntRect({ column * 32,currentFrame * 32 }, { 32,32 }));
        timer = 0;
    }
    

    //switch (currentDirection) {
    //case LEFT:
    //    texHeight = 128;
    //    for (currentFrame = 0; currentFrame <= 4; currentFrame++) {
    //        if (texHeight >= 256)
    //        if (timer >= timerMax) {
    //            m_sprite.setTextureRect(sf::IntRect({ 0,texHeight * currentFrame }, { 32,32 }));
    //        }
    //    }
    //    break;
    //case RIGHT:
    //    break;
    //case UP:
    //    break;
    //case DOWN:
    //    break;
    //default:
    //    break;
    //}

}

void Player::draw(sf::RenderWindow& window) const
{
    window.draw(m_sprite);
}