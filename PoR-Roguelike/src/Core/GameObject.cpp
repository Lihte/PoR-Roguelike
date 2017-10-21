#include "GameObject.h"

GameObject::GameObject(const std::string textureName){
	//m_Sprite->setTexture();
	//m_Size.x = m_Sprite->getLocalBounds().width;
	//m_Size.x = m_Sprite->getLocalBounds().height;
}

GameObject::~GameObject(){
	delete m_Sprite;
}

void GameObject::Update(const float dt)
{
	UpdateSpritePosition();
}

void GameObject::UpdateSpritePosition()
{
	m_Sprite->setPosition(m_Position);
}