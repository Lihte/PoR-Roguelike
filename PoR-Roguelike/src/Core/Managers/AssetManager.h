#include <SFML\System.hpp>
#include <unordered_map>
#include "Core\Core_types.h"

class IAssetHandler;

#pragma once
class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	void RegisterHandler(IAssetHandler* handler);
	IAssetHandler* GetHandler(typeAssetID assetID);


private:
	std::unordered_map<typeAssetHandlerID, IAssetHandler*> m_handlerMap;

};

