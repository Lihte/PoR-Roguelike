#include <assert.h>
#include <iostream>

#include "AssetManager.h"
#include "Core/Interfaces/IAssetHandler.h"



AssetManager::AssetManager()
{
}


AssetManager::~AssetManager()
{
}

void AssetManager::RegisterHandler(IAssetHandler* handler)
{
	assert(handler != NULL && "AssetManager::RegisterHandler() received a bad pointer");

	m_handlerMap[handler->GetID()] = handler;
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