#include "WallTile.h"

WallTile::WallTile(const std::string textureName)
	: Tile(TileType::Wall, textureName) {
}

WallTile::~WallTile(){
	Tile::~Tile();
}

void WallTile::Update(const float dt) {
	Tile::Update(dt);
}