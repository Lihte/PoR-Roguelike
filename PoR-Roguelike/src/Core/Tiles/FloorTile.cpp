#include "FloorTile.h"

FloorTile::FloorTile(const sf::Vector2f pos, const std::string textureName)
	: Tile(pos, TileType::Floor, textureName) {
}

FloorTile::~FloorTile(){
	Tile::~Tile();
}

void FloorTile::Update(const float dt){
	Tile::Update(dt);
}