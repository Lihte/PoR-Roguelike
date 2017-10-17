#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

class Entity{
public:
	Entity();
	virtual ~Entity();

	virtual void Update() = 0;

	sf::Sprite* GetSprite() { return &m_Sprite; }
	sf::Vector2f* GetPosition() { return &m_Position; }

protected:
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;
};