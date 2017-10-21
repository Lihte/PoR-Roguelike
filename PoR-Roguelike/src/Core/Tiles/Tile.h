#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include "Core/GameObject.h"

class Tile : public GameObject {
public:
	enum TileType {
		Floor,
		Wall,
	};

	Tile(const sf::Vector2f pos, const TileType tileType, std::string textureName);
	virtual ~Tile();

	virtual void Update(const float dt);
	virtual TileType GetTileType() const { return m_TileType; }
protected:
	TileType m_TileType;
};