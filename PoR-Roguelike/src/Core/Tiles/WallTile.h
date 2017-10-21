#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include "Core/Tiles/Tile.h"

class WallTile : Tile {
public:

	WallTile(std::string textureName);
	virtual ~WallTile();

	virtual void Update(const float dt);
protected:
};