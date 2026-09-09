#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    unsigned int width = 640;
    unsigned int height = 360;

    sf::RenderWindow window(sf::VideoMode({ width, height }), "SFML works!");
    window.setFramerateLimit(60);

    sf::Texture texture("Assets/SpriteSheet.png");
    sf::Sprite sprite(texture, sf::IntRect({ 0,0 }, {16, 16}));
    //sprite.setColor(sf::Color(255, 255, 255, 128)); // half transparent
    sprite.setOrigin({ 8.0f, 8.0f });
    sprite.setPosition({ 320.f, 180.f });
    sprite.setScale({3.0f,  3.0f});

    //sf::CircleShape circle(200.0f);
    //circle.setOrigin(circle.getGeometricCenter());
    //circle.setPosition({ width / 2.0f, height / 2.0f });
    

        while (window.isOpen())
        {
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

            //render
            window.clear(sf::Color::Black);

            //Drawing
            //window.draw(circle);
            window.draw(sprite);
            window.display();
        }
}
