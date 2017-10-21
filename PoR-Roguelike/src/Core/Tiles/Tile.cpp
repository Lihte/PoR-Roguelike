#include "Tile.h"

Tile::Tile(const TileType tileType, const std::string textureName)
	: GameObject(textureName) {
	m_TileType = tileType;
}

Tile::~Tile(){
	GameObject::~GameObject();
}

void Tile::Update(const float dt){
}