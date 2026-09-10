#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    unsigned int width = 640;
    unsigned int height = 360;

    sf::RenderWindow window(sf::VideoMode({ width, height }), "GBgame");
    window.setFramerateLimit(60);

    //assign player texture
    sf::Texture texture;
    try
    {
        texture = sf::Texture("Assets/SpriteSheet.png");
    }
    catch (const std::exception& e)
    {
        std::cerr << "Failed to load texture: " << e.what() << '\n';
        return -1;
    }
    Player player(texture, { width / 2.f, height / 2.f });

    sf::Clock clock; // setting up deltaTime

    //sf::CircleShape circle(200.0f);
    //circle.setOrigin(circle.getGeometricCenter());
    //circle.setPosition({ width / 2.0f, height / 2.0f });
    

        while (window.isOpen())
        {
            float deltaTime = clock.restart().asSeconds();
            //UserEvents, like close window,  escape and any other inputs 
            while (const std::optional event = window.pollEvent())
            {
                if (event->is < sf::Event::Closed >()) {
                    window.close();
                }
                else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                    if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                        window.close();
                    }
                }
            }

            player.handleInput();
            player.update(deltaTime);

            //render
            window.clear(sf::Color::Black);

            //Drawing
            player.draw(window);
            window.display();
        }
}
