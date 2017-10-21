#include "FloorTile.h"

FloorTile::FloorTile(const std::string textureName)
	: Tile(TileType::Floor, textureName) {
}

FloorTile::~FloorTile(){
	Tile::~Tile();
}

void FloorTile::Update(const float dt){
	Tile::Update(dt);
}