#include "Entity.h"

Entity::Entity(const int health, const std::string textureName)
	: GameObject(textureName) {
	m_Health = health;
}

Entity::~Entity(){
	delete m_pSprite;
}

void Entity::Update(const float dt){
}