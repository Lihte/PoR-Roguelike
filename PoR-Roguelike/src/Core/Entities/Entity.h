#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

class Entity {
public:
	Entity(const std::string entityName);
	virtual ~Entity();

	virtual void Update(const float dt);

	virtual sf::Sprite& GetSprite() const { return *m_Sprite; }
	virtual sf::Vector2f GetPosition() const { return m_Position; }
	virtual sf::Vector2f GetSize() const { return m_Size; }
	virtual int GetHealth() const { return m_Health; }
	virtual float GetSpeed() const { return m_Speed;  }
	virtual std::string GetName() const { return m_Name; }

protected:
	virtual void UpdateSpritePosition();


	std::string m_Name;
	sf::Sprite* m_Sprite;
	sf::Vector2f m_Position;
	sf::Vector2f m_Size;
	int m_Health;
	float m_Speed;
};