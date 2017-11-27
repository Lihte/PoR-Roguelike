#include <assert.h>
#include <iostream>

#include "Core/Interfaces/IAssetHandler.h"
#include "Core/Assets/TextureHandler.h"
#include "AssetManager.h"




AssetManager::AssetManager()
{
}


AssetManager::~AssetManager()
{
}

void AssetManager::RegisterHandler(IAssetHandler* handler)
{
	assert(handler != nullptr && "AssetManager::RegisterHandler() received a bad pointer");

	m_handlerMap[handler->GetID()];
}

TextureHandler* AssetManager::GetTextureHandler()
{
	auto handler = GetHandler("TextureHandler");

	return static_cast<TextureHandler*>(handler);
}

IAssetHandler* AssetManager::GetHandler(const typeAssetHandlerID handlerID)
{
	std::unordered_map<typeAssetHandlerID, IAssetHandler*>::iterator iter;

	iter = m_handlerMap.find(handlerID);

	if (iter != m_handlerMap.end())
	{
		return iter->second;
	}
	else
	{
		std::cout << "ERROR: Handler " << handlerID << " not found!" << std::endl;
		return nullptr;
	}
}