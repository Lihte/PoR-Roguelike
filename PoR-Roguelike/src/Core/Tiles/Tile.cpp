#include "Tile.h"

Tile::Tile(const std::string textureName)
	: GameObject(textureName) {
	
}

Tile::~Tile(){
	GameObject::~GameObject();
}

void Tile::Update(const float dt){
}