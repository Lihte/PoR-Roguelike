#include "Player.h"

Player::Player() :
	Entity(1, "")
{

}

Player::~Player()
{
}

void Player::Update(const float dt)
{
	Entity::Update(dt);
}