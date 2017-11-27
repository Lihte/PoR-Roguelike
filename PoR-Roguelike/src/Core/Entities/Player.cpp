#include "Player.h"
#include "Core\Assets\TextureHandler.h"
#include "PlayerMeleeAttack.h"


Player::Player() :
	Entity("player")
{
}                                                                                                                                                                                                                                                                          

Player::~Player()
{
}

void Player::Update(const float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		GetSprite().move(0.f, -GetSpeed() * dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		GetSprite().move(0.f, GetSpeed() * dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		GetSprite().move(-GetSpeed() * dt, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		GetSprite().move(GetSpeed() * dt, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

	}

	Entity::Update(dt);
}