#include "IAssetHandler.h"

IAssetHandler::IAssetHandler(const typeAssetHandlerID theAssetHandlerID) 
	: m_AssetHandlerID(theAssetHandlerID)
{
}


IAssetHandler::~IAssetHandler()
{
}

const typeAssetHandlerID IAssetHandler::GetID(void) const {
	return m_AssetHandlerID;
}
