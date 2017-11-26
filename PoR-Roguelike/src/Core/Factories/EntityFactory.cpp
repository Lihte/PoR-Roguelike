#include "EntityFactory.h"



EntityFactory::EntityFactory(Game& game, TextureHandler& textureHandler) :
	m_Game(game),
	m_TextureHandler(textureHandler)
{
	
}


EntityFactory::~EntityFactory()
{
}

Entity* EntityFactory::CreateEntity(typeAssetID assetID)
{
	Entity* entity = new Entity(1, assetID);
	entity->GetSprite()->setTexture(*m_TextureHandler.GetReference(assetID));
}

Player* EntityFactory::CreatePlayer(typeAssetID assetID)
{
	Player* player = (Player*)CreateEntity("player");

	return player;
}
