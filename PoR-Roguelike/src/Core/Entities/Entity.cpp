#include "Entity.h"
#include "Core\Assets\TextureHandler.h"
#include "Core\Game.h"

Entity::Entity(const std::string entityName) : 
	m_Sprite(),
	m_Speed(100),
	m_Name(entityName)
{
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