#include "WallTile.h"

WallTile::WallTile(const sf::Vector2f pos, const std::string textureName)
	: Tile(pos, TileType::Wall, textureName) {
}

WallTile::~WallTile(){
	Tile::~Tile();
}

void WallTile::Update(const float dt) {
	Tile::Update(dt);
}