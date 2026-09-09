#include <SFML/Graphics.hpp>

class Player {
public:
	Player(const sf::Texture& texture, sf::Vector2f startPos)
		: m_sprite(texture, sf::IntRect({ 0,0 }, { 16, 16 }))
	{
		m_sprite.setPosition(startPos);
	}

	void handleInput() {
		sf::Vector2f direction{ 0.f, 0.f };

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) direction.y -= 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) direction.y += 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) direction.x -= 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) direction.x += 1.f;
	
		m_velocity = direction;
	}

	

	void draw(sf::RenderWindow& window) const {
		window.draw(m_sprite);
	}

private:
	sf::Sprite m_sprite;
	sf::Vector2f m_velocity{ 0.f, 0.f };
	float m_speed = 150.f;
};