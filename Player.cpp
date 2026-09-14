//#define DEBUG

#include <stack>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

Player::Player(const sf::Texture& texture, sf::Vector2f startPos)
    : m_sprite(texture, sf::IntRect({ 0, 0 }, { 32, 32 }))
    , currentDirection(DOWN)
    , currentState(IDLE)
    
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
        direction.x = 0;
        currentDirection = UP;
        currentState = WALKING;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
        direction.y += 1.f;
        direction.x = 0;
        currentDirection = DOWN;
        currentState = WALKING;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
        direction.x -= 1.f;
        direction.y = 0;
        currentDirection = LEFT;
        currentState = WALKING;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))  {
        direction.x += 1.f;
        direction.y = 0;
        currentDirection = RIGHT;
        currentState = WALKING;
        
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

    // State determines which section of the spritesheet
    int row = currentFrame;

    if (currentState == WALKING)
    {
        row += 4;
    }

    if (timer >= timerMax) {
        timer -= timerMax;
        currentFrame = (currentFrame + 1) % 4;

        #ifdef DEBUG
        std::cout << currentFrame;
        #endif // DEBUG
    }
    
    m_sprite.setTextureRect(sf::IntRect({ column * 32,row * 32 }, { 32,32 }));
}

void Player::draw(sf::RenderWindow& window) const
{
    window.draw(m_sprite);
}