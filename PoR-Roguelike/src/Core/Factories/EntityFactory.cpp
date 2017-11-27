#include "Core\Entities\Player.h"
#include "Core\Entities\Projectile.h"
#include "EntityFactory.h"



EntityFactory::EntityFactory(TextureHandler& textureHandler) :
	m_TextureHandler(textureHandler)
{
	
}


EntityFactory::~EntityFactory()
{
}

Entity* EntityFactory::CreateEntity(typeAssetID assetID)
{
	Entity* entity = new Entity(assetID);
	entity->GetSprite().setTexture(*m_TextureHandler.GetReference(assetID));

	return entity;
}

Player* EntityFactory::CreatePlayer(typeAssetID assetID)
{
	Player* player = (Player*)CreateEntity(assetID);

	return player;
}

Projectile* EntityFactory::CreateProjectile(typeAssetID assetID)
{
	Projectile* projectile = (Projectile*)CreateEntity(assetID);

	return projectile;
}