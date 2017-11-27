#include <SFML\System.hpp>
#include <unordered_map>
#include "Core\Core_types.h"

class IAssetHandler;
class TextureHandler;

#pragma once
class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	void RegisterHandler(IAssetHandler* handler);

	TextureHandler* GetTextureHandler();

protected:
	IAssetHandler* GetHandler(typeAssetHandlerID handlerID);

private:
	std::unordered_map<typeAssetHandlerID, IAssetHandler*> m_handlerMap;

};

