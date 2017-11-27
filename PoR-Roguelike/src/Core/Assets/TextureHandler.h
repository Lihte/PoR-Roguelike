#pragma once

#include <SFML\Graphics.hpp>
#include "Core\Core_types.h"
#include "Core\Interfaces\IAssetHandler.h"

class TextureHandler : public IAssetHandler
{
public:
	TextureHandler(const typeAssetHandlerID theAssetHandlerID = "TextureHandler");
	~TextureHandler();

	virtual sf::Texture* GetReference(const typeAssetID theAssetID, AssetLoadTime loadTime = AssetLoadLater, AssetLoadStyle loadStyle = AssetLoadFromFile, AssetDropTime dropTime = AssetDropAtZero);
	virtual void DropReference(const typeAssetID theAssetID, AssetDropTime theDropTime = AssetDropUnspecified) override;
	virtual bool IsLoaded(const typeAssetID theAssetID) const override;

	virtual const std::string GetFilename(const typeAssetID theAssetID) const override;
	virtual void SetFilename(const typeAssetID theAssetID, std::string theFilename) override;

	virtual AssetLoadStyle GetLoadStyle(const typeAssetID theAssetID) const override;
	virtual void SetLoadStyle(const typeAssetID theAssetID, AssetLoadStyle theLoadStyle) override;
	virtual AssetLoadTime GetLoadTime(const typeAssetID theAssetID) const override;
	virtual void SetLoadTime(const typeAssetID theAssetID, AssetLoadTime theLoadTime) override;

	virtual bool LoadAsset(const typeAssetID theAssetID) override;
	virtual bool LoadAllAssets(void) override;

protected:

	virtual sf::Texture* CreateTexture(const typeAssetID assetID);

	virtual bool LoadFromFile(const typeAssetID theAssetID, sf::Texture& texture);
	virtual bool LoadFromMemory(const typeAssetID theAssetID, sf::Texture& texture);

	

private:

	struct typeTextureData {
		typeAssetID assetID;
		sf::Texture* texture;
		std::string filename;
		bool m_IsLoaded;
		unsigned int count;
	};
	
	std::unordered_map<typeAssetID, typeTextureData> m_TextureMap;

};

