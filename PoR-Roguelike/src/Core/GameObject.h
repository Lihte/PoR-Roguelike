#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

class GameObject {
public:
	GameObject(const std::string textureName);
	virtual ~GameObject();

	virtual void Update(const float dt);

	virtual sf::Sprite* GetSprite() const { return m_Sprite; }
	virtual sf::Vector2f GetPosition() const { return m_Position; }
	virtual sf::Vector2f Getsize() const { return m_Size; }

protected:
	virtual void UpdateSpritePosition();

	sf::Sprite* m_Sprite;
	sf::Vector2f m_Position;
	sf::Vector2f m_Size;
};