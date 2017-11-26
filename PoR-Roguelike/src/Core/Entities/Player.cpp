#include "Player.h"

Player::Player() :
	Entity(1, "")
{
	m_pSprite = new sf::Sprite();
}

Player::~Player()
{
}

void Player::Update(const float dt)
{
	Entity::Update(dt);
}