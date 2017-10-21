#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include "Core/Tiles/Tile.h"

class FloorTile : public Tile {
public:
	FloorTile(const sf::Vector2f pos, std::string textureName);
	virtual ~FloorTile();

	virtual void Update(const float dt);
protected:
};