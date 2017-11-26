#pragma once

#include <unordered_map>
#include "Core/Core_types.h"

class IAssetHandler
{
public:

	IAssetHandler(const typeAssetHandlerID theAssetHandlerID);

	virtual ~IAssetHandler();

	const typeAssetHandlerID GetID(void) const;

	virtual void DropReference(const typeAssetID theAssetID,
		AssetDropTime theDropTime = AssetDropUnspecified) = 0;

	virtual bool IsLoaded(const typeAssetID theAssetID) const = 0;


	virtual const std::string GetFilename(const typeAssetID theAssetID) const = 0;

	virtual void SetFilename(const typeAssetID theAssetID, std::string theFilename) = 0;

	virtual AssetLoadStyle GetLoadStyle(const typeAssetID theAssetID) const = 0;

	virtual void SetLoadStyle(const typeAssetID theAssetID, AssetLoadStyle theLoadStyle) = 0;

	virtual AssetLoadTime GetLoadTime(const typeAssetID theAssetID) const = 0;

	virtual void SetLoadTime(const typeAssetID theAssetID, AssetLoadTime theLoadTime) = 0;

	virtual bool LoadAsset(const typeAssetID theAssetID) = 0;

	virtual bool LoadAllAssets(void) = 0;

protected:

private:
	// Variables
	///////////////////////////////////////////////////////////////////////////
	/// ID specified for this IAssetHandler
	const typeAssetHandlerID m_AssetHandlerID;

	/**
	* Our copy constructor is private because we do not allow copies of our
	* class
	*/
	IAssetHandler(const IAssetHandler&);  // Intentionally undefined

										  /**
										  * Our assignment operator is private because we do not allow copies of our
										  * class
										  */
	IAssetHandler& operator=(const IAssetHandler&); // Intentionally undefined
};