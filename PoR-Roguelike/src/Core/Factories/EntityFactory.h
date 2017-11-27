#pragma once
#include <SFML/Graphics.hpp>

#include "Core\Game.h"
#include "Core\Assets\TextureHandler.h"

class Player;
class Projectile;

class EntityFactory
{
public:
	EntityFactory(TextureHandler& textureHandler);
	~EntityFactory();

	virtual Player *CreatePlayer(typeAssetID assetID);
	virtual Projectile *CreateProjectile(typeAssetID assetID);
protected:
	virtual Entity *CreateEntity(typeAssetID assetID);

private:
	TextureHandler& m_TextureHandler;
};

