#pragma once
class Entity;

class Projectile : public Entity
{
public:
	Projectile();
	~Projectile();

	virtual void Update(const float dt) override;
};

