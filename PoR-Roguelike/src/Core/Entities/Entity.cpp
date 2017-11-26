#include "Entity.h"
#include "Core\Assets\TextureHandler.h"
#include "Core\Game.h"

Entity::Entity(const int health, const std::string textureName){
	m_Health = health;
}

Entity::~Entity(){
	delete m_Sprite;
}

void Entity::Update(const float dt)
{
	//UpdateSpritePosition();
}

void Entity::UpdateSpritePosition()
{
	//m_Sprite->setPosition(m_Position);
}