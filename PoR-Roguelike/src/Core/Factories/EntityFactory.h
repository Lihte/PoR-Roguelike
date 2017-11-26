#pragma once
#include <SFML/Graphics.hpp>
#include "Core\Entities\Player.h"
#include "Core\Game.h"
#include "Core\Assets\TextureHandler.h"

class EntityFactory
{
public:
	EntityFactory(Game& game, TextureHandler& textureHandler);
	~EntityFactory();

	virtual Player *CreatePlayer(typeAssetID assetID);

protected:
	virtual Entity *CreateEntity(typeAssetID assetID);

private:
	Game& m_Game;
	TextureHandler& m_TextureHandler;
};

