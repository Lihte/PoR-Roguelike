#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity {
public:
	Player();
	virtual ~Player();

	virtual void Update(const float dt) override;

protected:

};