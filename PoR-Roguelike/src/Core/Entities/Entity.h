#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include "Core/GameObject.h"

class Entity : public GameObject {
public:
	Entity(const int health, const std::string textureName);
	virtual ~Entity();

	virtual void Update(const float dt);
	virtual int GetHealth() const { return m_Health; }

protected:

	int m_Health;
};