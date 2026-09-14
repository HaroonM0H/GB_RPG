//#define DEBUG
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"

int main()
{
    unsigned int width = 640;
    unsigned int height = 360;

    sf::RenderWindow window(sf::VideoMode({ width, height }), "GBgame");
    window.setFramerateLimit(60);

    //assign player texture
    sf::Texture playerTexture;
    try
    {
        playerTexture = sf::Texture("Assets/SpriteSheet.png");
    }
    catch (const std::exception& e)
    {
        std::cerr << "Failed to load texture: " << e.what() << '\n';
        return -1;
    }
    Player player(playerTexture, { width / 2.f, height / 2.f });

    //assign map texture
    sf::Texture mapTexture;

    try
    {
        mapTexture = sf::Texture("Assets/TilesetField.png");
    }
    catch (const std::exception& e)
    {
        std::cerr << "Failed to load texture: " << e.what() << '\n';
        return -1;
    }
    Map Map(mapTexture, { width / 2.f, height / 2.f });



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
            Map.update();
            player.handleInput();
            player.update(deltaTime);


            //render
            window.clear(sf::Color::Black);

            //Drawing
            player.draw(window);
            window.display();
        }
}
