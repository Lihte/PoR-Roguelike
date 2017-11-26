#include "Tile.h"

Tile::Tile(const sf::Vector2f pos, const TileType tileType, const std::string textureName)
	: GameObject(textureName) {
	m_TileType = tileType;
	m_Position = pos;
	//m_Sprite->setPosition(pos);
}

Tile::~Tile(){
	GameObject::~GameObject();
}

void Tile::Update(const float dt){
	if (m_pSprite)
		m_pSprite->setPosition(m_Position);
}