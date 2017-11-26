#include "TextureHandler.h"
#include <iostream>



TextureHandler::TextureHandler(const typeAssetHandlerID theAssetHandlerID) : IAssetHandler(theAssetHandlerID)
{
	
}


TextureHandler::~TextureHandler()
{
}

bool TextureHandler::LoadFromFile(const typeAssetID theAssetID, sf::Texture& texture)
{
	bool result = false;

	std::string filename = GetFilename(theAssetID);

	if (filename.length() > 0)
	{
		result = texture.loadFromFile("assets/" + filename);
	}

	return result;

}

bool TextureHandler::LoadFromMemory(const typeAssetID theAssetID, sf::Texture& texture)
{
	return false;
}

sf::Texture* TextureHandler::GetReference(const typeAssetID theAssetID, AssetLoadTime loadTime, AssetLoadStyle loadStyle, AssetDropTime dropTime)
{
	sf::Texture* result = nullptr;

	std::unordered_map<typeAssetID, typeTextureData>::iterator iter;
	iter = m_TextureMap.find(theAssetID);

	if (iter != m_TextureMap.end())
	{
		iter->second.count++;
		result = iter->second.texture;
	}
	else 
	{
		result = CreateTexture(theAssetID);

		if (result != nullptr)
		{
			typeTextureData data;

			data.texture = result;
			data.count = 1;
			data.m_IsLoaded = false;
			data.filename = theAssetID;

			m_TextureMap.insert(std::pair<const typeAssetID, typeTextureData>(theAssetID, data));

			LoadAsset(theAssetID);
		}
	}

	if (result == nullptr)
	{
		return new sf::Texture();
	}

	return result;
}

void TextureHandler::DropReference(const typeAssetID theAssetID, AssetDropTime theDropTime)
{
}

bool TextureHandler::IsLoaded(const typeAssetID theAssetID) const
{
	return false;
}

const std::string TextureHandler::GetFilename(const typeAssetID theAssetID) const
{
	return theAssetID + ".png";
}

void TextureHandler::SetFilename(const typeAssetID theAssetID, std::string theFilename)
{
}

AssetLoadStyle TextureHandler::GetLoadStyle(const typeAssetID theAssetID) const
{
	return AssetLoadStyle();
}

void TextureHandler::SetLoadStyle(const typeAssetID theAssetID, AssetLoadStyle theLoadStyle)
{
}

AssetLoadTime TextureHandler::GetLoadTime(const typeAssetID theAssetID) const
{
	return AssetLoadTime();
}

void TextureHandler::SetLoadTime(const typeAssetID theAssetID, AssetLoadTime theLoadTime)
{
}

bool TextureHandler::LoadAsset(const typeAssetID theAssetID)
{
	bool anResult = false;

	// Iterator to the asset if found
	std::unordered_map<typeAssetID, typeTextureData>::iterator iter;

	// Try to find the asset using theAssetID as the key
	iter = m_TextureMap.find(theAssetID);

	// Found asset? return the loaded indicator found
	if (iter != m_TextureMap.end())
	{
		if (false == iter->second.m_IsLoaded)
		{
			// Attempt to load the asset now using the correct style
			//switch (iter->second.loadStyle)
			//{
			//case AssetLoadFromFile:
			//	iter->second.m_IsLoaded = LoadFromFile(theAssetID, *(iter->second.texture));
			//	break;
			//case AssetLoadFromMemory:
			//	iter->second.m_IsLoaded = LoadFromMemory(theAssetID, *(iter->second.texture));
			//	break;
			//case AssetLoadFromNetwork:
			//	iter->second.m_IsLoaded = LoadFromNetwork(theAssetID, *(iter->second.texture));
			//	break;
			//case AssetLoadFromUnknown:
			//default:
			//	std::cout << "TAssetHandler(" << GetID() << ")::LoadAsset("
			//		<< theAssetID << ") unknown loading style specified!" << std::endl;
			//	break;
			//}

			iter->second.m_IsLoaded = LoadFromFile(theAssetID, *(iter->second.texture));
		}

		// Set our return result
		anResult = iter->second.m_IsLoaded;
	}
	else
	{
		// Log a warning for trying to determine loaded value of an unknown asset ID
		std::cout << "TAssetHandler(" << GetID() << "):LoadAsset("
			<< theAssetID << ") Asset ID provided not found!"
			<< std::endl;
	}

	// Return anResult which is true if asset was loaded, false otherwise
	return anResult;
}

bool TextureHandler::LoadAllAssets(void)
{
	return false;
}

sf::Texture* TextureHandler::CreateTexture(const typeAssetID assetID)
{
	return new sf::Texture();
}